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
        auto position = linesIn.find("\n");  // no further "\n"
        if (position == std::string::npos) {
            line = linesIn;
            linesIn.clear();
        } else {
            line = linesIn.substr(0, position + 1);
            linesIn = linesIn.substr(position + 1);
        }
        if (!linesOut.empty()) {  // working for indent except first line
            linesOut.append(spaces, ' ');
        }
        linesOut += line;
    }
    return linesOut;
}

std::string colonIndent(std::string &s) {
    std::string out;
    size_t spaces = 4;
    bool colon = false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!colon) {
            out += s[i];
        }
        if (colon) {
            if (s[i] != ' ') {
                colon = false;
                out += s[i];
            }
        }
        if (s[i] == ':') {
            colon = true;
            if (!out.empty()) {
                out.push_back('\n');
                out.append(spaces, ' ');
                spaces += 4;
            }
        }
    }
    return out;
}

}  // namespace String_Ext