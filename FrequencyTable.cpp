

#include "FrequencyTable.h"


void FrequencyTable::addSymbol(char symbol) {
    unsigned char location = static_cast<unsigned char>(symbol);
    FrequencyTable::frequencies[location]++;
}

int FrequencyTable::getFrequency(char symbol) {
    unsigned char location = static_cast<unsigned char>(symbol);
    return FrequencyTable::frequencies[location];
}

FrequencyTable::FrequencyTable(std::string content) {
    frequencies.fill(0);
    for (char symbol: content) {
        this->addSymbol(symbol);
    }
    addSymbol((unsigned char) EOF);

}