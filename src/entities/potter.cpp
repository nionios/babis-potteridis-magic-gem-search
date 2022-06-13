/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function to move Mpampis around on the map with user input.
 *              This evaluates the validity of the movement and ignores if it
 *              is wrong (for ex. the player tries to move through a wall)
 */
#include <ncurses.h>
#include <map.hpp>
#include <potter.hpp>
#include <erase.hpp>
#include <place.hpp>
#include <exceptions.hpp>

// If the map position that the player wants to move too is empty (map area
// is 0) return true, else false (for ex a wall exists there)
bool evaluate_movement(Map map, int next_x, int next_y) {
    if (map.get_area()[next_y][next_x] == 0) return true;
    else return false;
}

void Potter::move(Map map) {
    while (1) {
        // next_x next_y are the candidates for the next position of player
        int next_x;
        int next_y;
        // True if input is recognised as valid direction (wasd and arrow keys)
        bool valid_dir_given = false;
        switch (getch()) {
            case KEY_UP:
            case 'w':
            case 'k':
                valid_dir_given = true;
                next_x = this->get_x();
                next_y = this->get_y()-1;
                break;
            case KEY_DOWN:
            case 's':
            case 'j':
                valid_dir_given = true;
                next_x = this->get_x();
                next_y = this->get_y()+1;
                break;
            case KEY_RIGHT:
            case 'd':
            case 'l':
                valid_dir_given = true;
                next_x = this->get_x()+1;
                next_y = this->get_y();
                break;
            case KEY_LEFT:
            case 'a':
            case 'h':
                valid_dir_given = true;
                next_x = this->get_x()-1;
                next_y = this->get_y();
                break;
            case ' ':
                valid_dir_given = true;
                next_x = this->get_x();
                next_y = this->get_y();
                break;
            case 'q':
                throw exit_signal();
                break;
            default:
                mvaddstr(LINES-1,(COLS/2)-40,
                        "Tip: Use wasd or hjkl or arrow keys to move. Space to remain still and q to exit");
                refresh();
                break;
        }
        if (valid_dir_given && evaluate_movement(map, next_x, next_y)) {
            // Erase potter from the map
            erase(*this, map);
            // Change position of potter to the updated one
            this->teleport(next_x, next_y);
            // Redraw potter on the map
            place(*this, map);
            break;
        }
    }
}
