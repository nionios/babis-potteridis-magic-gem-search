#include <movable.hpp>
#ifndef POTTER_HPP
#define POTTER_HPP
// Use parent class constructor (parent of parent constructor, Entity)
class Potter : public Movable {
    public:
        // Use constructor of class Movable (That is using the Entity constuctor)
        Potter(int x = 0, int y = 0, char id='M') : Movable(x,y,id) {}
};
#endif
