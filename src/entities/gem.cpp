#include <gem.hpp>
#include <cstdlib>
void Gem::spawn_elsewhere(Dimensions map_dimensions) {
    // Teleport the Gem to a random location
    teleport(rand() % map_dimensions.columns + 1,
             rand() % map_dimensions.lines + 1);
}

int Gem::generate_spawn_elsewhere_turn(Dimensions map_dimensions) {
    /* Generate a random number of turns in which the Gem will teleport
     * checking is such that respawn is not overly early or late */
    int limit;
    int turn_number;
    while (1) {
        limit = map_dimensions.columns * map_dimensions.lines;
        turn_number = rand() % limit;
        if (turn_number > (limit/4) && turn_number < (limit/1.5)) break;
    }
    return turn_number;
}
