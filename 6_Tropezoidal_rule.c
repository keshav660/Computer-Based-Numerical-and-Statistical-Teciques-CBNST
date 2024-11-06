#include <stdio.h>
#include <math.h>


float y(float x) {
    return 1/(1+pow(x,2));  
}

int main() {
    float a, b, h, sum, val, term;
    int n, i;

    printf("Enter the Lower Limit: ");
    scanf("%f", &a);
    printf("Enter the Upper Limit: ");
    scanf("%f", &b);
    printf("Enter the value of h: ");
    scanf("%f", &h);

    n = (b - a) / h;

    sum = y(a) + y(b);

    for(i = 1; i < n; i++) {
        term = a + i * h;
        sum += 2 * y(term);
    }

    val = (h / 2) * sum;

    printf("The approximate value of the integral is: %f\n", val);

    return 0;
}
