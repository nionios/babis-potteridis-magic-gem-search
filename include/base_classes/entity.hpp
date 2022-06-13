#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <map.hpp>
class Entity {
    private:
        int x;
        int y;
        char identifier;
    public:
        Entity(int input_x, int input_y, char input_id);
        void teleport(int input_x, int input_y);
        void spawn (Map map);
        void set_x(int input_x);
        void set_y(int input_y);
        int  get_x(void);
        int  get_y(void);
        char get_id(void);
};
#endif
