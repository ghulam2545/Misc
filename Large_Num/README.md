# Large Number in C++
<i>This is a mini library to deal with very large number in c++. Since standered type can store max value in uint64_t rather than all will go overflow.This one is written very straight forward to do basic arithmetic on large number.</i>

## Details    ----------(*do more improvement)
There are 3 files.
1. main.cpp  (having main method)
2. Large_Num.h  (declarion of all function)
3. Large_Num.cpp (implementation of all function)

-- <b>How to instantiate and call</b>

number::number instance_name;

instance_name.add(a, b); // equilent to a+b <br>
instance_name.substract(a, b); // equilent to a-b <br>
instance_name.multiply(a, b); // equilent to a*b <br>
instance_name.divide(a, b); // equilent to a/b <br>
instance_name.max(a, b); <br>
instance_name.min(a, b); <br>

where a, b are reference of std::string (see header file)


