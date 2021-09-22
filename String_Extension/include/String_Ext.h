#ifndef STRING_EXT_H
#define STRING_EXT_H

#include <iostream>

namespace String_Ext {

// it removes all unnecessary space from begin and end
const std::string trim(const std::string &s);

// write here
std::string indent(std::string linesIn, size_t spaces);

}  // namespace String_Ext

#endif