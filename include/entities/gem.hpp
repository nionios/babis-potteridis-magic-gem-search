#include <entity.hpp>
#include <map.hpp>
class Gem : Entity {
    private:
    public:
        void spawn_elsewhere(Dimensions map_dimensions);
        int generate_spawn_elsewhere_turn(Dimensions map_dimensions);
};

