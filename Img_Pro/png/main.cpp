#include <fstream>
#include <iostream>
using namespace std;

const auto width = 400;
const auto height = 400;

int main() {
    ofstream ofs("out.ppm", ios::binary);

    ofs << "P6\n";
    ofs << width << ' ' << height << '\n';
    ofs << "255\n";

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            ofs << 255 << 0 << 0 << '\n';
        }
    }

    ofs.close();

    return 0;
}