/**
 * @file Codec.h
 * @brief This file provides the Codec class for compressing and decompressing data.
 */

#ifndef CODEC_H
#define CODEC_H

#include <string>
#include <vector>

/**
 * @class Codec
 * @brief The Codec class provides static methods for compressing and decompressing data.
 *
 * This class implements compression and decompression algorithms for
 * converting data between a string and a vector of boolean values.
 */
class Codec {
public:
    /**
     * @brief Compresses the input data.
     *
     * Compresses the given input string using a custom compression algorithm
     * and returns a vector of boolean values representing the compressed data.
     *
     * @param input The input string to be compressed.
     * @return A vector of boolean values representing the compressed data.
     */
    static std::vector<bool> compress(const std::string &input);

    /**
     * @brief Decompresses the input data.
     *
     * Decompresses the given input vector of boolean values using a custom decompression
     * algorithm and returns a string representing the decompressed data.
     *
     * @param input The input vector of boolean values to be decompressed.
     * @return A string representing the decompressed data.
     */
    static std::string decompress(const std::vector<bool> &input);
};

#endif // CODEC_H
