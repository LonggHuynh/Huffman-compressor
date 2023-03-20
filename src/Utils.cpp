#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "../include/Utils.h"

std::string Utils::readFileToString(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::ostringstream content;
    content << inFile.rdbuf();
    return content.str();
}

void Utils::writeBoolVectorToFile(const std::string &filename, const std::vector<bool> &data) {
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    for (size_t i = 0; i < data.size(); i += 8) {
        char byte = 0;
        for (size_t j = 0; j < 8 && i + j < data.size(); ++j) {
            byte |= data[i + j] << (7 - j);
        }
        outFile.put(byte);
    }
}

std::vector<bool> Utils::readBoolVectorFromFile(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::vector<bool> data;
    char byte;
    while (inFile.get(byte)) {
        for (int i = 7; i >= 0; --i) {
            data.push_back((byte >> i) & 1);
        }
    }
    return data;
}

void Utils::writeStringToFile(const std::string &filename, const std::string &content) {
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    outFile.write(content.data(), content.size());
}


void Utils::addIntToBoolVector(std::vector<bool> &bool_vector, int value) {
    for (int i = HEADER_INT_LENGTH - 1; i >= 0; --i) {
        bool bit = (value >> i) & 1;
        bool_vector.push_back(bit);
    }
}


std::vector<int> Utils::boolVectorToIntVector(const std::vector<bool> &bool_vector) {
    std::vector<int> int_vec;
    size_t vector_size = bool_vector.size();

    for (size_t i = 0; i < vector_size; i += HEADER_INT_LENGTH) {
        int value = 0;

        for (int j = 0; j < HEADER_INT_LENGTH && i + j < vector_size; ++j) {
            value |= (bool_vector[i + j] << (HEADER_INT_LENGTH - 1 - j));
        }

        int_vec.push_back(value);
    }

    return int_vec;
}

bool Utils::hasMyZipExtension(const std::string &filename) {
    return filename.size() >= 6 && filename.substr(filename.size() - 6) == ".myzip";
}



