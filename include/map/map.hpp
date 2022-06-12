#ifndef MAP_HPP
#define MAP_HPP
#include <vector>
#include <string>

struct Dimensions {
    int lines;
    int columns;
};

class Map {
    private:
        //2D vector to mark out area, 1 is wall, 0 is empty space (corridor)
        std::vector<std::vector<bool>> area;
        Dimensions dimensions;
        std::string name;
    public:
        Map(std::vector<std::vector<bool>> input_area,
            int lines,
            int columns,
            std::string input_name);
        std::vector<std::vector<bool>> get_area(void);
        void set_area(std::vector<std::vector<bool>>);
        int get_lines(void);
        int get_columns(void);
        std::string get_name(void);
};
#endif
