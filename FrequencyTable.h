
#ifndef COMPRESSOR_FREQUENCYTABLE_H
#define COMPRESSOR_FREQUENCYTABLE_H


#include <vector>
#include <string>
#include <array>


class FrequencyTable {
private:
    std::array<int, 256> frequencies;

    /*
     * Increment the frequency of the symbol.
     */
    void addSymbol(char symbol);

public:

    /*
     * Return the frequency of the symbol.
     */
    int getFrequency(char symbol);


    /*
     * Constructor
     */
    FrequencyTable(std::string content);

    FrequencyTable();


};


#endif //COMPRESSOR_FREQUENCYTABLE_H
