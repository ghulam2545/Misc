#include "utf8.hpp"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

namespace utf8 {
    size_t utf8::tellOctet(uint32_t unicodeCodePoint) {
        size_t nOctet = 0;
        size_t nBit = 0;
        while (unicodeCodePoint) {
            ++nBit;
            unicodeCodePoint >>= 1;
        }
        if (nBit <= 7)
            nOctet = 1;
        else if (nBit <= 11)
            nOctet = 2;
        else if (nBit <= 16)
            nOctet = 3;
        else if (nBit <= 21)
            nOctet = 4;
        return nOctet;
    }
    std::vector<uint8_t> utf8::encode(const std::vector<uint32_t>& unicodeCodePoint) {
        std::vector<uint8_t> encodedAns;
        for (auto codePoint : unicodeCodePoint) {
            if (tellOctet(codePoint) == 1) {
                encodedAns.push_back(codePoint & 0x007f);
            } else if (tellOctet(codePoint) == 2) {
                encodedAns.push_back(((codePoint >> 6) & 0x1f) | 0xc0);
                encodedAns.push_back((codePoint & 0x3f) | 0x80);
            } else if (tellOctet(codePoint) == 3) {
                encodedAns.push_back(((codePoint >> 12) & 0x0f) | 0xe0);
                encodedAns.push_back(((codePoint >> 6) & 0x3f) | 0x80);
                encodedAns.push_back((codePoint & 0x3f) | 0x80);
            } else if (tellOctet(codePoint) == 4) {
                encodedAns.push_back(((codePoint >> 18) & 0x07) | 0xf0);
                encodedAns.push_back(((codePoint >> 12) & 0x3f) | 0x80);
                encodedAns.push_back(((codePoint >> 6) & 0x3f) | 0x80);
                encodedAns.push_back((codePoint & 0x3f) | 0x80);
            }
        }
        return encodedAns;
    }
    std::vector<uint32_t> utf8::decode(const std::vector<uint8_t>& code) {
        std::vector<uint32_t> output;
        // TODO :
    }
}  // namespace utf8
