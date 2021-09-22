#include "../include/String_Ext.h"

#include <iostream>

namespace String_Ext {
const std::string trim(const std::string &s) {
    size_t i = 0;
    size_t j = s.size();
    while (i < s.size() && s[i] <= 32) {
        ++i;
    }
    while (j >= 0 && s[j - 1] <= 32) {
        --j;
    }
    return s.substr(i, j - i);
}

std::string indent(std::string linesIn, size_t spaces) {
    std::string linesOut;
    while (!linesIn.empty()) {
        std::string line;
        auto delimiter = linesIn.find("\n");
        if (delimiter == std::string::npos) {
            line = linesIn;
            linesIn.clear();
        } else {
            line = linesIn.substr(0, delimiter + 1);
            linesIn = linesIn.substr(delimiter + 1);
        }
        if (!linesOut.empty()) {
            linesOut.append(spaces, ' ');
        }
        linesOut += line;
    }
    return linesOut;
}

}  // namespace String_Ext