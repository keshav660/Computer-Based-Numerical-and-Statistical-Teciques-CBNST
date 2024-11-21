#include <stdio.h>

float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, h, xn, x, y, k1, k2, k3, k4;

    printf("\nEnter x0: ");
    scanf("%f", &x0);
    printf("\nEnter y0: ");
    scanf("%f", &y0);
    printf("\nEnter h: ");
    scanf("%f", &h);
    printf("\nEnter the value of x at which y is required (xn): ");
    scanf("%f", &xn);

    x = x0;
    y = y0;

    printf("\n  x\t y\n");
    while (x < xn) {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
        printf("%0.4f\t%0.4f\n", x, y);
    }

    return 0;
}
