#include <iostream>

#include "include/Base64.h"

int main() {
    std::string name = "these all are very usefull";

    std::string ans = Base64::Encode(name);
    std::cout << ans << "\n";
    ans = Base64::Decode(ans);
    std::cout << ans << "\n";

    return EXIT_SUCCESS;
}