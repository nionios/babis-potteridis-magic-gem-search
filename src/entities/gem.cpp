#include <gem.hpp>
#include <map.hpp>
#include <cstdlib>

void Gem::spawn_elsewhere (Map map) {
    // Teleport the Gem to a random location
    int new_x;
    int new_y;
    while (1) {
        new_x = rand() % map.get_columns() + 1;
        new_y = rand() % map.get_lines()   + 1;
        // Keep setting these values until an empty position is found
        if (map.get_area()[new_y][new_x]) break;
    }
    teleport(new_x, new_y);
}

int Gem::generate_spawn_elsewhere_turn (Map map) {
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
