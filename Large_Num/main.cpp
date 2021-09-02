#include <iostream>
#include <vector>
#include "Large_Num.h"

int main() {
    std::cout<<"Hello Test\n";

    std::string a = "1000000000";
    std::string b = "123456789";
    
    std::string s = num::num::add(a, b);
    std::cout<<s;

    return EXIT_SUCCESS;
}