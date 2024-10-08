#include <stdio.h>

#define SIZE 3
void gaussElimination(float a[SIZE][SIZE + 1]) {
    int i, j, k, iterations = 0;
    float ratio;
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (a[i][i] == 0) {
                printf("its error here , Division by zero.\n");
                return;
            }
            ratio = a[j][i] / a[i][i];
            for (k = 0; k <= SIZE; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
            iterations++;
        }
    }
    float x[SIZE];
    x[SIZE - 1] = a[SIZE - 1][SIZE] / a[SIZE - 1][SIZE - 1];
    
    for (i = SIZE - 2; i >= 0; i--) {
        x[i] = a[i][SIZE];
        for (j = i + 1; j < SIZE; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    printf("The solution is:\n");
    for (i = 0; i < SIZE; i++) {
        printf("x%d = %0.2f\n", i + 1, x[i]);
    }

    printf("Number of iterations: %d\n", iterations);
}
int main() {
    float a[SIZE][SIZE + 1];
    int i, j;

    printf("Enter the coefficients of the augmented matrix (including the right-hand side values):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j <= SIZE; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    gaussElimination(a);
    return 0;
}

    





















