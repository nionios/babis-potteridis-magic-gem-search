#include <entity.hpp>
#include <cstdlib>
Entity::Entity(int input_x, int input_y, char input_id) {
    x = input_x;
    y = input_y;
    identifier = input_id;
}

void Entity::teleport(int input_x, int input_y) {
    set_x(input_x);
    set_y(input_y);
}

void Entity::set_x(int input_x) { x = input_x; }
void Entity::set_y(int input_y) { y = input_y; }

int  Entity::get_x(void)  { return x; }
int  Entity::get_y(void)  { return y; }
char Entity::get_id(void) { return identifier; }

void Entity::spawn (Map map) {
    // Teleport the Gem to a random location
    int new_x;
    int new_y;
    while (1) {
        new_x = rand() % map.get_columns();
        new_y = rand() % map.get_lines();
        // Keep setting these values until an empty position on the map is found
        if (map.get_area()[new_y][new_x] == 0) break;
    }
    teleport(new_x, new_y);
}

