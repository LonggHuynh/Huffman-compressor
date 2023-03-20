#ifndef COMPRESSOR_HUFFMANTREE_H
#define COMPRESSOR_HUFFMANTREE_H

#include "Node.h"
#include "FrequencyTable.h"

/**
 * @brief A class representing a Huffman Tree for data compression.
 */
class HuffmanTree {
private:
    Node *root;
    std::array<int, 256> codeLengthTable;
    FrequencyTable frequencyTable;

    /**
     * @brief Build the Huffman Tree using the given FrequencyTable.
     * @param table The FrequencyTable object used to build the tree.
     */
    void buildTree(FrequencyTable &table);

    /**
     * @brief Build the code length table from the Huffman Tree.
     */
    void buildCodeTable();

public:
    /**
     * @brief Construct a HuffmanTree object from the given FrequencyTable.
     * @param table The FrequencyTable object used to build the tree.
     */
    HuffmanTree(const FrequencyTable &table);

    /**
     * @brief Get the code length table for the Huffman Tree.
     * @return The code length table represented as an array.
     */
    std::array<int, 256> getCodeLengthTable();

};

#endif //COMPRESSOR_HUFFMANTREE_H
