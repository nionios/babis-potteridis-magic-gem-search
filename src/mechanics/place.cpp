/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function place() to draw entities on the map
 */
#include <ncurses.h>
#include <map.hpp>
#include <gem.hpp>
#include <potter.hpp>
#include <malfoy.hpp>
#include <exceptions.hpp>

void place (Entity ent, Map map) {
    // Color the entity according to its identifier
    switch (ent.get_id()) {
        case '$':
            attron(COLOR_PAIR(6));
            break;
        case 'L':
            attron(COLOR_PAIR(7));
            break;
        case 'M':
            attron(COLOR_PAIR(8));
            break;
        default:
            throw invalid_entity_data(ent.get_id());
            break;
    }
    // Place malfoy but move him according to the map centering coords too
    mvaddch(ent.get_y() + (LINES/2)  - map.get_lines() / 2,
            ent.get_x() + (COLS/2) - map.get_columns() / 2,
            ent.get_id());
    attron(COLOR_PAIR(1));
}
