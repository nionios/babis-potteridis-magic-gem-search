#include <ncurses.h>
void setup_ncurses(void) {
    initscr();
    clear();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
}
