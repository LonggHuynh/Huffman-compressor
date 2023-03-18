

#include <algorithm>
#include "Utils.h"

int Utils::bitLength(int num) {
    int length = 0;
    for (; num;  num >>= 1) {
        length++;
    }
    return std::max(length, 1);
}