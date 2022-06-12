#include <iostream>
#include <regex>
#include <string>
#include <map.hpp>
#include <exceptions.hpp>
// This function does not only decode the data, it interprets it into objects
// too.
Map
interpret
(std::vector<char> input_data_block,
 std::string filepath) {
    std::vector<std::vector<bool>> interpreted_area;
    char byte = 0;
    int line  = 0;
    int col   = 0;
    // total_col is used because col=0 after last line is read, we keep the num
    // with this variable
    int total_col = 0;
    std::vector<bool> first_row;
    // Initialize first row of interpreted_area with an empty vector
    interpreted_area.push_back(first_row);
    // In case '.' or '*', add one to column number
    // (in each iteration we move right + 1 byte)
    for (auto & symbol : input_data_block) {
        switch (symbol) {
            case '*':
                interpreted_area[line].push_back(true);
                col++;
                break;
            case '.':
                interpreted_area[line].push_back(false);
                col++;
                break;
            // Change line to make 2D area and reset column number
            case '\n':
                {//Limit scope in this case
                    line++;
                    //Initialize vector for making the next row
                    std::vector<bool> next_row;
                    interpreted_area.push_back(next_row);
                    total_col = col;
                    col = 0;
                    break;
                }
            default:
                throw invalid_map_data(filepath, line, col, symbol);
                break;
        }
    }
    std::string interpreted_name = std::regex_replace(filepath,
                                         std::regex("maps/"),
                                         "");
    interpreted_name = std::regex_replace(interpreted_name,
                                         std::regex("_"),
                                         " ");
    interpreted_name = std::regex_replace(interpreted_name,
                                         std::regex("\\.txt"),
                                         " ");
    // Construct map object with interpreted data (give_total col since col is
    // reset)
    Map interpreted_map(interpreted_area, line, total_col, interpreted_name);
    return interpreted_map;
}
