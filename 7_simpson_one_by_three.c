#include <stdio.h>

float y(float x) {
    return x * x;
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
    if (n % 2 != 0) {
        printf("Simpson's 1/3 rule requires an even number of intervals.\n");
        return -1;
    }

    sum = y(a) + y(b);

    for(i = 1; i < n; i++) {
        float term = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * y(term);
        } else {
            sum += 4 * y(term);
        }
    }

    val = (h / 3) * sum;

    printf("The approximate value of the integral is: %f\n", val);

    return 0;
}
