#include <exception>
#include <string>
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
class invalid_map_data : std::exception {
    private:
        std::string error_file;
        int error_line;
        int error_col;
        char error_symbol;
    public:
        invalid_map_data(std::string filename, int line, int col, char symbol);
        std::string what(void);
};
class maps_dir_not_found : std::exception {
    public:
        std::string what(void);
};
#endif
