#include <cstdint>
#include <iostream>

namespace ghulam {

    class Image {
       public:
        Image();
        void generate_image(uint8_t* image, int height, int width, const char* image_name);  // this generates image
        uint8_t* header_data(int height, int stride);                                        // this will write header part  of bmp
        uint8_t* info_header_data(int height, int width);                                    // this will  write info_header part of bmp
        ~Image() {}                                                                          // see you later

       private:
        int m_width;           // width of image
        int m_height;          // height of image
        int byte_per_pixel;    // each pixel always has RGB
        int header_size;       // first section of bmp file
        int info_header_size;  // second section of bmp file

        int req_padding;  // since uint8_t && uint32_t
        int m_stride;
        const char* image_name;
    };

}  // namespace ghulam

int main() {
    ghulam::Image* my_pic = new ghulam::Image();
    std::cout << "Image genrated successfully.\n";

    return 0;
}

ghulam::Image::Image() {
    m_width = 450;
    m_height = 700;
    byte_per_pixel = 3;
    header_size = 14;
    info_header_size = 40;

    req_padding = (4 - (m_width * byte_per_pixel) % 4) % 4;
    m_stride = req_padding + (m_width * byte_per_pixel);
    image_name = "my_pic.bmp";

    // this is the pixel array which contains each pixel's RGB color value
    uint8_t image[m_height][m_width][byte_per_pixel];

    for (auto i = 0; i < m_height; ++i) {
        for (auto j = 0; j < m_width; ++j) {
            image[i][j][2] = (uint8_t)(i * 255 / m_height);
            image[i][j][1] = (uint8_t)(i * 255 / m_height);
            image[i][j][0] = (uint8_t)((i + j) * 255 / (m_height + m_width));
        }
    }

    generate_image((uint8_t*)image, m_height, m_width, image_name);
}

void ghulam::Image::generate_image(uint8_t* image, int height, int width, const char* image_name) {
    uint8_t padding[] = {0, 0, 0};

    // std::ofstream fout(image_name, std::ios::out | std::ios::binary);
    FILE* fout = fopen(image_name, "wb");
    if (!fout) {
        std::cout << "ERROR : could not generate image, issue while opening file.\n";
        return;
    }

    auto header_data_t = header_data(m_height, m_stride);
    std::fwrite(header_data_t, 1, header_size, fout);

    auto info_header_data_t = info_header_data(m_height, m_width);
    std::fwrite(info_header_data_t, 1, info_header_size, fout);

    for (int i = 0; i < height; ++i) {
        std::fwrite(image + (i * (width * byte_per_pixel)), byte_per_pixel, width, fout);
        std::fwrite(padding, 1, req_padding, fout);
    }

    fclose(fout);
}

uint8_t* ghulam::Image::header_data(int height, int stride) {
    const auto file_size = header_size + info_header_size + req_padding + (m_width * byte_per_pixel) * m_height;
    static uint8_t header[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // actually we just need to put required byte
    header[0] = (uint8_t)('B');
    header[1] = (uint8_t)('M');
    header[2] = (uint8_t)(file_size);
    header[3] = (uint8_t)(file_size >> 8);
    header[4] = (uint8_t)(file_size >> 16);
    header[5] = (uint8_t)(file_size >> 24);
    header[10] = (uint8_t)(header_size + info_header_size);

    return header;
}

uint8_t* ghulam::Image::info_header_data(int height, int width) {
    static uint8_t infoHeader[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    // actually we just need to put required byte
    infoHeader[0] = (uint8_t)(info_header_size);
    infoHeader[4] = (uint8_t)(width);
    infoHeader[5] = (uint8_t)(width >> 8);
    infoHeader[6] = (uint8_t)(width >> 16);
    infoHeader[7] = (uint8_t)(width >> 24);
    infoHeader[8] = (uint8_t)(height);
    infoHeader[9] = (uint8_t)(height >> 8);
    infoHeader[10] = (uint8_t)(height >> 16);
    infoHeader[11] = (uint8_t)(height >> 24);
    infoHeader[12] = (uint8_t)(1);
    infoHeader[14] = (uint8_t)(byte_per_pixel * 8);

    return infoHeader;
}