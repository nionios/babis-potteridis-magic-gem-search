// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: 
// Compilation command : Running "make" command in root dir of the
//                       exercise to make, "make run" to make the
//                       executables and run. It should run if g++
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

int
main (int argc, char **argv)
{
    // Seed the random number generator. Needed for randomly spawning jewel
    srand(time(NULL));
    initscr();
    clear();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_CYAN,  COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    keypad(stdscr, TRUE);
    //Gather maps from disk and ask user which one to load
    intro();
    clear();
    try {
        std::vector<Map> map_list = gather_maps();
        print_map_menu(map_list);
        int choice = getch() - '0';
        clear();
        print_map(map_list[choice]);
    } catch (maps_dir_not_found ex) {
        std::cerr << ex.what() << std::endl;
    }
    getch();
    endwin();
}
