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
    keypad(stdscr, TRUE);
    //Gather maps from disk and ask user which one to load
    std::vector<Map> map_list = gather_maps();
//    while (1) {
//      for (auto entry : map_list) {
//      }
//    }
    intro();
    while(1){}
    endwin();
}
