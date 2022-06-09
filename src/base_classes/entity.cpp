#include <entity.hpp>
Entity::Entity(int input_x, int input_y) {
    x = input_x;
    y = input_y;
}

void Entity::teleport(int input_x, int input_y) {
    set_x(input_x);
    set_y(input_y);
}

void Entity::set_x(int input_x) {
    x = input_x;
}

void Entity::set_y(int input_y) {
    y = input_y;
}

int Entity::get_x(void) {
    return x;
}

int Entity::get_y(void) {
    return y;
}
