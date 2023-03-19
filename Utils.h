

#ifndef COMPRESSOR_UTILS_H
#define COMPRESSOR_UTILS_H

//Assume there are 256 characters, the int size is at most 1 byte.
#define HEADER_INT_LENGTH 8

#include <string>

namespace Utils {
    int bitLength(int num);

    void writeBitStreamToFile(std::vector<bool> &bitStream, const std::string &outputFile);

    std::vector<bool> readBitStreamFromFile(const std::string &inputFile);

    std::vector<bool> generateRandomBitArray(size_t size);

    void addIntToBoolVector(std::vector<bool> &bool_vector, int value);

    std::vector<int> boolVectorToIntVector(const std::vector<bool> &bool_vector);
}


#endif //COMPRESSOR_UTILS_H
