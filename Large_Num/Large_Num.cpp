#include "Large_Num.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>

namespace number {

number::number() {
    _size_of_num1 = 0;
    _size_of_num2 = 0;
    __result = "";
}

std::string number::max(std::string& __num1, std::string& __num2) {
    __result = "";
    _size_of_num1 = __num1.size();
    _size_of_num2 = __num2.size();

    bool _boht_are_same = true;
    bool _num1_is_greater = false;
    bool _num2_is_greater = false;

    if (_size_of_num1 > _size_of_num2) {
        //  num1 has max length
        for (int i = 0; i < _size_of_num1; i++) {
            __result += __num1[i];
        }
        return __result;
    } else if (_size_of_num2 > _size_of_num1) {
        // num2 has max length
        for (int i = 0; i < _size_of_num2; i++) {
            __result += __num2[i];
        }
        return __result;
    } else {
        // both has same length
        for (int i = 0; i < _size_of_num1; i++) {
            if (__num1[i] - '0' > __num2[i] - '0') {
                _num1_is_greater = true;
                break;
            } else if (__num2[i] - '0' > __num1[i] - '0') {
                _num2_is_greater = true;
                break;
            }
        }
    }

    if (_num1_is_greater) {
        for (int i = 0; i < _size_of_num1; i++) {
            __result += __num1[i];
        }
        return __result;
    } else if (_num2_is_greater) {
        for (int i = 0; i < _size_of_num2; i++) {
            __result += __num2[i];
        }
        return __result;
    } else {
        return "Both are same";
    }
}

std::string number::min(std::string& __num1, std::string& __num2) {
    __result = "";
    std::string __s = max(__num1, __num2);
    __result = "";
    if (__s == "Both are same") {
        return "Both are same";
    } else if (__s == __num1) {
        return __num2;
    } else {
        return __num1;
    }
}

// Alert : This also erased the input data.
std::string number::add(std::string __num1, std::string __num2) {
    __result = "";
    _size_of_num1 = __num1.size();
    _size_of_num2 = __num2.size();

    int __carry = 0;
    while (!(__num1.empty() || __num2.empty())) {
        int __a = __num1.back() - '0';
        __num1.pop_back();
        int __b = __num2.back() - '0';
        __num2.pop_back();
        int __data = __a + __b + __carry;
        __carry = 0;

        __result.push_back(__data % 10 + '0');
        __carry = __data / 10;
    }

    // If both have same lenth there may be a last carry
    if (_size_of_num1 == _size_of_num2) {
        if (__carry) {
            __result.push_back(__carry + '0');
        }
    } else {  // both are diff length
        if (__carry) {
            if (_size_of_num1 > _size_of_num2) {
                for (int i = (_size_of_num1 - _size_of_num2 - 1); i >= 0; i--) {
                    __result.push_back((__num1[i] - '0') + (__carry + '0'));
                    __carry = 0;
                }
            } else {
                for (int i = (_size_of_num2 - _size_of_num1 - 1); i >= 0; i--) {
                    __result.push_back((__num2[i] - '0') + (__carry + '0'));
                    __carry = 0;
                }
            }
        } else {
            if (_size_of_num1 > _size_of_num2) {
                for (int i = (_size_of_num1 - _size_of_num2 - 1); i >= 0; i--) {
                    __result.push_back(__num1[i]);
                }
            } else {
                for (int i = (_size_of_num2 - _size_of_num1 - 1); i >= 0; i--) {
                    __result.push_back(__num2[i]);
                }
            }
        }
    }

    reverse(__result.begin(), __result.end());

    return __result;
}

std::string number::substract(std::string& __num1, std::string& __num2) {
    __result = "";
    int diff = _size_of_num1 - _size_of_num2;
    for (int i = 0; i < diff; i++) {
        __num2 = "0" + __num2;
    }
    std::string tt = compliment_of_10(__num2);
    __result = add(__num1, tt);
    if (__result.size() > __num1.size()) {
        auto it = __result.begin();
        __result.erase(it);
        it = __result.begin();
        while (*it == '0') {
            __result.erase(it);
        }
        return __result;
    } else {
        return compliment_of_10(__result);
    }
}

std::string number::multiply(std::string& __num1, std::string& __num2) {
    __result = "";
    // considering all are zero
    bool n1_zeros = true;
    bool n2_zeros = true;
    for (int i = 0; i < __num1.size(); i++) {
        if (__num1[i] != '0') {
            n1_zeros = false;
        }
    }
    for (int i = 0; i < __num2.size(); i++) {
        if (__num2[i] != '0') {
            n2_zeros = false;
        }
    }
    if (n1_zeros == true || n2_zeros == true) {
        return "0";
    }

    _size_of_num2 = __num2.size();
    std::string _append_ = "0";
    std::string toPass = "";
    toPass.push_back(__num2.back());
    std::string __ans = mult(__num1, toPass);
    std::string __temp_ans = "";
    for (int i = _size_of_num2 - 2; i >= 0; i--) {
        toPass = __num2[i];
        __temp_ans = mult(__num1, toPass);
        __temp_ans += _append_;
        _append_ += "0";
        __ans = add(__ans, __temp_ans);
    }

    return __ans;
}

std::string number::divide(std::string& __num1, std::string& __num2) {
    return "abc";
}

std::string number::compliment_of_10(std::string& __input) {
    std::string __ans = "";
    for (int i = 0; i < __input.size(); i++) {
        __ans += '9' - __input[i] + '0';
    }
    std::string tt = "1";
    __ans = add(__ans, tt);
    return __ans;
}

std::string number::mult(std::string __num1, std::string __num2) {
    __result = "";
    if (__num2[0] - '0' == 0) return "0";
    int __carry = 0;
    int temp;
    for (int i = __num1.size() - 1; i >= 0; i--) {
        temp = ((__num2[0] - '0') * (__num1[i] - '0')) + __carry;
        __carry = 0;
        __result.push_back((temp % 10) + '0');
        __carry = temp / 10;
    }
    if (__carry) {
        __result.push_back(__carry + '0');
    }

    reverse(__result.begin(), __result.end());
    return __result;
}

}  // namespace number
