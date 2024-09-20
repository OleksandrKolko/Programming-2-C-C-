#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float eps = 0.0000001;
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
    else if(fabs(dis) < eps){
        float x = (-1 * b) / (2 * b);
        printf("x = %.0f\n", x);
    }
    else {
        float x1 = ((-1 * b) - sqrt(dis)) / (2 * a);
        float x2 = ((-1 * b) + sqrt(dis)) / (2 * a);
        printf("x1 = %.0f\n", x1);
        printf("x2 = %.0f\n", x2);
    }
}
