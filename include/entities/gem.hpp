#include <entity.hpp>
#include <map.hpp>
#ifndef GEM_HPP
#define GEM_HPP
class Gem : public Entity {
    private:
    public:
        Gem(int x = 0, int y = 0) : Entity(x,y) {}
        void spawn_elsewhere(Map map);
        int generate_spawn_elsewhere_turn(Map map);
};
#endif
