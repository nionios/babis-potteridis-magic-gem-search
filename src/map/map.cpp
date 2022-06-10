#include <vector>
#include <map.hpp>

Map::Map
(std::vector<std::vector<bool>> input_area, int input_lines, int input_columns) {
    area = input_area;
    // Temporary dimentions struct initialization
    Dimentions input_dimentions;
    input_dimentions.lines   = input_lines;
    input_dimentions.columns = input_columns;
    // Setting dimentions of map obj
    dimentions = input_dimentions;
}

std::vector<std::vector<bool>> Map::get_area(void) {
    return area;
}

void Map::set_area(std::vector<std::vector<bool>> input_area) {
    area = input_area;
}
