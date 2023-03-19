#include <iostream>
#include <algorithm>
#include <map>
#include "Codec.h"
#include "FrequencyTable.h"
#include "HuffmanTree.h"
#include "Utils.h"


std::array<int, 256> canonicalCode(const std::array<int, 256> &codeLengthTable) {
    std::array<int, 256> codeTable;
    codeTable.fill(0);
    std::vector<std::pair<unsigned char, int>> symbols;
    for (int symbol = 0; symbol < 256; ++symbol) {
        int codeLen = codeLengthTable[symbol];

        if (codeLen) {
            symbols.push_back({(unsigned char) symbol, codeLen});
        }
    }
    std::sort(symbols.begin(), symbols.end(),
              [](const std::pair<unsigned char, int> &a, const std::pair<unsigned char, int> &b) {
                  return a.second < b.second || (a.second == b.second && a.first < b.first);
              });

    // Generate canonical codes
    int currentCode = 0;
    int prevLen = symbols[0].second;
    for (const auto &symbol: symbols) {
        while (prevLen < symbol.second) {
            currentCode <<= 1;
            ++prevLen;
        }
        codeTable[symbol.first] = currentCode;
        ++currentCode;
    }

    return codeTable;
}


std::vector<bool> Codec::compress(const std::string &input) {
    FrequencyTable frequencyTable(input);

    HuffmanTree huffmanTree(frequencyTable);

    std::vector<bool> output;

    std::array<int, 256> codeLengthTable = huffmanTree.getCodeLengthTable();
    std::array<int, 256> codeTable = canonicalCode(codeLengthTable);


    for (int symbol = 0; symbol < 256; ++symbol) {
        Utils::addIntToBoolVector(output, codeLengthTable[symbol]);
    }

    for (unsigned char symbol: input) {

        int len = codeLengthTable[symbol];
        int code = codeTable[symbol];
        for (int pos = len - 1; pos >= 0; --pos) {
            output.push_back((code >> pos) & 1);
        }
    }


    //Padding
    while (output.size() % 8)
        output.push_back(false);


    return output; // Return the compressed string
}

std::string Codec::decompress(const std::vector<bool> &input) {
    // Implement the decompression algorithm here
    int header_length = HEADER_INT_LENGTH * 256;
    std::vector<bool> header(input.begin(), input.begin() + header_length); // contains elements from index 0 to n-1
    std::vector<bool> content(input.begin() + header_length, input.end());

    std::vector<int> codeLengthVector = Utils::boolVectorToIntVector(header);
    std::array<int, 256> codeLengthTable;
    std::copy(codeLengthVector.begin(), codeLengthVector.end(), codeLengthTable.begin());
    std::array<int, 256> codeTable = canonicalCode(codeLengthTable);

    //Could use unordered_map but it does not support pair while the performance is not practically better.
    std::map<std::pair<int, int>, unsigned char> codeToChar;
    for (int symbol = 0; symbol < 256; symbol++) {
        if (codeLengthTable[symbol])
            codeToChar[{codeLengthTable[symbol], codeTable[symbol]}] = (unsigned char) symbol;

    }

    std::vector<char> output;
    int curLen = 0;
    int curCode = 0;
    for (bool bit: content) {
        curLen++;
        curCode = (curCode << 1) | bit;
        if (codeToChar.count({curLen, curCode})) {

            unsigned char symbol = codeToChar[{curLen, curCode}];


            if (symbol == (unsigned char) EOF)
                break;

            output.push_back(symbol);
            curLen = 0;
            curCode = 0;


        }

    }
    return std::string(output.begin(), output.end()); // Return the decompressed string
}



