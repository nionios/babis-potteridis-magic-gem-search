#include <exceptions.hpp>
#include <exception>
#include <string>
std::string invalid_map_data::what(void) {
    return "Exception: Invalid map data in " + error_file + ":" +
           "\n Check line: " + std::to_string(error_line) +
            ", column: "     + std::to_string(error_col)  +
           "\n Unknown Symbol:" + error_symbol;
}
invalid_map_data::invalid_map_data
(std::string filename, int line, int col, char symbol) {
    // Construct exception object with the information of what file contains
    // the error
    error_file   = filename;
    error_line   = line;
    error_col    = col;
    error_symbol = symbol;
}

std::string invalid_entity_data::what(void) {
    return "Exception: Invalid entity data: \n Unknown Symbol: '"
            + std::to_string(error_symbol) +
           "', Initialization of an entity object has probably failed";
}
invalid_entity_data::invalid_entity_data
(char symbol) {
    // Mention the symbol that has is unknown to the program
    error_symbol = symbol;
}

maps_dir_not_found::maps_dir_not_found (std::string dirname) {
    error_dir = dirname;
}
std::string maps_dir_not_found::what(void) {
    return "Exception: Cannot find maps directory, directory '" +
            error_dir + "' not found";
}

maps_file_not_found::maps_file_not_found (std::string filename) {
    error_file = filename;
}
std::string maps_file_not_found::what(void) {
    return "Exception: Cannot find maps file, file '" +
            error_file + "' not found";
}
