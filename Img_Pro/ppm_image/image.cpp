#include "image.hpp"

namespace gh {

    bool ascii::write_pbm(const string& filename) {
        ofstream ofs;
        ofs.open(filename);

        ofs << "P1\n";
        ofs << WIDTH << ' ' << HEIGHT << '\n';

        if (ofs.is_open()) {
            for (size_t rows = 0; rows < HEIGHT; ++rows) {
                for (size_t cols = 0; cols < WIDTH; ++cols) {
                    ofs << 0 << ' ';  // only 2 pixels are supported. 0 for white & 1 for black
                }
                ofs << '\n';
            }
        } else {
            fprintf(stderr, "ERROR: Could not write to file \"%s\"", filename.c_str());
            return false;
        }

        ofs.close();
        return true;
    }

    bool ascii::read_pbm(const string& filename) {
        ifstream ifs;
        ifs.open(filename);

        vector<uint8_t> pixels{};
        uint8_t in{};

        if (ifs.is_open()) {
            while (ifs.eof() == false) {
                ifs >> noskipws >> in;  // noskipws == also don't skip any non-printable chars
                pixels.push_back(in);
            }
        } else {
            fprintf(stderr, "ERROR: Could not read from file \"%s\"", filename.c_str());
            return false;
        }

        ifs.close();

        // data are stored in pixels array
        //  re-writing to defferent file
        ofstream ofs;
        ofs.open("out.pbm");
        for (auto& e : pixels) ofs << e;
        ofs.close();

        return true;
    }

    bool ascii::write_pgm(const string& filename) {
        ofstream ofs;
        ofs.open(filename);

        ofs << "P2\n";
        ofs << WIDTH << ' ' << HEIGHT << '\n';
        ofs << "255\n";  // max color value

        if (ofs.is_open()) {
            for (size_t rows = 0; rows < HEIGHT; ++rows) {
                for (size_t cols = 0; cols < WIDTH; ++cols) {
                    ofs << 90 << ' ';  // only grayscale (0-255) color pixels are supported.
                }
                ofs << '\n';
            }
        } else {
            fprintf(stderr, "ERROR: Could not write to file \"%s\"", filename.c_str());
            return false;
        }

        ofs.close();
        return true;
    }

    bool ascii::read_pgm(const string& filename) {
        ifstream ifs;
        ifs.open(filename);

        vector<uint8_t> pixels{};
        uint8_t in{};

        if (ifs.is_open()) {
            while (ifs.eof() == false) {
                ifs >> noskipws >> in;  // noskipws == also don't skip any non-printable chars
                pixels.push_back(in);
            }
        } else {
            fprintf(stderr, "ERROR: Could not read from file \"%s\"", filename.c_str());
            return false;
        }

        ifs.close();

        // data are stored in pixels array
        //  re-writing to defferent file
        ofstream ofs;
        ofs.open("out.pgm");
        for (auto& e : pixels) ofs << e;
        ofs.close();

        return true;
    }

    bool binary::write_ppm(const string& filename) {
        ofstream ofs;
        ofs.open(filename, ios::binary);

        ofs << "P6\n";
        ofs << WIDTH << ' ' << HEIGHT << '\n';
        ofs << "255\n";

        if (ofs.is_open()) {
            for (size_t rows = 0; rows < HEIGHT; ++rows) {
                for (size_t cols = 0; cols < WIDTH; ++cols) {
                    ofs << (uint8_t)0 << (uint8_t)0 << (uint8_t)255;  // rgb colors
                }
            }
        } else {
            fprintf(stderr, "ERROR: Could not write to file \"%s\"", filename.c_str());
            return false;
        }

        ofs.close();
        return true;
    }

    bool binary::read_ppm(const string& filename) {
        ifstream ifs;
        ifs.open(filename);

        vector<uint8_t> pixels{};
        uint8_t in{};

        if (ifs.is_open()) {
            while (ifs.eof() == false) {
                ifs >> noskipws >> in;  // noskipws == also don't skip any non-printable chars
                pixels.push_back(in);
            }
        } else {
            fprintf(stderr, "ERROR: Could not read from file \"%s\"", filename.c_str());
            return false;
        }

        ifs.close();

        // data are stored in pixels array
        //  re-writing to defferent file
        ofstream ofs;
        ofs.open("gardient_out.ppm");
        for (auto& e : pixels) ofs << e;
        ofs.close();

        return true;
    }

}
