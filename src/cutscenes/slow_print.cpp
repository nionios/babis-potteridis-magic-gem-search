#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <slow_print.hpp>
void slow_print(std::string str, int offset_x, int offset_y) {
    for (auto character : str) {
        mvaddch((LINES/2) + offset_y, (COLS/2) + offset_x, character);
        usleep(50000);
        refresh();
        offset_x++;
    }
}
