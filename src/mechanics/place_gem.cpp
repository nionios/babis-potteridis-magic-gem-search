#include <ncurses.h>
#include <map.hpp>
#include <gem.hpp>
void place_gem (Gem gem, Map map) {
    mvaddch(gem.get_x() + (COLS/2) - map.get_columns() / 2,
            gem.get_y() + (LINES/2)  - map.get_lines() / 2,
            '*');
}
