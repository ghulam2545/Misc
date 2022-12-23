#include <iostream>

#include "image.hpp"
using namespace std;

int main() {
    using namespace gh;

    const string filename = "pmb_img.pbm";
    const string filename1 = "pgm_img.pgm";
    const string filename2 = "ppm_img.ppm";
    const string filename3 = "gradient_in.ppm";

    ascii aa;
    binary bb;
    cout << boolalpha << aa.write_pbm(filename) << '\n';
    cout << boolalpha << aa.read_pbm(filename) << '\n';

    cout << boolalpha << aa.write_pgm(filename1) << '\n';
    cout << boolalpha << aa.read_pgm(filename1) << '\n';

    cout << boolalpha << bb.write_ppm(filename2) << '\n';
    cout << boolalpha << bb.read_ppm(filename3) << '\n';

    cout << "success\n";

    return 0;
}