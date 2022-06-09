#include <entity.hpp>
class Movable : public Entity {
    private:
    public:
        void move_in_x_axis(int block_numbers);
        void move_in_y_axis(int block_numbers);
};

