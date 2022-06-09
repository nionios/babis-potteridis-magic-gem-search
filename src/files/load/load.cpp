#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: function to load every byte of selected map data file from disk

std::vector<char>
load(std::string filename) {
    std::vector<char> loaded_data;
    char byte = 0;

    std::fstream data(filename, std::fstream::in);
    if (!data.is_open()) {
        std::cout << "* Data load from file " << filename << " failed."
                  << std::endl;
    } else {
        // Get every byte from the map file
        while (data.get(byte)) {
            loaded_data.push_back(byte);
        }
    }
    std::cout << "* Data load from file " << filename << " completed!"
              << std::endl;
    data.close();
    return loaded_data;
}
