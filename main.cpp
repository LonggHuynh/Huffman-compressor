#include <iostream>
#include "Codec.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto com =Codec::compress("aaaaaaaaaabcccccccccccccccddddddd");
    auto cc = Codec::decompress(com);
    return 0;
}
