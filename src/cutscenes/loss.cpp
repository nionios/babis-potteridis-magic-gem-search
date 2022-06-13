/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Losing sequence
 */
#include <ncurses.h>
#include <slow_print.hpp>
#include <loss.hpp>

void loss (void) {
    int offset_x = -6;
    int offset_y = -8;
    slow_print("Lukas Malfoy", offset_x, offset_y);
    offset_x = -7;
    offset_y++;
    slow_print("caught Babis!", offset_x ,offset_y);
    offset_x = -4;
    offset_y++;
    attron(COLOR_PAIR(10));
    slow_print("You lost!", offset_x, offset_y);
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
