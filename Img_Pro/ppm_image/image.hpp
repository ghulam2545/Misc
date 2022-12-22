#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const auto WIDTH = 400;
const auto HEIGHT = 400;

namespace gh {
    struct ascii {
        bool write_pbm(const string& filename);
        bool read_pbm(const string& filename);

        bool write_pgm(const string& filename);
        bool read_pgm(const string& filename);
    };

    struct binary {
        // TODO: more
        bool write_ppm(const string& filename);
    };
}

#endif