

#ifndef COMPRESSOR_HUFFMANTREE_H
#define COMPRESSOR_HUFFMANTREE_H


#include "Node.h"
#include "FrequencyTable.h"

class HuffmanTree {
    Node *root;
    std::array<int, 256> codeTable;
    std::array<int, 256> codeLengthTable;
    FrequencyTable frequencyTable;


private:
    void buildTree(FrequencyTable &table);

    void buildCodeTable();

public:

    HuffmanTree(const FrequencyTable &table);

    HuffmanTree(std::array<std::byte, 256> codeLen);

    int getCode(unsigned char symbol);

    int getCodeLength(unsigned char symbol);

};


#endif //COMPRESSOR_HUFFMANTREE_H
