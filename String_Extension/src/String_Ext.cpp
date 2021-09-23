#include "../include/String_Ext.h"

#include <cstring>
#include <iostream>
#include <vector>

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

std::string indent(std::string linesInput, size_t spaces) {
    std::string linesOutput;
    while (!linesInput.empty()) {
        std::string line;
        auto position = linesInput.find("\n");
        if (position == std::string::npos) {  // no further "\n"
            line = linesInput;
            linesInput.clear();
        } else {
            line = linesInput.substr(0, position + 1);
            linesInput = linesInput.substr(position + 1);
        }
        if (!linesOutput.empty()) {  // working for indent except first line
            linesOutput.append(spaces, ' ');
        }
        linesOutput += line;
    }
    return linesOutput;
}

const std::string colonIndent(const std::string &s) {
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

const std::vector<std::string> split(const std::string &s) {
    std::vector<std::string> ans;
    std::string temp;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            temp += s[i];
        } else {
            ans.push_back(temp);
            temp = "";
        }
    }
    return ans;
}

const std::string lower(const std::string &s) {
    std::string ans;
    for (auto &e : s) {
        ans += tolower(e);
    }
    return ans;
}

const std::string upper(const std::string &s) {
    std::string ans;
    for (auto &e : s) {
        ans += toupper(e);
    }
    return ans;
}

}  // namespace String_Ext