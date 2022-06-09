#include <iostream>
#include <map.hpp>
#include <exceptions.hpp>

// This function does not just decode the data, it interprets it into objects
// too.
Map
interpret
(std::vector<char> input_data_block) {
    char byte = 0;
    std::vector<std::vector<bool>> interpreted_area;
    int line = 0;
    for (auto & symbol : input_data_block)
        switch (symbol) {
            // Change line to make 2D area
            case '\n':
                line++;
            case '*':
                interpreted_area[line].push_back(1);
                break;
            case '.':
                interpreted_area[line].push_back(0);
                break;
        }
    Map interpreted_map(interpreted_area);
    return interpreted_map;
}
