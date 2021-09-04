#include <iostream>
#include <vector>

#include "Large_Num.h"

int main() {
    std::cout << "Hello Test\n";

    std::string a = "1234";
    std::string b = "1234";

    std::string s = num::num::max(a, b);
    std::cout << s;

    return EXIT_SUCCESS;
}