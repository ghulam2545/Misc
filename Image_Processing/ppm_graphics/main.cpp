#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;

// interface.hpp
namespace gh {
    auto WIDTH = 400;
    auto HEIGHT = 400;

    struct vec2 {
        vec2();
        vec2(const float& xcoord, const float& ycoord);
        // more here

        float m_xcoord;
        float m_ycoord;
    };

    struct vec3 {
        vec3();
        vec3(const uint8_t& red, const uint8_t& green, const uint8_t& blue);
        // more here

        uint8_t m_red;
        uint8_t m_green;
        uint8_t m_blue;
    };

    vec3** pixels{nullptr};

    class Canvas {
       public:
        Canvas();
        Canvas(const size_t& width, const size_t& height, const vec3& bg_color);

        bool create(const size_t& width, const size_t& height, const vec3& bg_color);
        void save(const std::string& filename);
    };

    class Rectangle {
       public:
        Rectangle();
        Rectangle(const vec2& loc, const size_t& width, const size_t& height, const vec3& color);

        void draw(const vec2& loc, const size_t& width, const size_t& height, const vec3& color);

       private:
        vec2 m_origin;
        size_t m_width;
        size_t m_height;
    };

    class Circle {};

    class Line {};

    class Triangle {};
}

/**
 * @ main function
 *
 *
 */
int main() {
    cout << "Hello, World!\n";

    const auto default_color = gh::vec3(85, 85, 85);
    const auto red_color = gh::vec3(255, 0, 0);
    const auto green_color = gh::vec3(0, 255, 0);
    const auto blue_color = gh::vec3(0, 0, 255);
    string filename = "out.ppm";
    using namespace gh;

    Canvas my_canvas(400, 400, red_color);
    Rectangle rect(vec2{100, 100}, 200, 200, green_color);

    my_canvas.save(filename);

    cout << "success.\n";

    return 0;
}

// implementation.cpp
namespace gh {
    vec2::vec2() : m_xcoord{0}, m_ycoord{0} {}

    vec2::vec2(const float& xcoord, const float& ycoord) : m_xcoord{xcoord}, m_ycoord{ycoord} {}

    vec3::vec3() : m_red{0}, m_green{0}, m_blue{0} {}

    vec3::vec3(const uint8_t& red, const uint8_t& green, const uint8_t& blue)
        : m_red{red}, m_green{green}, m_blue{blue} {}

    Canvas::Canvas() {}

    Canvas::Canvas(const size_t& width, const size_t& height, const vec3& bg_color) {
        auto flag = create(width, height, bg_color);
        if (!flag) {
            std::cout << "canvas creation failed.\n";
        }
    }

    bool Canvas::create(const size_t& width, const size_t& height, const vec3& bg_color) {
        WIDTH = width;
        HEIGHT = height;

        pixels = new vec3*[HEIGHT];
        for (size_t i = 0; i < HEIGHT; ++i) {
            pixels[i] = new vec3[WIDTH];
        }

        if (pixels == nullptr) return false;

        for (size_t rows = 0; rows < HEIGHT; ++rows) {
            for (size_t cols = 0; cols < WIDTH; ++cols) {
                pixels[rows][cols].m_red = bg_color.m_red;
                pixels[rows][cols].m_green = bg_color.m_green;
                pixels[rows][cols].m_blue = bg_color.m_blue;
            }
        }

        return true;
    }

    void Canvas::save(const std::string& filename) {
        std::ofstream ofs;
        ofs.open(filename, std::ios::binary);

        ofs << "P6\n";
        ofs << WIDTH << ' ' << HEIGHT << '\n';
        ofs << "255\n";

        // for (size_t rows = 0; rows < HEIGHT; ++rows) {
        //     for (size_t cols = 0; cols < WIDTH; ++cols) {
        //         ofs << pixels[rows][cols].m_red;
        //         ofs << pixels[rows][cols].m_green;
        //         ofs << pixels[rows][cols].m_blue;
        //     }
        // }
        for (size_t cols = 0; cols < WIDTH; ++cols) {
            for (size_t rows = 0; rows < HEIGHT; ++rows) {
                ofs << pixels[rows][cols].m_red;
                ofs << pixels[rows][cols].m_green;
                ofs << pixels[rows][cols].m_blue;
            }
        }

        ofs.close();
    }

    Rectangle::Rectangle() : m_origin{}, m_width{WIDTH / 2}, m_height{HEIGHT / 2} {}

    Rectangle::Rectangle(const vec2& loc, const size_t& width, const size_t& height, const vec3& color) {
        draw(loc, width, height, color);
    }

    void Rectangle::draw(const vec2& loc, const size_t& width, const size_t& height, const vec3& color) {
        auto x1 = loc.m_xcoord;
        auto y1 = loc.m_ycoord;
        auto x2 = loc.m_xcoord + width;
        auto y2 = loc.m_ycoord + height;

        for (size_t rows = 0; rows < HEIGHT; ++rows) {
            for (size_t cols = 0; cols < WIDTH; ++cols) {
                if (rows >= x1 && cols >= y1 && rows <= x2 && cols <= y2) {
                    pixels[rows][cols].m_red = color.m_red;
                    pixels[rows][cols].m_green = color.m_green;
                    pixels[rows][cols].m_blue = color.m_blue;
                }
            }
        }
    }

}