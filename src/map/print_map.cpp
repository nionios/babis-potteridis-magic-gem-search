/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function to print the map but also center it (print in the 
 *              middle of the terminal.
 */
#include <vector>
#include <ncurses.h>
#include <map.hpp>
#include <exceptions.hpp>

void print_map (Map input_map) {
    std::vector<std::vector<bool>> input_area = input_map.get_area();
    int map_lines = input_map.get_lines();
    int map_cols  = input_map.get_columns();
    mvaddstr(2,
             (COLS/2)  - input_map.get_name().size()/2,
             input_map.get_name().c_str());
    for (int i=0; i<map_lines; i++) {
        for (int j=0; j<map_cols; j++) {
            if (input_area[i][j]) attron(COLOR_PAIR(2));
            else attron(COLOR_PAIR(3));
            // Draw the map centered in the terminal screen
            mvaddch((LINES/2)-(map_lines/2)+i, (COLS/2)-(map_cols/2)+j, ' ');
        }
    }
    // Back to default color pair
    attron(COLOR_PAIR(1));
    refresh();
}
