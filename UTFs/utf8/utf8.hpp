#ifndef UTF8_HPP
#define UTF8_HPP

#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

namespace utf8 {
    class utf8 {
       public:
        static size_t tellOctet(uint32_t unicodeCodePoint);
        static std::vector<uint8_t> encode(const std::vector<uint32_t>& unicodeCodePoint);
        static std::vector<uint32_t> decode(const std::vector<uint8_t>& code);
    };
}  // namespace utf8

#endif