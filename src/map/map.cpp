#include <vector>
#include <map.hpp>

Map::Map
(std::vector<std::vector<bool>> input_area, int input_lines, int input_columns) {
    area = input_area;
    // Temporary dimensions struct initialization
    Dimensions input_dimensions;
    input_dimensions.lines   = input_lines;
    input_dimensions.columns = input_columns;
    // Setting dimensions of map obj
    dimensions = input_dimensions;
}

std::vector<std::vector<bool>> Map::get_area(void) {
    return area;
}

void Map::set_area(std::vector<std::vector<bool>> input_area) {
    area = input_area;
}
