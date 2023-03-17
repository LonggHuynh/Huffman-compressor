cmake_minimum_required(VERSION 3.24)
project(Compressor)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compressor main.cpp Huffman.h Codec.cpp FrequencyTable.cpp Huffman.cpp HuffmanTree.cpp Node.h)
