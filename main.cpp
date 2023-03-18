#include <iostream>
#include "Codec.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Codec::compress("aaaaaaaaaabcccccccccccccccddddddd");
    return 0;
}
