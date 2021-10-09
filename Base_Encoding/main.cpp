#include <bitset>
#include <fstream>
#include <ios>
#include <iostream>

#include "include/Base2.h"
#include "include/Base64.h"

int main() {
    char ch = (char)12;
    std::vector<char> v{'a', 'b', 'c'};
    std::string ss = "Lord";
    std::string ans;

    ans = Base2::Encode(ch);
    Base2::EncodeInFile(ch);
    std::cout << ans << "\n";

    ans = Base2::Encode(v);
    Base2::EncodeInFile(v);
    std::cout << ans << "\n";

    ans = Base2::Encode(ss);
    Base2::EncodeInFile(ss);
    std::cout << ans << "\n";

    return EXIT_SUCCESS;
}