

#ifndef COMPRESSOR_UTILS_H
#define COMPRESSOR_UTILS_H


#include <string>

namespace Utils {
    int bitLength(int num);

    void writeBitStreamToFile(std::vector<bool> &bitStream, const std::string &outputFile);

    std::vector<bool> readBitStreamFromFile(const std::string &inputFile);

    std::vector<bool> generateRandomBitArray(size_t size);
}


#endif //COMPRESSOR_UTILS_H
