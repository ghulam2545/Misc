#include "../include/Base2.h"

#include <bits/basic_string.h>

#include <bitset>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>

namespace Base2 {
    std::ofstream file("data.txt", std::ios::app);

    std::bitset<8> Encode(const uint8_t &data) {
        std::bitset<8> result = std::bitset<8>(data);
        file << result;
        file.close();
        return result;
    }

    void Encode(const std::vector<uint8_t> &data) {
        for (auto e : data) {
            std::bitset<8> result = std::bitset<8>(e);
            file << result;
        }
        file.close();
    }

    void Encode(const std::string &data) {
        std::bitset<8> result;
        for (int i = 0; i < data.size(); ++i) {
            result = std::bitset<8>(data[i]);
            file << result;
        }
        file.close();
    }

    void clearFile() {}

}  // namespace Base2