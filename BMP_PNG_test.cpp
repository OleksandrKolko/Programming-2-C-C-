#include "BMP_PNG.h"
#include <iostream>
#include <string>
#include <cmath>

// Глобальна змінна для збереження імені файлу
const std::string temp_filename = "manual_test.bmp";

// Функція для очікування продовження
void wait_for_user() {
    std::cout << "Press Enter to continue...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Функція для демонстрації функції виводу вмісту
void test_file_content_function() {
    std::cout << "\nTesting content output on a small file...\n";

    // Створюємо невелике зображення 20x20
    Image small_img(20, 20);

    // Наповнюємо фон білим
    small_img.fill_background(255, 255, 255);

    // Малюємо маленький червоний прямокутник
    small_img.draw_rectangle(2, 2, 5, 5, 255, 0, 0);

    // Зберігаємо файл
    small_img.save_to_bmp("test_content.bmp");
    std::cout << "Small test image saved to 'test_content.bmp'.\n";

    // Виводимо вміст у читабельному вигляді
    small_img.print_contents();
}

void manual_test() {
    // Створюємо зображення 500x500
    Image img(500, 500);

    // Встановлюємо фон (білий колір)
    img.fill_background(255, 255, 255); // Білий фон
    img.save_to_bmp(temp_filename); // Зберігаємо початкове зображення
    std::cout << "Initial image saved to '" << temp_filename << "'.\n";

    bool exit = false;
    while (!exit) {
        std::cout << "\nManual Test Menu:\n";
        std::cout << "1) Draw a line\n";
        std::cout << "2) Draw a rectangle\n";
        std::cout << "3) Draw a circle\n";
        std::cout << "4) Change a specific color\n";
        std::cout << "5) Show image info\n";
        std::cout << "6) End testing\n";
        std::cout << "Enter your choice: \n";

        int choice;
        std::cin >> choice;

switch (choice) {
    case 1: { // Draw a line
        uint32_t x0, y0, x1, y1;
        int r, g, b; //Замінив на int, через некоректність зчитування uint8_t
        std::cout << "Enter start point (x0 y0): \n";
        std::cin >> x0 >> y0;
        std::cout << "Enter end point (x1 y1): \n";
        std::cin >> x1 >> y1;
        std::cout << "Enter color (r g b): \n";
        std::cin >> r >> g >> b;
        img.draw_line(x0, y0, x1, y1, r, g, b); // Ensure correct color order here
        img.save_to_bmp(temp_filename);
        std::cout << "Line drawn successfully! Updated image saved to '" << temp_filename << "'.\n";
        break;
    }
    case 2: { // Draw a rectangle
        uint32_t x, y, w, h;
        int r, g, b; //Замінив на int, через некоректність зчитування uint8_t
        std::cout << "Enter top-left corner (x y): \n";
        std::cin >> x >> y;
        std::cout << "Enter width and height (w h): \n";
        std::cin >> w >> h;
        std::cout << "Enter color (r g b): \n";
        std::cin >> r >>  g >> b;
        img.draw_rectangle(x, y, w, h, r, g, b); // Ensure correct color order here
        img.save_to_bmp(temp_filename);
        std::cout << "Rectangle drawn successfully! Updated image saved to '" << temp_filename << "'.\n";
        break;
    }
    case 3: { // Draw a circle
        uint32_t xc, yc, radius;
        int r, g, b; //Замінив на int, через некоректність зчитування uint8_t
        std::cout << "Enter center (xc yc): \n";
        std::cin >> xc >> yc;
        std::cout << "Enter radius: \n";
        std::cin >> radius;
        std::cout << "Enter color (r g b): \n";
        std::cin >> r >> g >> b;
        img.draw_circle(xc, yc, radius, r, g, b); // Ensure correct color order here
        img.save_to_bmp(temp_filename);
        std::cout << "Circle drawn successfully! Updated image saved to '" << temp_filename << "'.\n";
        break;
    }
    case 4: { // Change color
        int r1, g1, b1, r2, g2, b2; //Замінив на int, через некоректність зчитування uint8_t
        std::cout << "Enter color to change (r g b): \n";
        std::cin >> r1 >> g1 >> b1;
        std::cout << "Enter new color (r g b): \n";
        std::cin >> r2 >> g2 >> b2;
        img.change_color(r1, g1, b1, r2, g2, b2); // Ensure correct color order here
        img.save_to_bmp(temp_filename);
        std::cout << "Color changed successfully! Updated image saved to '" << temp_filename << "'.\n";
        break;
    }
    case 5: {
        img.print_info();
        break;
    }
    case 6:
        std::cout << "Ending test...\n";
        exit = true;
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
}
    }
}

int main() {
    int choice;
    std::cout << "Choose format for test: \n";
    std::cout << "1) Auto test\n";
    std::cout << "2) Manual test\n";
    std::cout << "3) Test file content function\n";
    std::cin >> choice;

    if (choice == 1) {
        // Автоматичне тестування
        std::cout << "\nStarting auto test...\n";

        // Створюємо зображення 500x500
        Image img(500, 500);

        // 1. Наповнюємо фон білим
        img.fill_background(255, 255, 255);
        img.save_to_bmp("auto_test.bmp");
        std::cout << "Step 1: Background filled. Check 'auto_test.bmp'.\n";
        wait_for_user();

        // 2. Малюємо червону лінію
        img.draw_line(50, 50, 450, 50, 255, 0, 0);
        img.save_to_bmp("auto_test.bmp");
        std::cout << "Step 2: Red line drawn. Check 'auto_test.bmp'.\n";
        wait_for_user();

        // 3. Малюємо зелену вертикальну лінію
        img.draw_line(250, 50, 250, 450, 0, 255, 0);
        img.save_to_bmp("auto_test.bmp");
        std::cout << "Step 3: Green vertical line drawn. Check 'auto_test.bmp'.\n";
        wait_for_user();

        // 4. Малюємо синє коло
        img.draw_circle(250, 250, 100, 0, 0, 255);
        img.save_to_bmp("auto_test.bmp");
        std::cout << "Step 4: Blue circle drawn. Check 'auto_test.bmp'.\n";
        wait_for_user();

        // 5. Малюємо червоний прямокутник
        img.draw_rectangle(100, 100, 200, 150, 255, 0, 0);
        img.save_to_bmp("auto_test.bmp");
        std::cout << "Step 5: Red rectangle drawn. Check 'auto_test.bmp'.\n";
        wait_for_user();

        // 6. Змінюємо всі червоні пікселі на зелені
        img.change_color(255, 0, 0, 0, 255, 0);
        img.save_to_bmp("auto_test.bmp");
        std::cout << "Step 6: Changed red color to green. Check 'auto_test.bmp'.\n";
        wait_for_user();

        std::cout << "Auto test complete. Check 'auto_test.bmp' for final results.\n";

    } else if (choice == 2) {
        manual_test();
    } else if (choice == 3) {
        test_file_content_function();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}
