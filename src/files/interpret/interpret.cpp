#include <iostream>
#include <string>
#include <map.hpp>
#include <exceptions.hpp>

// This function does not just decode the data, it interprets it into objects
// too. Filename is given only for the case of the exception
Map
interpret
(std::vector<char> input_data_block,
 std::string filename) {
    char byte = 0;
    std::vector<std::vector<bool>> interpreted_area;
    int line = 0;
    int col  = 0;
    for (auto symbol : input_data_block) {
        // Add one to column number (in each iteration we move right + 1 byte
        col++;
        switch (symbol) {
            // Change line to make 2D area and reset column number
            case '\n':
                line++;
                col = 0;
            case '*':
                interpreted_area[line].push_back(1);
                break;
            case '.':
                interpreted_area[line].push_back(0);
                break;
            default:
                throw invalid_map_data(filename, line, col, symbol);
                break;
        }
    }
    Map interpreted_map(interpreted_area);
    return interpreted_map;
}
