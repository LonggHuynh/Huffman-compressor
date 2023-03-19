#include <iostream>
#include "Codec.h"
#include "FrequencyTable.h"
#include "HuffmanTree.h"
#include "Utils.h"


std::vector<bool> Codec::compress(const std::string &input) {
    FrequencyTable frequencyTable(input);

    HuffmanTree huffmanTree(frequencyTable);

    std::vector<bool> output;


    for (int symbol = 0; symbol < 256; ++symbol) {
        Utils::addIntToBoolVector(output, huffmanTree.getCodeLength(symbol));
    }

    for (unsigned char symbol: input) {

        int len = huffmanTree.getCodeLength(symbol);
        int code = huffmanTree.getCode(symbol);
        for (int pos = len - 1; pos >= 0; --pos) {
            output.push_back((code >> pos) & 1);
        }
    }
    while (output.size() % 8)
        output.push_back(false);




    return output; // Return the compressed string
}

std::string Codec::decompress(const std::vector<bool> &input) {
    // Implement the decompression algorithm here
    int header_length = HEADER_INT_LENGTH * 256;
    std::vector<bool> header(input.begin(), input.begin() + header_length); // contains elements from index 0 to n-1
    std::vector<bool> content(input.begin() + header_length, input.end());

    std::vector<int> codeLength = Utils::boolVectorToIntVector(header);


    return ""; // Return the decompressed string
}

