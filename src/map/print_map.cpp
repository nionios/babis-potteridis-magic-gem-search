#include <vector>
#include <ncurses.h>
#include <map.hpp>
#include <exceptions.hpp>

void print_map (Map input_map) {
    std::vector<std::vector<bool>> input_area = input_map.get_area();
    for (int i=0; i<input_map.get_lines(); i++) {
        for (int j=0; j<input_map.get_columns(); j++) {
            if (input_area[i][j]) attron(COLOR_PAIR(3));
            else attron(COLOR_PAIR(2));
           //TODO: handle properly //else throw invalid_map_data();
            mvaddch((LINES/1.2)+i,(COLS/1.2)+j, ' ');
            refresh();
        }
    }
    // Back to default color pair
    attron(COLOR_PAIR(1));
}
