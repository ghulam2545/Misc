#ifndef STRING_EXT_H
#define STRING_EXT_H

#include <cstring>
#include <iostream>
#include <vector>

namespace String_Ext {

// it removes all unnecessary space from begin and end
const std::string trim(const std::string &s);

// indent string by specified space except first line ("\n" as new line terminator)
std::string indent(std::string linesIn, size_t spaces);

// colon indent (":" as new line terminator)
const std::string colonIndent(const std::string &s);

// convert complete sentence in vector<string> (usually for space sepration)
const std::vector<std::string> split(const std::string &s, const char &ch);

// for now I am not implementing this
// const std::vector<std::string> split(const std::string &actualStr, const std::string &delimiterStr);

// transform string in lowercase
const std::string lower(const std::string &s);

// transform string in uppercase
const std::string upper(const std::string &s);

// concatenate vector<string> and provided char in a single string
const std::string join(const std::vector<std::string> &s, const char &ch);

// concatenate vector<string> and provided string in a single string
const std::string join(const std::vector<std::string> &s, const std::string &delimiterStr);

}  // namespace String_Ext

#endif