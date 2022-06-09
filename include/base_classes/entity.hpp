class Entity {
    private:
        int x;
        int y;
    public:
        Entity(int input_x, int input_y);
        void set_x(int input_x);
        void set_y(int input_y);
        int get_x(void);
        int get_y(void);
        void teleport(int input_x, int input_y);
};
