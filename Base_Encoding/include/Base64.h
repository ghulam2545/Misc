#ifndef BASE_64_H
#define BASE_64_H
#include <cstdint>
#include <string>
#include <vector>

namespace Base64 {
    /**
     * @brief This method encodes the provided data in base64 using base64 algorithm
     *
     * @param[in] data The data that we have to encode
     *
     * @return The Base64 encoding of the given data is returned.
     */
    std::string Encode(const std::vector<uint8_t> &data);

    /**
     * @brief This method encodes the provided data in base64 using base64 algorithm
     *
     * @param[in] data The data that we have to encode
     *
     * @return The Base64 encoding of the given data is returned.
     */
    std::string Encode(const std::string &data);

    /**
     * @brief This method decodes the provided data in base64 using base64 algorithm
     *
     * @param[in] data The data that we have to edecode
     *
     * @return The Base64 decoding of the given data is returned.
     */
    std::string Decode(const std::vector<uint8_t> &data);

    /**
     * @brief This method decodes the provided data in base64 using base64 algorithm
     *
     * @param[in] data The data that we have to decodes
     *
     * @return The Base64 decoding of the given data is returned.
     */
    std::string Decode(const std::string &data);

}  // namespace Base64
#endif