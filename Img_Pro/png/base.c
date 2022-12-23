#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const uint8_t PNG_SIGN_SIZE = 8;
const uint8_t PNG_SIGN_BUFFER[] = {137, 80, 78, 71, 13, 10, 26, 10};

bool validate(const char* filename, void* buffer);
void read_bytes(FILE* file, void* buffer, size_t cap);
void print_bytes(uint8_t* buffer, size_t cap);
void reverse_byte(uint8_t* buffer, size_t cap);

int main() {
    const char* filename = "baby.png";
    // const char* filename = "test_image.png";
    // const char* filename = "ball.png";

    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("ERROR: Could not open file <%s>\n", filename);
        exit(0);
    }

    // 8 byte for png signature
    uint8_t buffer[8];
    read_bytes(file, buffer, sizeof(buffer));
    print_bytes(buffer, sizeof(buffer));
    printf("\n");

    bool running = false;
    while (!running) {
        // 4 byte for length
        uint8_t length[4];
        read_bytes(file, length, sizeof(length));
        reverse_byte(length, sizeof(length));
        uint32_t chunk_length;
        memcpy(&chunk_length, length, sizeof(length));
        printf("chunk length : %u\n", chunk_length);

        // 4 byte for chunk type
        if (chunk_length == 0) running = true;

        // 4 byte for chunk type
        uint8_t type[4];
        read_bytes(file, type, sizeof(type));
        printf("chunk type : %.*s\n", sizeof(type), type);
        // printf("chunk type : ");
        // for (size_t i = 0; i < sizeof(type); ++i) {
        //     printf("%c", type[i]);
        // }
        // printf("\n");

        // <length> byte for chunk data
        if (fseek(file, chunk_length, SEEK_CUR) < 0) {
            printf("ERROR: Could not skipp chunk data.\n");
            exit(0);
        }

        // 4 byte for crc
        uint8_t crc[4];
        read_bytes(file, crc, sizeof(crc));
        printf("chunk crc : %X\n", crc);

        printf("----------------------------\n");
    }

    return 0;
}

bool validate(const char* filename, void* buffer) {
    int flag = memcmp(buffer, PNG_SIGN_BUFFER, PNG_SIGN_SIZE);

    return (flag == 0);
}

void read_bytes(FILE* file, void* buffer, size_t cap) {
    size_t size = fread(buffer, 1, cap, file);
    if (size != cap) {
        printf("ERROR: Could read <%zu> bytes.\n", cap);
        exit(0);
    }
}

void print_bytes(uint8_t* buffer, size_t cap) {
    for (size_t i = 0; i < cap; ++i) {
        printf("%u ", buffer[i]);
    }
    printf("\n");
}

void reverse_byte(uint8_t* buffer, size_t cap) {
    for (size_t i = 0; i < cap / 2; ++i) {
        uint8_t tmp = buffer[i];
        buffer[i] = buffer[cap - i - 1];
        buffer[cap - i - 1] = tmp;
    }
}
