#include <vector>
#include <string>
#include <map.hpp>

Map::Map
(std::vector<std::vector<bool>> input_area,
 int input_lines,
 int input_columns,
 std::string input_name) {
    area = input_area;
    // Temporary dimensions struct initialization
    Dimensions input_dimensions;
    input_dimensions.lines   = input_lines;
    input_dimensions.columns = input_columns;
    // Setting dimensions of map obj
    dimensions = input_dimensions;
    // Setting name of map
    name = input_name;
}

std::vector<std::vector<bool>> Map::get_area(void) {
    return area;
}

void Map::set_area(std::vector<std::vector<bool>> input_area) {
    area = input_area;
}

int Map::get_lines(void) {
    return dimensions.lines;
}

int Map::get_columns(void) {
    return dimensions.columns;
}

std::string Map::get_name(void) {
    return name;
}
