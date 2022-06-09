#include <vector>
class Map {
    private:
        //2D vector to mark out area
        std::vector<std::vector<bool>> area;
    public:
        Map(std::vector<std::vector<bool>> input_area);
        std::vector<std::vector<bool>> get_area(void);
        void set_area(std::vector<std::vector<bool>>);
};
