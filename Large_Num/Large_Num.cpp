#include "Large_Num.h"

#include <algorithm>
#include <iostream>
#include <string>

namespace number {
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

std::string number::add(std::string& __num1, std::string& __num2) {
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
    std::cout << __num1 << "  " << __num2 << "\n\n";
    return "done";

    /*
    std::string __max_val = max(__num1, __num2);
    std::string __min_val = min(__num1, __num2);
    if (__max_val == __min_val) {
        return "0";
    }
    // _size_of_num1 = __num1.size();
    // _size_of_num2 = __num2.size();

    int diff = _size_of_num1 - _size_of_num2;
    int __carry = 0;
    for (int i = _size_of_num2 - 1; i >= 0; i--) {
        int __sub = ((__num1[i + diff] - '0') - (__num2[i] - '0') - __carry);
        if (__sub < 0) {
            __sub += 10;
            __carry = 1;
        } else {
            __carry = 0;
        }
        __result.push_back(__sub + '0');
    }
    for (int i = _size_of_num1 - _size_of_num2 - 1; i >= 0; i--) {
        if (__num1[i] == '0' && __carry) {
            __result.push_back('9');
            continue;
        }
        int __sub = ((__num1[i] - '0') - __carry);
        if (i > 0 || __sub > 0) {
            __result.push_back(__sub + '0');
        }
        __carry = 0;
    }

    reverse(__result.begin(), __result.end());

    return __result;

    */
}

}  // namespace number
