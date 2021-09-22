#include <iostream>

#include "include/String_Ext.h"

int main() {
    const char *s =
        "this is line 1\nthis is a new line\n"
        "this is line 2\n"
        "this is line 3\n";
    std::cout << String_Ext::indent(s, 4);

    return EXIT_SUCCESS;
}