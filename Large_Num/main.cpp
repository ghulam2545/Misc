#include <iostream>
#include <vector>

#include "Large_Num.h"

int main() {
    std::cout << "Hello Test\n";
    std::cout << "-------------------------------\n\n";

    std::string a = "12345334233242431433";
    std::string b = "12345334233242431432";
    number::number aa;

    // std::cout << aa.max(a, b) << "\n\n";

    // std::cout << aa.min(a, b) << "\n\n";

    // std::cout << aa.add(a, b) << "\n\n";

    // std::cout << aa.substract(a, b) << "\n\n";

    a = "000";
    b = "23123231";
    std::cout << aa.multiply(a, b);

    return EXIT_SUCCESS;
}