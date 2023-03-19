

#ifndef COMPRESSOR_HUFFMANTREE_H
#define COMPRESSOR_HUFFMANTREE_H


#include "Node.h"
#include "FrequencyTable.h"

class HuffmanTree {
    HuffmanTree(const std::array<int, 256> &codeLen);

    Node *root;
    std::array<int, 256> codeLengthTable;
    FrequencyTable frequencyTable;


private:
    void buildTree(FrequencyTable &table);

    void buildCodeTable();

public:

    HuffmanTree(const FrequencyTable &table);


    std::array<int,256> getCodeLengthTable();

};


#endif //COMPRESSOR_HUFFMANTREE_H
