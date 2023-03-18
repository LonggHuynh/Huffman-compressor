#include <iostream>
#include "Codec.h"
#include "FrequencyTable.h"
#include "HuffmanTree.h"

namespace Codec {

    std::string compress(const std::string &input) {
        FrequencyTable frequencyTable(input);

        HuffmanTree huffmanTree(frequencyTable);
        auto l = huffmanTree.canonicalCodes();
        return ""; // Return the compressed string
    }

    std::string decompress(const std::string &input) {
        // Implement the decompression algorithm here
        return ""; // Return the decompressed string
    }

} // namespace Codec
