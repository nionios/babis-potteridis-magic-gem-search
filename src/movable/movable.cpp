#include <movable.hpp>

void Movable::move_in_y_axis(int block_number){
    set_y(get_y() - block_number);
}

void Movable::move_in_x_axis(int block_number){
    set_x(get_x() - block_number);
}
