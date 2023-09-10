#include <iostream>
#include <filesystem>
#include "../include/Codec.h"
#include "../include/Utils.h"

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <compress/decompress> <input_file> <output_folder>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string inputFile = argv[2];
    std::string outputFolder = argv[3];

    if (!std::filesystem::exists(outputFolder)) {
        std::filesystem::create_directory(outputFolder);
    }

    if (mode == "compress") {
        std::string content = Utils::readFileToString(inputFile);
        content.push_back((unsigned char) EOF);

        std::vector<bool> compressedData = Codec::compress(content);
        std::string outputFilePath = outputFolder + "/" + std::filesystem::path(inputFile).filename().string() + ".cpred";
        Utils::writeBoolVectorToFile(outputFilePath, compressedData);
    } else if (mode == "decompress") {
        if (!Utils::hasMyZipExtension(inputFile)) {
            std::cerr << "Input file does not have a .cpred extension." << std::endl;
            return 1;
        }
        std::vector<bool> compressedData = Utils::readBoolVectorFromFile(inputFile);
        std::string decompressedContent = Codec::decompress(compressedData);
        std::string outputFilePath = outputFolder + "/" + std::filesystem::path(inputFile).stem().string();
        Utils::writeStringToFile(outputFilePath, decompressedContent);
    } else {
        std::cerr << "Invalid mode. Use 'compress' or 'decompress'." << std::endl;
        return 1;
    }

    return 0;
}