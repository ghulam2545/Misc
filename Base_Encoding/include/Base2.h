#ifndef BASE_2_H
#define BASE_2_H
#include <bitset>
#include <cstdint>
#include <string>
#include <vector>

namespace Base2 {
    /**
     * @brief this function is used to convert data to binary form
     *
     * @param[in] data the data that has to be convert
     *
     * @return converted data is retured in the form of binary
     */
    std::bitset<8> Encode(const uint8_t &data);

    /**
     * @brief this function is used to convert data to binary form
     *
     * @param[in] data the data that has to be convert
     */
    void Encode(const std::vector<uint8_t> &data);

    /**
     * @brief this function is used to convert data to binary form
     *
     * @param[in] data the data that has to be convert
     */
    void Encode(const std::string &data);

    // helper
    void clearFile();
}  // namespace Base2

#endif