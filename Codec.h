#ifndef COMPRESSOR_CODEC_H
#define COMPRESSOR_CODEC_H

#include <string>

namespace Codec {

    std::string compress(const std::string& input);
    std::string decompress(const std::string& input);

};

#endif //COMPRESSOR_CODEC_H
