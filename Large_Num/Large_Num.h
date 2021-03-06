#ifndef LARGE_NUM_H
#define LARGE_NUM_H

#include <string>

namespace number {

struct member {
    int _size_of_num1;
    int _size_of_num2;
    std::string __result;

    bool __num1_is_positive;
    bool __num2_is_positive;
};

struct number : public member {
    // making members as their default value
    number();

    // returns max value of both number
    std::string max(std::string& __num1, std::string& __num2);

    // returns min value of both number
    std::string min(std::string& __num1, std::string& __num2);

    // for adding
    std::string add(std::string __num1, std::string __num2);

    // for substracting
    std::string substract(std::string& __num1, std::string& __num2);

    // for multiplying
    std::string multiply(std::string& __num1, std::string& __num2);

    // for dividing
    std::string divide(std::string& __num1, long long& __num2);

    // Some helper methods
    std::string compliment_of_10(std::string& __input);
    std::string mult(std::string& __num1, std::string& __num2);
    void action(std::string __num1, std::string __num2, std::string __method);
};

}  // namespace number

#endif