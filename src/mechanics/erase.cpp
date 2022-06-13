/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function erase() to erase entities on the map
 */
#include <ncurses.h>
#include <entity.hpp>
#include <map.hpp>
void erase (Entity ent, Map map) {
    // Add an empty space on the coordinates of the entity on the map,
    // effectively erasing it.
    mvaddch(ent.get_y() + (LINES/2)  - map.get_lines() / 2,
            ent.get_x() + (COLS/2) - map.get_columns() / 2,
            ' ');
}
