#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    printf("a = \n");
    scanf("%f", &a);
    printf("b = \n");
    scanf("%f", &b);
    printf("c = \n");
    scanf("%f", &c);

    float dis = (b * b) - (4 * a * c);
    if (dis < 0) {
        return 0;
    }
    else if (dis == 0) {
        float x = (-1 * b) / (2 * a);
        printf("x = %.0f", x);
    }
    else if (dis > 0) {
        float x1 = ((-1 * b) - sqrt(dis)) / (2 * a);
        float x2 = ((-1 * b) + sqrt(dis)) / (2 * a);
        printf("x1 = %.0f\n", x1);
        printf("x2 = %.0f\n", x2);
    }
}