

#ifndef COMPRESSOR_HUFFMANTREE_H
#define COMPRESSOR_HUFFMANTREE_H


#include "Node.h"
#include "FrequencyTable.h"

class HuffmanTree {
    Node* root ;
    std::array<char16_t, 256> codeTable;



private:
    void buildTree(FrequencyTable &table);
    void buildCodeTable();


public:
    HuffmanTree(FrequencyTable &table);







};


#endif //COMPRESSOR_HUFFMANTREE_H
