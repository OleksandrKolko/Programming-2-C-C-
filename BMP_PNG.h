#ifndef BMP_PNG_HPP
#define BMP_PNG_HPP

#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

// Клас для роботи із зображеннями
class Image {
private:
    uint32_t width;                 // Ширина зображення
    uint32_t height;                // Висота зображення
    std::vector<uint8_t> pixels;    // Масив пікселів (RGB)
    uint32_t num_rectangles;        // Кількість прямокутників
    uint32_t num_circles;           // Кількість кіл
    uint32_t num_lines;             // Кількість ліній

public:
    // Конструктор
    Image(uint32_t width, uint32_t height);

    // Створення зображення із заданими розмірами
    void create_image(uint32_t new_width, uint32_t new_height);

    // Встановлення кольору для окремого пікселя
    void set_pixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b);

    // Малювання прямокутника із заданими координатами, розмірами та кольором
    void draw_rectangle(uint32_t x, uint32_t y, uint32_t rect_width, uint32_t rect_height, uint8_t r, uint8_t g, uint8_t b);

    // Малювання лінії (Алгоритм Брезенхема)
    void draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t r, uint8_t g, uint8_t b);

    // Малювання кола (Алгоритм Брезенхема)
    void draw_circle(uint32_t xc, uint32_t yc, uint32_t radius, uint8_t r, uint8_t g, uint8_t b);

    // Заповнення фону певним кольором
    void fill_background(uint8_t r, uint8_t g, uint8_t b);

    // Збереження зображення у BMP файл
    void save_to_bmp(const std::string& filename) const;

    // Виведення інформації про зображення
    void print_info() const;

    // Виведення вмісту зображення
    void print_contents() const;

    // Заміна одного кольору на інший
    void change_color(uint8_t old_r, uint8_t old_g, uint8_t old_b, uint8_t new_r, uint8_t new_g, uint8_t new_b);

    // Очищення пам'яті зображення
    void clear_image();
};

#endif
