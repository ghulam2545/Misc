#ifndef LARGE_NUM_H
#define LARGE_NUM_H

#include <string>
#include <vector>

namespace num {
static int _size_of_input;

static std::vector<int> _num1_;
static std::vector<int> _num2_;
static int _size_of_num1;
static int _size_of_num2;

static std::vector<int> __ans;
static std::string __result = "";

class num {
   private:
   public:
    // Convert string to array of interger
    static std::vector<int> _convert_in_array(std::string& __input);

    // for adding
    static std::string add(std::string& __num1, std::string& __num2);

    // for substracting
    static std::string substract(std::string& __num1, std::string& __num2);

    // returns max val
    static std::string max(std::string& __num1, std::string& __num2);

    // returns min val
    static std::string min(std::string& __num1, std::string& __num2);
};
}  // namespace num

#endif