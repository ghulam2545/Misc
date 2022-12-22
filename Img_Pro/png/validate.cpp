#include <fstream>
#include <iostream>
using namespace std;

const auto PNG_SIGN_SIZE = 8;
const uint8_t PNG_SIGN_BUFFER[] = {137, 80, 78, 71, 13, 10, 26, 10};

bool validate(const string& filename) {
    ifstream ifs;
    ifs.open(filename, ios::binary);
    bool is_valid = true;

    if (ifs.is_open()) {
        uint8_t buffer[PNG_SIGN_SIZE]{};

        ifs.read((char*)buffer, PNG_SIGN_SIZE);

        for (int i = 0; i < PNG_SIGN_SIZE; ++i) {
            if (buffer[i] != PNG_SIGN_BUFFER[i]) {
                is_valid = false;
                break;
            }
        }

    } else {
        printf("ERROR: Could not read <%s>.\n", filename.c_str());
        is_valid = false;
    }

    // uint8_t len[4];
    // ifs.read((char*)len, 4);
    // for (int i = 0; i < 4; ++i) printf("%x ", len[i]);

    uint32_t len{};
    ifs.read((char*)len, sizeof(len));

    ifs.close();
    return is_valid;
}

int main() {
    string filename = "baby.png";
    auto res = validate(filename);

    cout << boolalpha << res;

    return 0;
}