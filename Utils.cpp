

#include <algorithm>
#include <fstream>
#include <iostream>
#include <cassert>
#include <random>
#include "Utils.h"

int Utils::bitLength(int num) {
    int length = 0;
    for (; num; num >>= 1) {
        length++;
    }
    return std::max(length, 1);

}

void Utils::writeBitStreamToFile(std::vector<bool> &bitStream, const std::string &outputFile) {
    std::ofstream output_file(outputFile, std::ios::binary);

    if (!output_file) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    //Padding
    while (bitStream.size() % 8 != 0) {
        bitStream.push_back(false);
    }

    unsigned char byte = 0;
    int bit_position = 0;

    for (bool bit: bitStream) {
        byte |= (bit << (7 - bit_position));
        bit_position++;

        if (bit_position == 8) {
            output_file.write(reinterpret_cast<char *>(&byte), sizeof(byte));
            byte = 0;
            bit_position = 0;
        }
    }



    // Write the last byte if the bit stream was not a multiple of 8 bits
    if (bit_position > 0) {
        output_file.write(reinterpret_cast<char *>(&byte), sizeof(byte));
    }

    output_file.close();

    std::cout << "Bit stream successfully written to " << outputFile << std::endl;
}

std::vector<bool> Utils::readBitStreamFromFile(const std::string &inputFile) {
    std::ifstream input_file(inputFile, std::ios::binary);

    if (!input_file) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return std::vector<bool>();
    }

    std::vector<bool> bit_stream;
    unsigned char byte;

    while (input_file.read(reinterpret_cast<char *>(&byte), sizeof(byte))) {
        for (int bit_position = 0; bit_position < 8; ++bit_position) {
            bool bit = (byte >> (7 - bit_position)) & 1;
            bit_stream.push_back(bit);
        }
    }

    input_file.close();

    return bit_stream;
}

std::vector<bool> generateRandomBitArray(size_t size) {
    std::vector<bool> bit_array(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (size_t i = 0; i < size; ++i) {
        bit_array[i] = dis(gen);
    }

    return bit_array;
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


//void testReadWriteBitStreamToFile() {
//    std::vector<bool> bit_stream = generateRandomBitArray(300);
//    std::string output_file = "test_output.bin";
//
//    Utils::writeBitStreamToFile(bit_stream, output_file);
//    std::vector<bool> read_bit_stream = Utils::readBitStreamFromFile(output_file);
//
//    assert(bit_stream == read_bit_stream);
//    std::cout << "Test passed: writeBitStreamToFile and readBitStreamFromFile work correctly." << std::endl;
//}
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    testReadWriteBitStreamToFile();
//
//    return 0;
//}



