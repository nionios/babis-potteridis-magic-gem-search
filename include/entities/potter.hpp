#include <entity.hpp>
#ifndef POTTER_HPP
#define POTTER_HPP
// Use parent class constructor
class Potter : public Entity {
    public:
        // Use constructor of parent class
        Potter(int x = 0, int y = 0, char id = 'M') : Entity(x,y,id) {}
        void move(Map map);
};
#endif
