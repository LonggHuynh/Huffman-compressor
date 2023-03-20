

#include <vector>
#include <random>
#include "Generators.h"

std::vector<bool> Generators::generateRandomBitArray(size_t size) {
    std::vector<bool> bit_array(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (size_t i = 0; i < size; ++i) {
        bit_array[i] = dis(gen);
    }

    return bit_array;
}

std::string Generators::generateRandomString(size_t length) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    std::string result;
    result.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        result.push_back(alphanum[dis(gen)]);
    }

    return result;
}