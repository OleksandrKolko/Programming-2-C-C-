#include "BMP_PNG.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to create an image
Image *create_image(uint32_t width, uint32_t height) {
    Image *img = (Image *)malloc(sizeof(Image)); // Allocate memory for the structure
    img->width = width;
    img->height = height;
    img->pixels = (uint8_t *)calloc(width * height * 3, sizeof(uint8_t)); // Allocate memory for pixels
    img->num_rectangles = 0;
    img->num_circles = 0;
    img->num_lines = 0;
    return img;
}

// Function to set pixel color at a specific position
void set_pixel_color(Image *img, uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b) {
    if (x >= img->width || y >= img->height) {
        printf("Error: Out of image bounds\n");
        return;
    }
    uint32_t index = (y * img->width + x) * 3; // Calculate the pixel position in the array
    img->pixels[index] = r;
    img->pixels[index + 1] = g;
    img->pixels[index + 2] = b;
}

// Function to print image info
void print_image_info(const Image *img) {
    printf("Image Information:\n");
    printf("Width: %u pixels\n", img->width);
    printf("Height: %u pixels\n", img->height);
    printf("Number of rectangles: %u\n", img->num_rectangles);
    printf("Number of circles: %u\n", img->num_circles);
    printf("Number of lines: %u\n", img->num_lines);
}

void print_image_contents(const Image *img) {
    printf("Image Contents:\n");
    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            uint32_t index = (y * img->width + x) * 3;
            uint8_t b = img->pixels[index];
            uint8_t g = img->pixels[index + 1];
            uint8_t r = img->pixels[index + 2];

            // Якщо піксель не чорний (0,0,0), друкуємо його
            if (r != 0 || g != 0 || b != 0) {
                printf("Pixel at (%u, %u): RGB(%u, %u, %u)\n", x, y, r, g, b);
            }
        }
    }
}

// Function to draw a rectangle
void draw_rectangle(Image *img, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint8_t r, uint8_t g, uint8_t b) {
    for (uint32_t i = y; i < y + h && i < img->height; i++) {
        for (uint32_t j = x; j < x + w && j < img->width; j++) {
            set_pixel_color(img, j, i, b, g, r);
        }
    }
    img->num_rectangles++;
}

void fill_background(Image *img, uint8_t r, uint8_t g, uint8_t b) {
    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            set_pixel_color(img, x, y, r, g, b);
        }
    }
}

//Using Bresenham algorithm
void draw_circle(Image *img, uint32_t xc, uint32_t yc, uint32_t radius, uint8_t r, uint8_t g, uint8_t b) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        set_pixel_color(img, xc + x, yc + y, r, g, b);
        set_pixel_color(img, xc - x, yc + y, r, g, b);
        set_pixel_color(img, xc + x, yc - y, r, g, b);
        set_pixel_color(img, xc - x, yc - y, r, g, b);
        set_pixel_color(img, xc + y, yc + x, r, g, b);
        set_pixel_color(img, xc - y, yc + x, r, g, b);
        set_pixel_color(img, xc + y, yc - x, r, g, b);
        set_pixel_color(img, xc - y, yc - x, r, g, b);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
    img->num_circles++;
}

//Using Bresenham algorithm
void draw_line(Image *img, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t b, uint8_t g, uint8_t r) {
    int dx = abs((int)x1 - (int)x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs((int)y1 - (int)y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        set_pixel_color(img, x0, y0, r, g, b);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
    img->num_lines++;
}

void change_color(Image *img, uint8_t old_r, uint8_t old_g, uint8_t old_b,uint8_t new_r, uint8_t new_g, uint8_t new_b) {
    uint32_t row_padded = (img->width * 3 + 3) & (~3);

    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            uint32_t index = y * row_padded + x * 3;

            // Перевірка кольору у форматі BGR
            if (img->pixels[index] == old_b &&
                img->pixels[index + 1] == old_g &&
                img->pixels[index + 2] == old_r) {

                // Замінюємо на новий колір
                img->pixels[index] = new_b;
                img->pixels[index + 1] = new_g;
                img->pixels[index + 2] = new_r;
                }
        }
    }
}


// Function to save the image as a BMP file
void save_as_bmp(const Image *img, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        printf("Error: Could not open file for writing\n");
        return;
    }

    uint32_t file_size = 54 + img->width * img->height * 3; // File size
    uint32_t data_offset = 54;

    uint8_t bmp_header[54] = {
        0x42, 0x4D,              // Signature 'BM'
        file_size, file_size >> 8, file_size >> 16, file_size >> 24, // File size
        0x00, 0x00,              // Reserved
        0x00, 0x00,              // Reserved
        data_offset, 0x00, 0x00, 0x00, // Offset to pixel data
        0x28, 0x00, 0x00, 0x00,  // DIB header size
        img->width, img->width >> 8, img->width >> 16, img->width >> 24, // Width
        img->height, img->height >> 8, img->height >> 16, img->height >> 24, // Height
        0x01, 0x00,              // Color planes
        0x18, 0x00,              // Bits per pixel (24 bits)
        0x00, 0x00, 0x00, 0x00,  // Compression (none)
        0x00, 0x00, 0x00, 0x00,  // Image size (can be 0 for no compression)
        0x13, 0x0B, 0x00, 0x00,  // Horizontal resolution (2835 pixels per meter)
        0x13, 0x0B, 0x00, 0x00,  // Vertical resolution (2835 pixels per meter)
        0x00, 0x00, 0x00, 0x00,  // Colors in palette (none)
        0x00, 0x00, 0x00, 0x00   // Important colors (all)
    };

    fwrite(bmp_header, sizeof(bmp_header), 1, f); // Write BMP header

    for (int i = img->height - 1; i >= 0; i--) {
        fwrite(&img->pixels[i * img->width * 3], 3, img->width, f); // Write pixel data
    }

    fclose(f);
    printf("Image successfully saved to file %s\n", filename);
}

// Function to free memory for the image
void free_image(Image *img) {
    free(img->pixels);
    free(img);
}

