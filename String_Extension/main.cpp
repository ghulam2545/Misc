#include <fstream>
#include <iostream>

#include "include/String_Ext.h"

int main() {
    std::string ans = "an333sWEr";
    std::cout << String_Ext::lower(ans) << "\n";
    std::cout << String_Ext::upper(ans);

    // std::vector<std::string> aa = {"nadeem", "saleem", "karee", "jameel"};
    // std::string de = " bhai\n";
    // std::cout << String_Ext::join(aa, de);
    // std::vector<std::string> aa = {"manuu", "is", "a", "central", "university"};
    // std::cout << String_Ext::join(aa, 'X');

    // std::ifstream in("test.txt");
    // if (!in) {
    //     std::cerr << "some error";
    // }
    // std::string s;
    // char ch = 0;
    // while (in.get(ch)) {
    //     if (ch != '\n') s += ch;
    // }
    // std::cout << s << "\n\n";
    // std::vector<std::string> tt = String_Ext::split(s);
    // for (auto& e : tt) std::cout << e << "\n";
    // std::cout << String_Ext::colonIndent(s);

    // const char *s =
    //     "this is line 1:this is a new line:\n"
    //     "this is line 2:\n"
    //     "this is line 3:\n";
    // std::string aa = s;
    // std::cout << String_Ext::indent(aa, 8);

    return EXIT_SUCCESS;
}