cmake_minimum_required(VERSION 3.24)
project(Compressor)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compressor main.cpp  Codec.cpp Codec.h FrequencyTable.cpp FrequencyTable.h  HuffmanTree.cpp HuffmanTree.h Node.h Node.cpp)
