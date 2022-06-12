#include <ncurses.h>
void init_pairs(void) {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_CYAN,  COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
}
