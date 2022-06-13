/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function to move Malfoy around on the map. He follows potter
 *              calculating where to go based on where the straight line to
 *              potters coordinates is closer.
 */
#include <ncurses.h>
#include <map.hpp>
#include <potter.hpp>
#include <erase.hpp>
#include <place.hpp>
void Malfoy::move(Map map, Potter potter) {
    // Straight line is y2 – y1*x2  – x1  when malfoy(x1,x2) and potter(x2,y2)
    if (this->get_x()+1)
}
