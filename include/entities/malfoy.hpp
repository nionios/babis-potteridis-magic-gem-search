#include <movable.hpp>
#include <potter.hpp>
#ifndef MALFOY_HPP
#define MALFOY_HPP
// Use parent class constructor (parent of parent constructor, Entity)
class Malfoy : public Movable {
    public:
        // Use constructor of class Movable (That is using the Entity constuctor)
        Malfoy(int x = 0, int y = 0, char id = 'L') : Movable(x,y,id) {}
        void move(Map map, Potter potter);
};
#endif
