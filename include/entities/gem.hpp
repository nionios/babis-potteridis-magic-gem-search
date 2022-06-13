#include <entity.hpp>
#include <map.hpp>
#ifndef GEM_HPP
#define GEM_HPP
// Use parent class constructor
class Gem : public Entity {
    public:
        // Use constructor of class entity
        Gem(int x = 0, int y = 0, char id = '$') : Entity(x,y,id) {}
        int generate_spawn_turn(Map map);
};
#endif
