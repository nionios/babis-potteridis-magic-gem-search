/* Code by Dennis Nikolopoulos
 * AM: 18390126
 * License: GPLv3
 * Description: This is the main function of the videogame. From here,
 *              ncurses will be initialized and screens will be cleared, etc.
 * Compilation command : Running "make" command in root dir of the
 *                       exercise to make, "make run" to make the
 *                       executable and run. It should run if g++
 *                       is installed on the host machine.
 * My machine specs: Arch Linux, kernel: 5.17.5-arch1-1, g++ (GCC) 11.2.0
 */
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
#include <place.hpp>
#include <erase.hpp>

int
main (int argc, char **argv)
{
    // Seed the random number generator. Needed for randomly spawning jewel
    srand(time(NULL));
    setup_ncurses();
    init_pairs();
    attron(COLOR_PAIR(1));
//    intro();
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
        Map * curr_map = &map_list[choice];
        clear();
        print_map(*curr_map);
        // Spawn all entities
        Gem gem;
        gem.spawn(*curr_map);
        Malfoy malfoy;
        malfoy.spawn(*curr_map);
        Potter potter;
        potter.spawn(*curr_map);
        // Place all entities on the map
        place(gem,*curr_map);
        place(malfoy,*curr_map);
        place(potter,*curr_map);
        // Start playing the game
        int turn = 0;
        // Generate the turn in which the gem respawns
        int gem_spawn_turn = gem.generate_spawn_turn(*curr_map);
        while (1) {
            if (potter.get_x() == malfoy.get_x() &&
                potter.get_y() == malfoy.get_y()) {
                clear();
                //lose();
                break;
            } else if (potter.get_x() == gem.get_x() &&
                       potter.get_y() == gem.get_y()) {
                clear();
                //win();
                break;
            }
            // Respawn and replace the gem if the appropriate turn has come
            if (turn == gem_spawn_turn) {
                // Erase the gem in its current position
                erase(gem, *curr_map);
                gem.spawn(*curr_map);
                // Make turn zero to recount
                turn = 0;
                // Generate the next turn to spawn
                gem_spawn_turn = gem.generate_spawn_turn(*curr_map);
                // Replace the gem
                place(gem,*curr_map);
                refresh();
            }
//            potter.move();
            refresh();
 //           malfoy.move();
            refresh();
            // Increment turn by 1
            turn++;
        }
        refresh();
    } catch (maps_dir_not_found ex) {
        std::cerr << ex.what() << std::endl;
    }
    getch();
    endwin();
}
