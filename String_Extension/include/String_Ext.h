#ifndef STRING_EXT_H
#define STRING_EXT_H

#include <iostream>

namespace String_Ext {

// it removes all unnecessary space from begin and end
const std::string trim(const std::string &s);

// indent string by specified space except first line ("\n" as new line terminator)
std::string indent(std::string linesIn, size_t spaces);

// colon indent (":" as new line terminator)
std::string colonIndent(std::string &s);

}  // namespace String_Ext

#endif