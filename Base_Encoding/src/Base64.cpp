#include "../include/Base64.h"

#include <cstdint>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

// This is helper namespace
namespace {
    /**
     * The only character which will be used for encoding (Base64)
     *  6 - bit of binary group will represent a single chararacter (including padding)
     */
    const char characters[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    /**
     * This table will map each character by its assigned value
     * Actually Base 64 algorithm
     */
    const std::map<char, size_t> charactersTable{
        {'A', 0},  {'B', 1},  {'C', 2},  {'D', 3},  {'E', 4},  {'F', 5},  {'G', 6},  {'H', 7},  {'I', 8},  {'J', 9},
        {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
        {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25}, {'a', 26}, {'b', 27}, {'c', 28}, {'d', 29},
        {'e', 30}, {'f', 31}, {'g', 32}, {'h', 33}, {'i', 34}, {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39},
        {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44}, {'t', 45}, {'u', 46}, {'v', 47}, {'w', 48}, {'x', 49},
        {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54}, {'3', 55}, {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59},
        {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63},
    };

    // main base64 encoding algorithm implementation
    std::string Encode(const std::vector<uint8_t>& data, const char* characters, const bool& padding) {
        std::ostringstream result;
        size_t bits = 0;
        uint32_t buffer = 0;
        for (auto in : data) {
            buffer <<= 8;
            buffer += (uint32_t)in;
            bits += 8;
            while (bits >= 6) {
                result << characters[(buffer >> (bits - 6)) & 0x3f];
                buffer &= ~(buffer << (bits - 6));
                bits -= 6;
            }
        }
        if ((data.size() % 3) == 1) {
            buffer <<= 4;
            result << characters[buffer & 0x3f];
            if (padding) {
                result << "==";
            }
        } else if ((data.size() % 3) == 2) {
            buffer <<= 2;
            result << characters[buffer & 0x3f];
            if (padding) {
                result << "=";
            }
        }
        return result.str();
    }

    // main base64 decoding algorithm implementation
    std::string Decode(const std::vector<uint8_t>& data, const std::map<char, size_t> charactersTable) {
        std::ostringstream result;
        uint32_t buffer = 0;
        size_t bits = 0;
        for (auto in : data) {
            const auto entry = charactersTable.find(in);
            uint32_t group = 0;
            if (entry != charactersTable.end()) {
                group = entry->second;
            }
            buffer <<= 6;
            bits += 6;
            buffer += group;
            if (bits >= 8) {
                if (in != '=') {
                    result << (char)(buffer >> (bits - 8));
                }
                buffer &= ~(0xff << (bits - 8));
                bits -= 8;
            }
        }
        return result.str();
    }
}  // namespace

namespace Base64 {
    std::string Encode(const std::vector<uint8_t>& data) { return ::Encode(data, characters, true); }

    std::string Encode(const std::string& data) { return Encode(std::vector<uint8_t>(data.begin(), data.end())); }

    std::string Decode(const std::vector<uint8_t>& data) { return ::Decode(data, charactersTable); }

    std::string Decode(const std::string& data) { return Decode(std::vector<uint8_t>(data.begin(), data.end())); }
}  // namespace Base64