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
    int offset_y = -4;
    print("Babis Potteridis", offset_x, offset_y);
    offset_x = -3;
    offset_y++;
    print("and the", offset_x ,offset_y);
    offset_x = -11;
    offset_y++;
    print("Search of the Magic Gem", offset_x, offset_y);
    offset_x = -3;
    offset_y += 2;
    print("*******", offset_x, offset_y);
    offset_x--;
    offset_y++;
    print("*********", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("*******", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("*****", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("***", offset_x, offset_y);
    offset_x++;
    offset_y++;
    print("*", offset_x, offset_y);
}
