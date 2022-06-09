#include <vector>
#include <map.hpp>
Map::Map (std::vector<std::vector<bool>> input_area) {
    area = input_area;
}

std::vector<std::vector<bool>> Map::get_area(void) {
    return area;
}

void Map::set_area(std::vector<std::vector<bool>> input_area) {
    area = input_area;
}
