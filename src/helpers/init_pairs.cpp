#include <ncurses.h>
void init_pairs(void) {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_CYAN,  COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_BLACK,  COLOR_CYAN);
    init_pair(7, COLOR_BLACK,   COLOR_RED);
    init_pair(8, COLOR_BLACK, COLOR_GREEN);
    init_pair(9, COLOR_YELLOW,COLOR_BLACK);
    init_pair(10,COLOR_RED,   COLOR_BLACK);
}
