#include <iostream>
#include <vector>

#include "Large_Num.h"

int main() {
    std::cout << "Hello Test\n";
    std::cout << "-------------------------------\n\n";

    std::string a = "112233445566778899000000000";
    std::string b = "900000000000000000123456789";
    number::number aa;

    std::cout << aa.max(a, b) << "\n\n";

    std::cout << aa.min(a, b) << "\n\n";

    std::cout << aa.add(a, b) << "\n\n";

    std::cout << aa.substract(a, b) << "\n\n";

    return EXIT_SUCCESS;
}