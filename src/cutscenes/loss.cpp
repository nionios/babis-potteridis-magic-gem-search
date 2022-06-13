/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Losing sequence. If mode is true, then Babis got caught by
 *              Lucas. Else, Lucas got the gem.
 */
#include <ncurses.h>
#include <slow_print.hpp>
#include <loss.hpp>

void loss (bool mode) {
    int offset_x = -6;
    int offset_y = -8;
    slow_print("Lucas Malfoy", offset_x, offset_y);
    offset_y++;
    if (mode) {
        offset_x = -7;
        slow_print("caught Babis!", offset_x ,offset_y);
    } else {
        offset_x = -6;
        slow_print("got the Gem!", offset_x ,offset_y);
    }
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
