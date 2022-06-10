#include <exceptions.hpp>
#include <exception>
#include <string>
std::string invalid_map_data::what(void) {
    return "Exception: Invalid map data in " + error_file;
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

std::string maps_dir_not_found::what(void) {
    return "Exception: Invalid subject data in subject_data.txt";
};
