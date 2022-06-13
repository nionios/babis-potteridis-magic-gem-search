/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Intro sequence for starting the game
 */
#include <ncurses.h>
#include <intro.hpp>
#include <slow_print.hpp>

void intro (void) {
    int offset_x = -7;
    int offset_y = -8;
    attron(COLOR_PAIR(5));
    slow_print("Babis Potteridis", offset_x, offset_y);
    attron(COLOR_PAIR(1));
    offset_x = -3;
    offset_y++;
    slow_print("and the", offset_x ,offset_y);
    offset_x = -11;
    offset_y++;
    slow_print("Search of the", offset_x, offset_y);
    attron(COLOR_PAIR(5));
    offset_x = 2;
    slow_print(" Magic Gem", offset_x, offset_y);
    attron(COLOR_PAIR(1));
    offset_x = -4;
    offset_y += 2;
    attron(COLOR_PAIR(4));
    slow_print("_________", offset_x, offset_y);
    offset_x--;
    offset_y++;
    slow_print("/////|\\\\\\\\\\", offset_x, offset_y);
    offset_y++;
    slow_print("\\\\\\\\\\|/////", offset_x, offset_y);
    offset_x++;
    offset_y++;
    slow_print("\\\\\\\\|////", offset_x, offset_y);
    offset_x++;
    offset_y++;
    slow_print("\\\\\\|///", offset_x, offset_y);
    offset_x++;
    offset_y++;
    slow_print("\\\\|//", offset_x, offset_y);
    offset_x++;
    offset_y++;
    slow_print("\\|/", offset_x, offset_y);
    offset_x++;
    offset_y++;
    slow_print("v", offset_x, offset_y);
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
