#include <iostream>
#include <string>
#include <map.hpp>
#include <exceptions.hpp>

// This function does not just decode the data, it interprets it into objects
// too. Filename is given only for the case of the exception
Map
interpret
(std::vector<char> input_data_block,
 std::string filepath) {
    std::vector<std::vector<bool>> interpreted_area;
    char byte = 0;
    int line  = 0;
    int col   = 0;
    // prev_col is used because col=0 after last line is read, we keep the num
    // with this variable
    int prev_col = 0;
    std::vector<bool> first_row;
    // Initialize first row of interpreted_area with an empty vector
    interpreted_area.push_back(first_row);
    for (auto symbol : input_data_block) {
        // Add one to column number (in each iteration we move right + 1 byte
        switch (symbol) {
            // Change line to make 2D area and reset column number
            case '\n':
                {
                //DEBUG
                    std::cout << std::endl;
                line++;
                std::vector<bool> next_row;
                interpreted_area.push_back(next_row);
                prev_col = col;
                col = 0;
                }
            case '*':
                interpreted_area[line].push_back(true);
                //DEBUG
                std::cout << interpreted_area[line][col];
                col++;
                break;
            case '.':
                interpreted_area[line].push_back(false);
                //DEBUG
                std::cout << interpreted_area[line][col];
                col++;
                break;
            default:
                throw invalid_map_data(filepath, line, col, symbol);
                break;
        }
    }
    // Construct map object with interpreted data
    Map interpreted_map(interpreted_area, line, prev_col);
    return interpreted_map;
}
