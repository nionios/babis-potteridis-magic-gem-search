#include <jewel.hpp>
#include <time.h>
void Jewel::spawn_elsewhere(Dimentions map_dimentions) {
    int y = rand() % map_dimentions.columns;
    int x = rand() % map_dimentions.lines;
}
