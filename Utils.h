#ifndef COMPRESSOR_UTILS_H
#define COMPRESSOR_UTILS_H

// Assume there are 256 characters, the int size is at most 1 byte.
#define HEADER_INT_LENGTH 8

#include <string>
#include <vector>

namespace Utils {

    /**
     * @brief Generate a random bit array
     * @param size Size of the bit array
     * @return Randomly generated bit array
     */
    std::vector<bool> generateRandomBitArray(size_t size);

    /**
     * @brief Generate a random string
     * @param length Length of the random string
     * @return Randomly generated string
     */
    std::string generateRandomString(size_t length);

    /**
     * @brief Add an integer to a bool vector
     * @param bool_vector Bool vector to be modified
     * @param value Integer value to be added
     */
    void addIntToBoolVector(std::vector<bool> &bool_vector, int value);

    /**
     * @brief Convert a bool vector to an int vector
     * @param bool_vector Input bool vector
     * @return Converted int vector
     */
    std::vector<int> boolVectorToIntVector(const std::vector<bool> &bool_vector);

    /**
     * @brief Read a bool vector from a file
     * @param filename Name of the input file
     * @return Bool vector read from the file
     */
    std::vector<bool> readBoolVectorFromFile(const std::string &filename);

    /**
     * @brief Write a string to a file
     * @param filename Name of the output file
     * @param content String to be written to the file
     */
    void writeStringToFile(const std::string &filename, const std::string &content);

    /**
     * @brief Write a bool vector to a file
     * @param filename Name of the output file
     * @param data Bool vector to be written to the file
     */
    void writeBoolVectorToFile(const std::string &filename, const std::vector<bool> &data);

    /**
     * @brief Read file content into a string
     * @param filename Name of the input file
     * @return Content of the file as a string
     */
    std::string readFileToString(const std::string &filename);
}

#endif //COMPRESSOR_UTILS_H
