#include <stdio.h>
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}
float calculate_p_term(float p, int n) {
    float temp = p;
    for (int i = 1; i < n; i++) {
        temp = temp * (p - i);
    }
    return temp;
}
int main() {
    int n, i, j;
    float x[10], y[10][10];
    printf("Enter the total number of values for x and y: ");
    scanf("%d", &n);
    printf("Enter the values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
    }
    printf("\nForward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%f", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("\t%f", y[i][j]);
        }
        printf("\n");
    }
    float value;
    printf("\nEnter the value of x to interpolate: ");
    scanf("%f", &value);
    float result = y[0][0];
    float p = (value - x[0]) / (x[1] - x[0]);
    for (i = 1; i < n; i++) {
        result = result + (calculate_p_term(p, i) * y[0][i]) / factorial(i);
    }
    printf("\nInterpolated value at x = %f is %f\n", value, result);
    return 0;
}
