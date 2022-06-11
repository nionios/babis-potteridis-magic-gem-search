#include <ncurses.h>
#include <unistd.h>
#include <string>
// Intro sequence for starting the game
void print(std::string str, int offset_x, int offset_y) {
    for (auto character : str) {
        mvaddch((LINES/2) + offset_y, (COLS/2) + offset_x, character);
        usleep(50000);
        refresh();
        offset_x++;
    }
}

void intro (void) {
    int offset_x = -7;
    int offset_y = -8;
    attron(COLOR_PAIR(5));
    print("Babis Potteridis", offset_x, offset_y);
    attron(COLOR_PAIR(1));
    offset_x = -3;
    offset_y++;
    print("and the", offset_x ,offset_y);
    offset_x = -11;
    offset_y++;
    print("Search of the", offset_x, offset_y);
    attron(COLOR_PAIR(5));
    offset_x = 2;
    print(" Magic Gem", offset_x, offset_y);
    attron(COLOR_PAIR(1));
    offset_x = -4;
    offset_y += 2;
    attron(COLOR_PAIR(4));
    print("_________", offset_x, offset_y);
    offset_x--;
    offset_y++;
    print("/////|\\\\\\\\\\", offset_x, offset_y);
    offset_y++;
    print("\\\\\\\\\\|/////", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("\\\\\\\\|////", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("\\\\\\|///", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("\\\\|//", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("\\|/", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("v", offset_x, offset_y);
    offset_x = -14;
    offset_y += 2;
    // Back to default color pair
    attron(COLOR_PAIR(1));
    mvaddstr((LINES/2) + offset_y,
             (COLS/2)  + offset_x,
             "Press any key to continue...");
    refresh();
    getch();
}
