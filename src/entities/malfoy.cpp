/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function to move Malfoy around on the map. He follows potter
 *              calculating where to go based on where the straight line to
 *              potter or gem coordinates is closer.
 *              Malfoy chases Potter and the gem.
 */
#include <cmath>
#include <ncurses.h>
#include <gem.hpp>
#include <map.hpp>
#include <potter.hpp>
#include <erase.hpp>
#include <place.hpp>

std::vector<std::pair<double,char>> Malfoy::create_candidates
(Map map, Entity target) {
    // Straight line is y2 – y1*x2  – x1  when malfoy(x1,x2) and target(x2,y2)
    // Malfoy's coordinates
    int x = this->get_x();
    int y = this->get_y();
    // Potter's coordinates
    int target_x = target.get_x();
    int target_y = target.get_y();
    // Check which possible movements around malfoy are available and set
    // straight-line-to-target values (in double for more accuracy)
    double up_value;
    double down_value;
    double left_value;
    double right_value;
    std::vector<std::pair<double,char>> candidate_list;
    // These checks cannot access out-of-bound memory since edge of the maps
    // is enclosed by a 1-block wall at least
    if (map.get_area()[y-1][x] == 0)  {
        // Calculate value
        up_value = std::abs(std::sqrt(std::pow(x - target_x, 2) +
                                      std::pow(y - target_y + 1, 2)));
        // Correlate value with its direction
        std::pair<double,char> candidate = {up_value, 'u'};
        // Push the candidate on the candidate list
        candidate_list.push_back(candidate);
    }
    // Follow same method with the other directions if they are available
    if (map.get_area()[y+1][x] == 0) {
        down_value = std::abs(std::sqrt(std::pow(x - target_x, 2) +
                                        std::pow(y - target_y - 1, 2)));
        std::pair<double,char> candidate = {down_value, 'd'};
        candidate_list.push_back(candidate);
    }

    if (map.get_area()[y][x-1] == 0) {
        left_value = std::abs(std::sqrt(std::pow(x - target_x + 1, 2) +
                                        std::pow(y - target_y, 2)));
        std::pair<double,char> candidate = {left_value, 'l'};
        candidate_list.push_back(candidate);
    }

    if (map.get_area()[y][x+1] == 0) {
        right_value = std::abs(std::sqrt(std::pow(x - target_x - 1, 2) +
                                         std::pow(y - target_y, 2)));
        std::pair<double,char> candidate = {right_value, 'r'};
        candidate_list.push_back(candidate);
    }

    return candidate_list;
}

void Malfoy::move(Map map, Potter potter, Gem gem) {
    std::vector<std::pair<double,char>> candidate_list_to_gem =
        create_candidates(map, gem);
    std::vector<std::pair<double,char>> candidate_list_to_potter =
        create_candidates(map, potter);
    std::vector<std::pair<double,char>> total_candidate_list;
    // Allocate memory for the joined vector (candidate list)
    total_candidate_list.reserve(candidate_list_to_gem.size() +
                                 candidate_list_to_potter.size() );
    // Insert the contents of the two candidate list into this one, thus join
    total_candidate_list.insert(total_candidate_list.end(),
                                candidate_list_to_gem.begin(),
                                candidate_list_to_gem.end() );
    total_candidate_list.insert(total_candidate_list.end(),
                                candidate_list_to_potter.begin(),
                                candidate_list_to_potter.end() );
    // Time to decide which candidate is better
    std::pair <double,char> best_candidate;
    // First iteration flag
    bool first = true;
    for (auto & current_candidate : total_candidate_list) {
        if (first) {
            // Make flag false after first iteration
            first = false;
            // Set best_candidate to the first candidate on list
            best_candidate = current_candidate;
        } else {
            // Check if the distance of the candidate from potter is smaller
            // than the distances seen until now. If yes, set as new min
            if (best_candidate.first < current_candidate.first)  {
                // Replace best_candidate on finding better candidate
                best_candidate = current_candidate;
            }
        }
    }
    // Erase malfoy from the map
    erase(*this, map);
    // Now time to learn which canditate has won and the move to make based on
    // this.
    // Change position of malfoy to the updated one
    int x = this->get_x();
    int y = this->get_y();
    switch (best_candidate.second) {
        case 'u':
            this->teleport(x,y-1);
            break;
        case 'd':
            this->teleport(x,y+1);
            break;
        case 'l':
            this->teleport(x-1,y);
            break;
        case 'r':
            this->teleport(x+1,y);
            break;
    }
    // Redraw malfoy on the map
    place(*this, map);
}
