#include <bitset>
#include <fstream>
#include <ios>
#include <iostream>

#include "include/Base2.h"
#include "include/Base64.h"

int main() {
    // simultenous call not working...WHY

    // char ch = 'Z';
    // std::bitset<8> ans = Base2::Encode(ch);
    // std::cout << ans << "\n";
    std::string s = "kingdom is very huge";
    // Base2::Encode(std::vector<uint8_t>(s.begin(), s.end()));
    Base2::Encode(s);

    return EXIT_SUCCESS;
}