

#ifndef COMPRESSOR_HUFFMANTREE_H
#define COMPRESSOR_HUFFMANTREE_H


#include "Node.h"
#include "FrequencyTable.h"

class HuffmanTree {
    Node *root;
    std::array<char16_t, 256> codeTable;


private:
    void buildTree(FrequencyTable &table);
    void buildCodeTable();

public:

    HuffmanTree(FrequencyTable &table);
    HuffmanTree(std::array<std::byte, 256> codeLen);

    std::array<char16_t,256> originalCode();
    std::array<char16_t,256> canonicalCode();

};


#endif //COMPRESSOR_HUFFMANTREE_H
