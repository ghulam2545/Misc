#include <fstream>
#include <iostream>

#include "include/String_Ext.h"

int main() {
    std::ifstream in("test.txt");
    if (!in) {
        std::cerr << "some error";
    }
    std::string s;
    char ch = 0;
    while (in.get(ch)) {
        if (!(ch == '\n')) s += ch;
    }
    std::cout << String_Ext::colonIndent(s);

    // const char *s =
    //     "this is line 1:this is a new line:"
    //     "this is line 2:"
    //     "this is line 3:";
    // std::string aa = s;
    // std::cout << String_Ext::pythonStyleIndent(aa);

    return EXIT_SUCCESS;
}