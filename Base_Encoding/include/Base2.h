#ifndef BASE_2_H
#define BASE_2_H
#include <bitset>
#include <cstdint>
#include <string>
#include <vector>

namespace Base2 {

    /**
     * @brief this function is used to convert data into binary form
     *
     * @param[in] data the data that has to be convert
     *
     * @return converted data in the form of binary is returned
     */
    std::string Encode(const char& data);

    /**
     * @brief this function is used to convert data into binary form and writes that in a file
     *
     * @param[in] data the data that has to be convert
     *
     */
    void EncodeInFile(const char& data);

    /**
     * @brief this function is used to convert data into binary form
     *
     * @param[in] data the data that has to be convert
     *
     * @return converted data in the form of binary is returned
     */
    std::string Encode(const std::vector<char>& data);

    /**
     * @brief this function is used to convert data into binary form and writes that in a file
     *
     * @param[in] data the data that has to be convert
     *
     */
    void EncodeInFile(const std::vector<char>& data);

    /**
     * @brief this function is used to convert data into binary form
     *
     * @param[in] data the data that has to be convert
     *
     * @return converted data in the form of binary is returned
     *
     */
    std::string Encode(const std::string& data);

    /**
     * @brief this function is used to convert data to binary form and writes that in a file
     *
     * @param[in] data the data that has to be convert
     */
    void EncodeInFile(const std::string& data);

}  // namespace Base2

#endif