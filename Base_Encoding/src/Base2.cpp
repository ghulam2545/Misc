#include "../include/Base2.h"

#include <bits/basic_string.h>

#include <bitset>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>

namespace Base2 {
    std::ofstream file;
    std::bitset<8> value;
    std::string ans = "";

    std::string Encode(const char& data) {
        ans.clear();
        value = std::bitset<8>(data);
        ans = value.to_string();
        return ans;
    }

    void EncodeInFile(const char& data) {
        file.open("data.txt", std::ios::app);
        value = std::bitset<8>(data);
        file << value;
        file.close();
    }

    std::string Encode(const std::vector<char>& data) {
        ans.clear();
        for (size_t i = 0; i < data.size(); ++i) {
            value = std::bitset<8>(data[i]);
            ans += value.to_string();
        }
        return ans;
    }

    void EncodeInFile(const std::vector<char>& data) {
        file.open("data.txt", std::ios::app);
        for (size_t i = 0; i < data.size(); ++i) {
            value = std::bitset<8>(data[i]);
            file << value;
        }
        file.close();
    }

    std::string Encode(const std::string& data) { return Base2::Encode(std::vector<char>(data.begin(), data.end())); }

    void EncodeInFile(const std::string& data) {
        file.open("data.txt", std::ios::app);
        for (size_t i = 0; i < data.size(); ++i) {
            value = std::bitset<8>(data[i]);
            file << value;
        }
        file.close();
    }

}  // namespace Base2