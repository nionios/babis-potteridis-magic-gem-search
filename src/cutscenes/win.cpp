/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Winning sequence
 */
#include <ncurses.h>
#include <slow_print.hpp>
#include <win.hpp>

void win (void) {
    int offset_x = -7;
    int offset_y = -8;
    slow_print("Babis Potteridis", offset_x, offset_y);
    offset_x = -6;
    offset_y++;
    slow_print("found the Gem!", offset_x ,offset_y);
    offset_x = -3;
    offset_y++;
    attron(COLOR_PAIR(9));
    slow_print("You won!", offset_x, offset_y);
    // Back to default color pair
    attron(COLOR_PAIR(1));
    offset_x = -10;
    offset_y += 2;
    mvaddstr((LINES/2) + offset_y,
             (COLS/2)  + offset_x,
             "Press any key to exit...");
    refresh();
    getch();
}
