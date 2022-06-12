#include <vector>
#include <ncurses.h>
#include <map.hpp>
#include <exceptions.hpp>

void print_map (Map input_map) {
    std::vector<std::vector<bool>> input_area = input_map.get_area();
    int map_lines = input_map.get_lines();
    int map_cols  = input_map.get_columns();
    for (int i=0; i<map_lines; i++) {
        for (int j=0; j<map_cols; j++) {
            if (input_area[i][j]) attron(COLOR_PAIR(2));
            else attron(COLOR_PAIR(3));
           //TODO: handle properly //else throw invalid_map_data();
            mvaddch((LINES/2)-(map_lines/2)+i, (COLS/2)-(map_cols/2)+j, ' ');
        }
    }
    // Back to default color pair
    attron(COLOR_PAIR(1));
    refresh();
}
