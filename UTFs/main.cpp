#include <bitset>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

#include "../UTFs/utf8/utf8.hpp"
using namespace std;

int main() {
    string str = "This is an statement.";
    vector<uint32_t> input;
    for (int i = 0; i < str.size(); ++i) {
        input.push_back((uint32_t)str[i]);
    }
    vector<uint8_t> output = utf8::utf8::encode(input);
    for (auto e : input) {
        printf("0x%x ", e);
    }

    return 0;
}
