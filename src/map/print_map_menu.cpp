#include <ncurses.h>
#include <map.hpp>
void print_map_menu(std::vector<Map> map_list) {
    for (int i=0; i<map_list.size(); i++) {
        mvaddstr((LINES/2) - map_list.size()/2 + i,
                (COLS/2)  - map_list[i].get_name().length()/2,
                map_list[i].get_name().c_str());
        // i + '0' to convert int to char
        mvaddch((LINES/2) - map_list.size()/2 + i,
                (COLS/2) - map_list[i].get_name().length()/2 - 2,
                i+'0');
    }
    mvaddstr((LINES/2) - map_list.size()/2 - 2,
            (COLS/2)  - 4,
            "MAP MENU");
    mvaddstr((LINES/2) - map_list.size()/2 - 1,
            (COLS/2)  - 3,
            "------");
    mvaddstr((LINES/2) + map_list.size()/2 + 1,
            (COLS/2)  - 4,
            "---------");
    mvaddstr((LINES/2) + map_list.size()/2 + 2,
            (COLS/2)  - 5,
            "Choose Map:");
    refresh();
}
