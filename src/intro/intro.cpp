#include <ncurses.h>
#include <unistd.h>
#include <string>
// Intro sequence for starting the game
void intro (void) {
    int i = -7;
    std::string str = "Babis Potteridis";
    for (auto character : str) {
        mvaddch((LINES/2) - 4, (COLS/2) + i, character);
        usleep(50000);
        refresh();
        i++;
    }
    i = -3;
    str = "and the";
    for (auto character : str) {
        mvaddch((LINES/2) - 3, (COLS/2) + i, character);
        usleep(50000);
        refresh();
        i++;
    }
    i = -11;
    str = "Search of the Magic Gem";
    for (auto character : str) {
        mvaddch((LINES/2) - 2, (COLS/2) + i, character);
        usleep(50000);
        refresh();
        i++;
    }
    i = -3;
    str = "*******";
    for (auto character : str ) {
        mvaddch((LINES/2), (COLS/2) + i, character);
        usleep(25000);
        refresh();
        i++;
    }
    i = -4;
    str = "*********";
    for (auto character : str) {
        mvaddch((LINES/2) + 1, (COLS/2) + i, character);
        usleep(25000);
        refresh();
        i++;
    }
    i = -3;
    str = "*******";
    for (auto character : str) {
        mvaddch((LINES/2) + 2, (COLS/2) + i, character);
        usleep(25000);
        refresh();
        i++;
    }
    i = -2;
    str = "*****";
    for (auto character : str) {
        mvaddch((LINES/2) + 3, (COLS/2) + i, character);
        usleep(25000);
        refresh();
        i++;
    }
    i = -1;
    str = "***";
    for (auto character : str) {
        mvaddch((LINES/2) + 4, (COLS/2) + i, character);
        usleep(25000);
        refresh();
        i++;
    }
    i = 0;
    mvaddch((LINES/2) + 5, (COLS/2) + i, '*');
    usleep(25000);
    refresh();
    i++;
}
