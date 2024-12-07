#include "BMP_PNG.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdint>
#include <cmath>

// Конструктор
Image::Image(uint32_t width, uint32_t height)
    : width(width), height(height), pixels(width * height * 3, 0),
      num_rectangles(0), num_circles(0), num_lines(0) {}

// Створення зображення із заданими розмірами
void Image::create_image(uint32_t new_width, uint32_t new_height) {
    width = new_width;
    height = new_height;
    pixels.resize(width * height * 3, 0); // Ініціалізація чорним кольором
    num_rectangles = 0;
    num_circles = 0;
    num_lines = 0;
}

// Встановлення кольору для окремого пікселя
void Image::set_pixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b) {
    if (x >= width || y >= height) {
        throw std::out_of_range("Pixel coordinates are out of bounds.");
    }
    uint32_t index = (y * width + x) * 3;
    pixels[index] = b;       // Синій
    pixels[index + 1] = g;   // Зелений
    pixels[index + 2] = r;   // Червоний
}

// Малювання прямокутника із заданими координатами, розмірами та кольором
void Image::draw_rectangle(uint32_t x, uint32_t y, uint32_t rect_width, uint32_t rect_height, uint8_t r, uint8_t g, uint8_t b) {
    for (uint32_t i = 0; i < rect_height; ++i) {
        for (uint32_t j = 0; j < rect_width; ++j) {
            uint32_t px = x + j;
            uint32_t py = y + i;
            if (px < width && py < height) {
                set_pixel(px, py, r, g, b);
            }
        }
    }
    num_rectangles++;
}

// Збереження зображення у BMP файл
void Image::save_to_bmp(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    uint32_t row_padded = (width * 3 + 3) & (~3); // Вирівнювання рядків до 4 байтів
    uint32_t pixel_array_size = row_padded * height;
    uint32_t file_size = 54 + pixel_array_size;

    uint8_t file_header[14] = {
        'B', 'M',
        static_cast<uint8_t>(file_size), static_cast<uint8_t>(file_size >> 8),
        static_cast<uint8_t>(file_size >> 16), static_cast<uint8_t>(file_size >> 24),
        0, 0, 0, 0, 54, 0, 0, 0
    };

    uint8_t info_header[40] = {
        40, 0, 0, 0,
        static_cast<uint8_t>(width), static_cast<uint8_t>(width >> 8),
        static_cast<uint8_t>(width >> 16), static_cast<uint8_t>(width >> 24),
        static_cast<uint8_t>(height), static_cast<uint8_t>(height >> 8),
        static_cast<uint8_t>(height >> 16), static_cast<uint8_t>(height >> 24),
        1, 0, 24, 0, 0, 0, 0, 0,
        static_cast<uint8_t>(pixel_array_size), static_cast<uint8_t>(pixel_array_size >> 8),
        static_cast<uint8_t>(pixel_array_size >> 16), static_cast<uint8_t>(pixel_array_size >> 24),
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    file.write(reinterpret_cast<const char*>(file_header), sizeof(file_header));
    file.write(reinterpret_cast<const char*>(info_header), sizeof(info_header));

    for (int y = height - 1; y >= 0; --y) {
        for (uint32_t x = 0; x < width; ++x) {
            uint32_t index = (y * width + x) * 3;
            file.put(pixels[index]);         // Синій
            file.put(pixels[index + 1]);     // Зелений
            file.put(pixels[index + 2]);     // Червоний
        }
        file.write("\0\0\0", row_padded - width * 3);
    }

    file.close();
}

// Малювання лінії (Алгоритм Брезенхема)
void Image::draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t r, uint8_t g, uint8_t b) {
    int dx = abs((int)x1 - (int)x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs((int)y1 - (int)y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        set_pixel(x0, y0, r, g, b);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
    num_lines++;
}

// Малювання кола (Алгоритм Брезенхема)
void Image::draw_circle(uint32_t xc, uint32_t yc, uint32_t radius, uint8_t r, uint8_t g, uint8_t b) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        set_pixel(xc + x, yc + y, r, g, b);
        set_pixel(xc - x, yc + y, r, g, b);
        set_pixel(xc + x, yc - y, r, g, b);
        set_pixel(xc - x, yc - y, r, g, b);
        set_pixel(xc + y, yc + x, r, g, b);
        set_pixel(xc - y, yc + x, r, g, b);
        set_pixel(xc + y, yc - x, r, g, b);
        set_pixel(xc - y, yc - x, r, g, b);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
    num_circles++;
}

// Заповнення фону певним кольором
void Image::fill_background(uint8_t r, uint8_t g, uint8_t b) {
    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            set_pixel(x, y, r, g, b);
        }
    }
}

// Заміна кольору
void Image::change_color(uint8_t old_r, uint8_t old_g, uint8_t old_b, uint8_t new_r, uint8_t new_g, uint8_t new_b) {
    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            uint32_t index = (y * width + x) * 3;
            if (pixels[index] == old_b && pixels[index + 1] == old_g && pixels[index + 2] == old_r) {
                pixels[index] = new_b;
                pixels[index + 1] = new_g;
                pixels[index + 2] = new_r;
            }
        }
    }
}

// Виведення інформації про зображення
void Image::print_info() const {
    std::cout << "Image Information:\n";
    std::cout << "Width: " << width << " px\n";
    std::cout << "Height: " << height << " px\n";
    std::cout << "Rectangles: " << num_rectangles << "\n";
    std::cout << "Circles: " << num_circles << "\n";
    std::cout << "Lines: " << num_lines << "\n";
}

// Виведення змісту зображення
void Image::print_contents() const {
    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            uint32_t index = (y * width + x) * 3;
            uint8_t r = pixels[index + 2];
            uint8_t g = pixels[index + 1];
            uint8_t b = pixels[index];
            std::cout << "(" << (int)r << "," << (int)g << "," << (int)b << ") ";
        }
        std::cout << "\n";
    }
}
