#include <stdio.h>

float y(float x) {
    return x * x; // Example function, replace with your desired function
}

int main() {
    float a, b, h, sum, val;
    int n, i;

    printf("Enter the Lower Limit: ");
    scanf("%f", &a);
    printf("Enter the Upper Limit: ");
    scanf("%f", &b);
    printf("Enter the value of h: ");
    scanf("%f", &h);

    n = (b - a) / h;
    if (n % 3 != 0) {
        printf("Simpson's 3/8 rule requires the number of intervals to be a multiple of 3.\n");
        return -1;
    }

    sum = y(a) + y(b);

    for(i = 1; i < n; i++) {
        float term = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * y(term);
        } else {
            sum += 3 * y(term);
        }
    }

    val = (3 * h / 8) * sum;

    printf("The approximate value of the integral is: %f\n", val);

    return 0;
}
