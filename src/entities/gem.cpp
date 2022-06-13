/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: Function of Gem object to generate the number of turns that
 *              will pass for the Gem to spawn somewhere else in the map
 */
#include <gem.hpp>
#include <map.hpp>
#include <cstdlib>

int Gem::generate_spawn_turn (Map map) {
    /* Generate a random number of turns in which the Gem will teleport
     * checking is such that respawn is not overly early or late */
    int limit;
    int turn_number;
    while (1) {
        limit = map.get_columns() * map.get_lines();
        turn_number = rand() % limit;
        if (turn_number > (limit/4) && turn_number < (limit/1.5)) break;
    }
    return turn_number;
}
