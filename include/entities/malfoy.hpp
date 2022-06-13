#include <entity.hpp>
#include <potter.hpp>
#ifndef MALFOY_HPP
#define MALFOY_HPP
// Use parent class constructor
class Malfoy : public Entity {
    public:
        // Use constructor of parent class
        Malfoy(int x = 0, int y = 0, char id = 'L') : Entity(x,y,id) {}
        void move(Map map, Potter potter);
};
#endif
