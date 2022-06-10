#include <vector>
class Map {
    private:
        //2D vector to mark out area, 1 is wall, 0 is empty space (corridor)
        std::vector<std::vector<bool>> area;
    public:
        Map(std::vector<std::vector<bool>> input_area);
        std::vector<std::vector<bool>> get_area(void);
        void set_area(std::vector<std::vector<bool>>);
};
