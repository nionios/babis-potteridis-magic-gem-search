#include <entity.hpp>
#include <gem.hpp>
#include <potter.hpp>
#ifndef MALFOY_HPP
#define MALFOY_HPP
// Use parent class constructor
class Malfoy : public Entity {
    private:
        std::vector<std::pair<int,char>> create_candidates
            (Map map, Entity target);
    public:
        // Use constructor of parent class
        Malfoy(int x = 0, int y = 0, char id = 'L') : Entity(x,y,id) {}
        void move(Map map, Potter potter, Gem gem);
};
#endif
