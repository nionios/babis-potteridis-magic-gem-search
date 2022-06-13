#include <entity.hpp>
#ifndef MOVABLE_HPP
#define MOVABLE_HPP
class Movable : public Entity {
    private:
    public:
        // Use constructor of Parent class entity
        Movable(int x, int y, char id) : Entity(x,y,id) {}
        void move_in_x_axis(int block_numbers);
        void move_in_y_axis(int block_numbers);
};
#endif
