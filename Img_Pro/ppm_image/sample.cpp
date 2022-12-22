#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct vec3f {
    vec3f() {}
    vec3f(float r, float g, float b) {
        red = r;
        green = g;
        blue = b;
    }

    float red;
    float green;
    float blue;
};

int main() {
    const auto width = 500;
    const auto height = 500;

    vector<vec3f> pixel(width * height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixel[i + j * width].red = 100.f;
            pixel[i + j * width].red = i + 1 / float(width);
            pixel[i].red = 0.f;
        }
    }

    ofstream ofs;
    ofs.open("./name.ppm");
    ofs << "P6\n" << width << ' ' << height << "\n255\n";

    for (size_t i = 0; i < height * width; ++i) {
        for (size_t j = 0; j < 3; j++) {
            ofs << (char)(pixel[i].red);
            ofs << (char)(pixel[i].green);
            ofs << (char)(pixel[i].blue);
        }
    }

    ofs.close();
    cout << "Image creation successfull.\n";

    return 0;
}