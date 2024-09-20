#include <stdio.h>
#include <math.h>
float invsqrt(float x, float a) {
    float y = x / sqrt(1 + (a*x*x));
    return y;

}
float invsqrt_derivative(float x, float a) {
    float y = 1 / sqrt(pow(1 + (a*x*x), 3));
    return y;
}

int main() {
    float x, a;
    printf("Enter x and a:\n");
    scanf("%f %f", &x, &a);

    float y = invsqrt(x, a);
    float z = invsqrt_derivative(x, a);

    printf("y = %.4f\ndf = %.4f\n", y, z);
}