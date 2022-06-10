#include <vector>

struct Dimentions {
    int lines;
    int columns;
};

class Map {
    private:
        //2D vector to mark out area, 1 is wall, 0 is empty space (corridor)
        std::vector<std::vector<bool>> area;
        Dimentions dimentions;
    public:
        Map(std::vector<std::vector<bool>> input_area, int lines, int columns);
        std::vector<std::vector<bool>> get_area(void);
        void set_area(std::vector<std::vector<bool>>);
};
