#ifndef COMPRESSOR_FREQUENCYTABLE_H
#define COMPRESSOR_FREQUENCYTABLE_H

#include <vector>
#include <string>
#include <array>

/**
 * @brief A class representing a frequency table for a given content.
 */
class FrequencyTable {
private:
    std::array<int, 256> frequencies;

    /**
     * @brief Increment the frequency of the given symbol.
     * @param symbol The character whose frequency is to be incremented.
     */
    void addSymbol(char symbol);

public:

    /**
     * @brief Get the frequency of the given symbol.
     * @param symbol The character whose frequency is to be retrieved.
     * @return The frequency of the given symbol.
     */
    int getFrequency(char symbol);

    /**
     * @brief Construct a FrequencyTable object from the given content.
     * @param content The string whose symbol frequencies are to be computed.
     */
    FrequencyTable(std::string content);

};

#endif //COMPRESSOR_FREQUENCYTABLE_H
