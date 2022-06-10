#include <load.hpp>
#include <interpret.hpp>
#include <sstream>
#include <iostream>
#include <exceptions.hpp>
#include <dirent.h>
// Helper function to load every map file from directory into the interpret
// function. This returns a list of the maps loaded.

std::vector<Map>
gather_maps
(void) {
    struct dirent *dirent_ptr;
    DIR *target_dir;

    target_dir = opendir("maps");
    if (target_dir == NULL) throw maps_dir_not_found();

    // Make a vector to store all the map objects
    std::vector<Map> loaded_map_list;
    // Process each entry.
    while ((dirent_ptr = readdir(target_dir)) != NULL) {
    //    printf ("[%s]\n", dirent_ptr->d_name);
        // Loading all files in directory
        std::string filename = dirent_ptr->d_name;
        std::vector<char> loaded_data_block = load(filename);
        try {
            Map loaded_map(interpret(loaded_data_block, filename));
            loaded_map_list.push_back(loaded_map);
        } catch (invalid_map_data ex) {
            std::cerr << ex.what() << std::endl;
        }
    }

    // Close directory, return.
    closedir (target_dir);
    return loaded_map_list;
}
