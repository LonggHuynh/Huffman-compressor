#ifndef COMPRESSOR_CODEC_H
#define COMPRESSOR_CODEC_H



#include <string>
#include <array>
#include <vector>


namespace Codec {

    std::vector<bool> compress(const std::string &input);

    std::string decompress(const std::vector<bool> &input);

};

#endif //COMPRESSOR_CODEC_H
