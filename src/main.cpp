// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: This is the main function of the videogame. From here,
//              ncurses will be initialized and screens will be cleared, etc.
// Compilation command : Running "make" command in root dir of the
//                       exercise to make, "make run" to make the
//                       executable and run. It should run if g++
//                       is installed on the host machine.
// My machine specs: Arch Linux, kernel: 5.17.5-arch1-1, g++ (GCC) 11.2.0
#include <iostream>
#include <string>
#include <time.h>
#include <ncurses.h>
#include <all_helpers.hpp>
#include <map.hpp>
#include <print_map.hpp>
#include <print_map_menu.hpp>
#include <exceptions.hpp>
#include <intro.hpp>
#include <gem.hpp>
#include <place_gem.hpp>

int
main (int argc, char **argv)
{
    // Seed the random number generator. Needed for randomly spawning jewel
    srand(time(NULL));
    setup_ncurses();
    init_pairs();
    attron(COLOR_PAIR(1));
    intro();
    clear();
    //Gather maps from disk and ask user which one to load
    try {
        std::vector<Map> map_list = gather_maps();
        print_map_menu(map_list);
        int choice = -1;
        // Ignore input that is invalid
        while (choice < 0 || choice > map_list.size() - 1) {
           choice = getch() - '0';
        }
        clear();
        print_map(map_list[choice]);
        Gem gem;
        gem.spawn_elsewhere(map_list[choice]);
        place_gem(gem,map_list[choice]);
        refresh();
    } catch (maps_dir_not_found ex) {
        std::cerr << ex.what() << std::endl;
    }
    getch();
    endwin();
}
