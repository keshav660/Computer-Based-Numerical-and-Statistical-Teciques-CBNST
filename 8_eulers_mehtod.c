#include <stdio.h>
float f(float x, float y) {
    return x + y;
}
int main() {
    float x0, y0, h, xn, x, y;
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
    printf("\n  x\t  y\n");
    while (x < xn) {
        y = y + h * f(x, y);
        x = x + h;
        printf("%0.4f\t%0.4f\n", x, y);
    }
    return 0;
}
