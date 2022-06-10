#ifndef MAP_HPP
#define MAP_HPP
#include <vector>

struct Dimensions {
    int lines;
    int columns;
};

class Map {
    private:
        //2D vector to mark out area, 1 is wall, 0 is empty space (corridor)
        std::vector<std::vector<bool>> area;
        Dimensions dimensions;
    public:
        Map(std::vector<std::vector<bool>> input_area, int lines, int columns);
        std::vector<std::vector<bool>> get_area(void);
        void set_area(std::vector<std::vector<bool>>);
        int get_lines(void);
        int get_columns(void);
};
#endif
