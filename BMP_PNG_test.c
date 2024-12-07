#include "BMP_PNG.h"
#include <stdio.h>

// Глобальна змінна для збереження імені файлу
const char *temp_filename = "manual_test.bmp";

// Функція для очікування продовження
void wait_for_user() {
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
}

// Функція для демонстрації функції виводу вмісту
void test_file_content_function() {
    printf("\nTesting content output on a small file...\n");

    // Створюємо невелике зображення 10x10
    Image *small_img = create_image(20, 20);
    if (!small_img) {
        printf("Error: Could not create image.\n");
        return;
    }

    // Наповнюємо фон білим
    fill_background(small_img, 255, 255, 255);

    // Малюємо маленький червоний прямокутник
    draw_rectangle(small_img, 2, 2, 5, 5, 255, 0, 0);

    // Зберігаємо файл
    save_as_bmp(small_img, "test_content.bmp");
    printf("Small test image saved to 'test_content.bmp'.\n");

    // Виводимо вміст у читабельному вигляді
    print_image_contents(small_img);

    // Звільняємо пам'ять
    free_image(small_img);
}

void manual_test() {
    // Створюємо зображення 500x500
    Image *img = create_image(500, 500);
    if (!img) {
        printf("Error: Could not create image.\n");
        return;
    }

    // Встановлюємо фон (білий колір)
    fill_background(img, 255, 255, 255); // Білий фон
    save_as_bmp(img, temp_filename); // Зберігаємо початкове зображення
    printf("Initial image saved to '%s'.\n", temp_filename);

    int exit = 0;
    while (!exit) {
        printf("\nManual Test Menu:\n");
        printf("1) Draw a line\n");
        printf("2) Draw a rectangle\n");
        printf("3) Draw a circle\n");
        printf("4) Change a specific color\n");
        printf("5) Show image info\n");
        printf("6) End testing\n");
        printf("Enter your choice: \n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                uint32_t x0, y0, x1, y1;
                uint8_t r, g, b;
                printf("Enter start point (x0 y0): \n");
                scanf("%u %u", &x0, &y0);
                printf("Enter end point (x1 y1): \n");
                scanf("%u %u", &x1, &y1);
                printf("Enter color (r g b): \n");
                scanf("%hhu %hhu %hhu", &r, &g, &b);
                draw_line(img, x0, y0, x1, y1, b, g, r);
                save_as_bmp(img, temp_filename);
                printf("Line drawn successfully! Updated image saved to '%s'.\n", temp_filename);
                break;
            }
            case 2: {
                uint32_t x, y, w, h;
                uint8_t r, g, b;
                printf("Enter top-left corner (x y): \n");
                scanf("%u %u", &x, &y);
                printf("Enter width and height (w h): \n");
                scanf("%u %u", &w, &h);
                printf("Enter color (r g b): \n");
                scanf("%hhu %hhu %hhu", &r, &g, &b);
                draw_rectangle(img, x, y, w, h, r, g, b);
                save_as_bmp(img, temp_filename);
                printf("Rectangle drawn successfully! Updated image saved to '%s'.\n", temp_filename);
                break;
            }
            case 3: {
                uint32_t xc, yc, radius;
                uint8_t r, g, b;
                printf("Enter center (xc yc): \n");
                scanf("%u %u", &xc, &yc);
                printf("Enter radius: \n");
                scanf("%u", &radius);
                printf("Enter color (r g b): \n");
                scanf("%hhu %hhu %hhu", &r, &g, &b);
                draw_circle(img, xc, yc, radius, r, g, b);
                save_as_bmp(img, temp_filename);
                printf("Circle drawn successfully! Updated image saved to '%s'.\n", temp_filename);
                break;
            }
            case 4: {
                uint8_t r1, g1, b1, r2, g2, b2;
                printf("Enter color to change (r g b): \n");
                scanf("%hhu %hhu %hhu", &r1, &g1, &b1);
                printf("Enter new color (r g b): \n");
                scanf("%hhu %hhu %hhu", &r2, &g2, &b2);
                change_color(img, r1, g1, b1, r2, g2, b2);
                save_as_bmp(img, temp_filename);
                printf("Color changed successfully! Updated image saved to '%s'.\n", temp_filename);
                break;
            }
            case 5: {
                print_image_info(img);
                break;
            }
            case 6: {
                printf("Ending test...\n");
                exit = 1;
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free_image(img);
}

int main() {
    int choice;
    printf("Choose format for test: \n");
    printf("1)Auto test\n");
    printf("2)Manual test\n");
    printf("3)Test file content function\n");
    scanf("%d", &choice);


    if (choice == 1) {
        // Автоматичне тестування
        printf("\nStarting auto test...\n");

        // Створюємо зображення 500x500
        Image *img = create_image(500, 500);
        if (!img) {
            printf("Error: Could not create image.\n");
            return 1;
        }

        // 1. Наповнюємо фон білим
        fill_background(img, 255, 255, 255);
        save_as_bmp(img, "auto_test.bmp");
        printf("Step 1: Background filled. Check 'output_test.bmp'.\n");
        wait_for_user();

        // 2. Малюємо червону лінію
        draw_line(img, 50, 50, 450, 50, 255, 0, 0);
        save_as_bmp(img, "auto_test.bmp");
        printf("Step 2: Red line drawn. Check 'output_test.bmp'.\n");
        wait_for_user();

        // 3. Малюємо зелену вертикальну лінію
        draw_line(img, 250, 50, 250, 450, 0, 255, 0);
        save_as_bmp(img, "auto_test.bmp");
        printf("Step 3: Green vertical line drawn. Check 'output_test.bmp'.\n");
        wait_for_user();

        // 4. Малюємо синє коло
        draw_circle(img, 250, 250, 100, 0, 0, 255);
        save_as_bmp(img, "auto_test.bmp");
        printf("Step 4: Blue circle drawn. Check 'output_test.bmp'.\n");
        wait_for_user();

        // 5. Малюємо червоний прямокутник
        draw_rectangle(img, 100, 100, 200, 150, 255, 0, 0);
        save_as_bmp(img, "auto_test.bmp");
        printf("Step 5: Red rectangle drawn. Check 'output_test.bmp'.\n");
        wait_for_user();

        // 6. Змінюємо всі червоні пікселі на зелені
        change_color(img, 255, 0, 0, 0, 255, 0);
        save_as_bmp(img, "auto_test.bmp");
        printf("Step 6: Changed red color to green. Check 'output_test.bmp'.\n");
        wait_for_user();

        // Звільняємо пам'ять
        free_image(img);
        printf("Auto test complete. Check 'auto_test.bmp' for final results.\n");
    }
    else if (choice == 2) {
        manual_test();
    }
    else if (choice == 3) {
        test_file_content_function();

    } else {
        printf("Invalid choice. Exiting.\n");
    }
}