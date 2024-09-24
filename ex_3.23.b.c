#include <stdio.h>
#include <math.h>
float ReLu(float x) {
    if(x > 0) {
        return x;
    }
    else {
        x = 0;
        return x;
    }
}

float ReLu_derivative(float x) {
    x =  0;
    return x;
}

int main() {
    float x;
    printf("Enter x:\n");
    scanf("%f", &x);

    printf("Result of function ReLu = %.1f\n", ReLu(x));
    printf("Derivative of function = %.1f\n", ReLu_derivative(ReLu(x)));

}