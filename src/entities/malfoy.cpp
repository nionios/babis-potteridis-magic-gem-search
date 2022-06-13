/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function to move Malfoy around on the map. He follows potter
 *              calculating where to go based on where the straight line to
 *              potters coordinates is closer. This is info is stored into
 *              "candidate" pairs, first value is distance from potter, second
 *              is direction that needs to be followed to get this distance
 *              from potter.
 */
#include <cmath>
#include <ncurses.h>
#include <map.hpp>
#include <potter.hpp>
#include <erase.hpp>
#include <place.hpp>
void Malfoy::move(Map map, Potter potter) {
    // Straight line is y2 – y1*x2  – x1  when malfoy(x1,x2) and potter(x2,y2)
    // Malfoy's coordinates
    int x = this->get_x();
    int y = this->get_y();
    // Potter's coordinates
    int target_x = potter.get_x();
    int target_y = potter.get_y();
    // Check which possible movements around malfoy are available and set
    // straight-line-to-potter values
    int up_value;
    int down_value;
    int left_value;
    int right_value;
    std::vector<std::pair<int,char>> candidate_list;
    // These checks cannot access out-of-bound memory since edge of the maps
    // is enclosed by a 1-block wall at least
    if (map.get_area()[y-1][x] == 0)  {
        // Calculate value
        up_value = std::abs(target_y - (y-1)*target_x - x);
        // Correlate value with its direction
        std::pair<int,char> candidate = {up_value, 'u'};
        // Push the candidate on the candidate list
        candidate_list.push_back(candidate);
    }
    // Follow same method with the other directions if they are available
    if (map.get_area()[y+1][x] == 0) {
        down_value = std::abs(target_y - (y+1)*target_x - x);
        std::pair<int,char> candidate = {down_value, 'd'};
        candidate_list.push_back(candidate);
    }

    if (map.get_area()[y][x-1] == 0) {
        left_value = std::abs(target_y - y*target_x - x - 1);
        std::pair<int,char> candidate = {left_value, 'l'};
        candidate_list.push_back(candidate);
    }

    if (map.get_area()[y][x+1] == 0) {
        right_value = std::abs(target_y - y*target_x - x + 1);
        std::pair<int,char> candidate = {right_value, 'r'};
        candidate_list.push_back(candidate);
    }
    // Time to decide which candidate is better
    std::pair <int,char> best_candidate;
    // First iteration flag
    bool first = true;
    for (auto & current_candidate : candidate_list) {
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
    // Now time to learn which canditate has won and the move to make base on
    // this.
    // Change position of malfoy to the updated one
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
