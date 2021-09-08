#include <iostream>
#include <vector>

#include "Large_Num.h"

int main() {
    std::cout << "Hello Test\n";
    std::cout << "-------------------------------\n\n";

    // Do not provide wrong input, I am not checking correctness
    std::string a = "903644476236474647";
    std::string b = "764563443444336443";
    number::number aa;

    std::cout << "max (a,b) --  : ";
    std::cout << aa.max(a, b) << "\n\n";

    std::cout << "min (a,b) --  : ";
    std::cout << aa.min(a, b) << "\n\n";

    std::cout << "add (a+b) --  : ";
    std::cout << aa.add(a, b) << "\n\n";

    std::cout << "substract (a-b) --  : ";
    std::cout << aa.substract(a, b) << "\n\n";

    std::cout << "multiply (a*b) --  : ";
    std::cout << aa.multiply(a, b) << "\n\n";

    std::cout << "divide (a/b) --  : ";
    long long _b = 564324;
    std::cout << aa.divide(a, _b);

    return EXIT_SUCCESS;
}