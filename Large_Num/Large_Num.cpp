#include "Large_Num.h"

#include <iostream>
#include <string>

namespace num {

std::vector<int> num::_convert_in_array(std::string &__input) {
    std::vector<int> __temp;
    _size_of_input = __input.size();
    for (int i = 0; i < _size_of_input; i++) {
        __temp.push_back(__input[i] - '0');
    }
    return __temp;
}

std::string num::add(std::string &__num1, std::string &__num2) {
    _num1_ = _convert_in_array(__num1);
    _num2_ = _convert_in_array(__num2);
    _size_of_num1 = _num1_.size();
    _size_of_num2 = _num2_.size();

    int __remainder = 0;
    while (!(_num1_.empty() || _num2_.empty())) {
        int __a = _num1_.back();
        _num1_.pop_back();
        int __b = _num2_.back();
        _num2_.pop_back();
        int __data = __a + __b + __remainder;
        __remainder = 0;

        __ans.push_back(__data % 10);
        __remainder = __data / 10;
    }

    // If both have same number there may be a last remainder
    if (_size_of_num1 == _size_of_num2) {
        if (__remainder) {
            __ans.push_back(__remainder);
        }
    } else {
        if (__remainder) {
            if (_size_of_num1 > _size_of_num2) {
                for (int i = (_size_of_num1 - _size_of_num2 - 1); i >= 0; i--) {
                    __ans.push_back(_num1_[i] + __remainder);
                    __remainder = 0;
                }
            } else {
                for (int i = (_size_of_num2 - _size_of_num1 - 1); i >= 0; i--) {
                    __ans.push_back(_num2_[i] + __remainder);
                    __remainder = 0;
                }
            }
        } else {
            if (_size_of_num1 > _size_of_num2) {
                for (int i = (_size_of_num1 - _size_of_num2 - 1); i >= 0; i--) {
                    __ans.push_back(_num1_[i]);
                }
            } else {
                for (int i = (_size_of_num2 - _size_of_num1 - 1); i >= 0; i--) {
                    __ans.push_back(_num2_[i]);
                }
            }
        }
    }

    for (int e = __ans.size() - 1; e >= 0; e--) {
        __result += std::to_string(__ans[e]);
    }

    return __result;
}

std::string num::substract(std::string &__num1, std::string &__num2) {
    // Has to imp
    return "abc";
}

std::string num::max(std::string &__num1, std::string &__num2) {
    _size_of_num1 = __num1.size();
    _size_of_num2 = __num2.size();

    std::cout << _size_of_num1 << "\n" << _size_of_num2 << "\n\n";

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

std::string num::min(std::string &__num1, std::string &__num2) {
    // has to imp
    return "abc";
}

}  // namespace num
