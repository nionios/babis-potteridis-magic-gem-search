#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <exceptions.hpp>
// Code by Dennis Nikolopoulos
// AM: 18390126
// Description: function to load every byte of selected map data file from disk

std::vector<char>
load(std::string filepath) {
    std::vector<char> loaded_data;
    char byte = 0;
    std::ifstream input_file(filepath);
    // If file isn't found, thow exception
    if (!input_file.is_open()) {
        throw maps_file_not_found(filepath);
    }
    // Read every byte from file and load into vector
    while (input_file.get(byte)) {
        loaded_data.push_back(byte);
    }
    input_file.close();
    return loaded_data;
}
