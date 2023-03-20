#include <iostream>
#include "../include/Codec.h"
#include "../include/Utils.h"

// Function to check if the given filename has a .myzip extension

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <compress/decompress> <input_file>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile;

    if (mode == "compress") {
        outputFile = inputFile + ".myzip";
        std::string content = Utils::readFileToString(inputFile);
        content.push_back((unsigned char) EOF);


        std::vector<bool> compressedData = Codec::compress(content);
        Utils::writeBoolVectorToFile(outputFile, compressedData);
    } else if (mode == "decompress") {
        if (!Utils::hasMyZipExtension(inputFile)) {
            std::cerr << "Input file does not have a .myzip extension." << std::endl;
            return 1;
        }
        outputFile = inputFile.substr(0, inputFile.size() - 6);
        std::vector<bool> compressedData = Utils::readBoolVectorFromFile(inputFile);
        std::string decompressedContent = Codec::decompress(compressedData);
        Utils::writeStringToFile(outputFile, decompressedContent);
    } else {
        std::cerr << "Invalid mode. Use 'compress' or 'decompress'." << std::endl;
        return 1;
    }

    return 0;
}
