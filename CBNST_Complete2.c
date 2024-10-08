/*
// Gauss Elimination Method
#include<stdio.h>

int main() {
    int n;
    printf("Enter the value of n (number of equations): \n");
    scanf("%d", &n);
    float arr[n][n+1];

    // Input the augmented matrix
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            scanf("%f", &arr[i][j]);
        }
    }

    // Forward elimination to convert matrix to upper triangular form
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            float ratio = arr[j][i] / arr[i][i];
            for(int k = 0; k <= n; k++) {
                arr[j][k] -= ratio * arr[i][k];
            }
        }
    }

    // Back substitution to find the solution
    float sol[n];
    sol[n-1] = arr[n-1][n] / arr[n-1][n-1];
    for(int i = n-2; i >= 0; i--) {
        float sum = 0;
        for(int j = i+1; j < n; j++) {
            sum += arr[i][j] * sol[j];
        }
        sol[i] = (arr[i][n] - sum) / arr[i][i];
    }

    // Output the solution
    printf("Solution:\n");
    for(int i = 0; i < n; i++) {
        printf("%f ", sol[i]);
    }
    printf("\n");

    return 0;
}
*/

/*
// Gauss-Jordan Method
#include<stdio.h>

int main() {
    int n;
    printf("Enter the value of n (number of equations): \n");
    scanf("%d", &n);
    float arr[n][n+1];

    // Input the augmented matrix
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            scanf("%f", &arr[i][j]);
        }
    }

    // Convert matrix to reduced row echelon form
    for(int i = 0; i < n; i++) {
        // Upper triangular
        for(int j = i+1; j < n; j++) {
            float ratio = arr[j][i] / arr[i][i];
            for(int k = i; k <= n; k++) {
                arr[j][k] -= ratio * arr[i][k];
            }
        }
    }

    for(int i = n-1; i >= 0; i--) {
        // Lower triangular
        for(int j = i-1; j >= 0; j--) {
            float ratio = arr[j][i] / arr[i][i];
            for(int k = i; k <= n; k++) {
                arr[j][k] -= ratio * arr[i][k];
            }
        }
    }

    // Output the matrix after row reduction
    printf("Reduced Row Echelon Form:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    // Output the solution
    float sol[n];
    for(int i = 0; i < n; i++) {
        sol[i] = arr[i][n] / arr[i][i];
    }

    printf("Solution:\n");
    for(int i = 0; i < n; i++) {
        printf("%f ", sol[i]);
    }
    printf("\n");

    return 0;
}
*/

/*
// Newton Forward Interpolation
#include <stdio.h>

// Function to generate the forward difference table
void generateForwardDifferenceTable(double y[], double forwardTable[][100], int n) {
    for (int i = 0; i < n; i++) {
        forwardTable[i][0] = y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            forwardTable[j][i] = forwardTable[j + 1][i - 1] - forwardTable[j][i - 1];
        }
    }
}

// Function to evaluate the interpolation
double evaluateInterpolation(double x, double x0, double forwardTable[][100], double h, int n) {
    double result = forwardTable[0][0];
    double term = (x0 - x) / h;
    double act = term;
    int fact = 1;

    for (int i = 1; i < n; i++) {
        double val = (term * forwardTable[0][i]) / fact;
        result += val;
        fact *= (i + 1);
        term = term * (act - i);
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[100], y[100], x0, h, result;

    // Input the point for interpolation
    printf("Enter the point at which you want to calculate the interpolation: ");
    scanf("%lf", &x0);

    // Input data points
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double forwardTable[100][100] = {0};

    generateForwardDifferenceTable(y, forwardTable, n);

    // Display the forward difference table
    printf("Complete Forward Difference Table:\n");
    printf("    x      y");
    for(int i = 0; i < n - 1; i++) {
        printf("      Δ^%d y", i + 1);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%.4lf      ", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("%.4lf      ", forwardTable[i][j]);
        }
        printf("\n");
    }

    h = x[1] - x[0];
    result = evaluateInterpolation(x[0], x0, forwardTable, h, n);
    printf("\nInterpolated value at x = %.2lf is %.6lf\n", x0, result);

    return 0;
}
*/

/*
// Gauss Forward Interpolation
#include<stdio.h>
#include<math.h>

int main() {
    int n;
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    double y[n][n];
    double xi[n];
    double x;

    // Initialize y array to zero
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            y[i][j] = 0;
        }
    }

    // Input xi and f(xi)
    printf("Enter the xi values:\n");
    for(int i = 0; i < n; i++) {
        scanf("%lf", &xi[i]);
    }
    printf("Enter the f(xi) values:\n");
    for(int i = 0; i < n; i++) {
        scanf("%lf", &y[0][i]);
    }

    // Compute the forward differences
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            y[i][j] = y[i-1][j+1] - y[i-1][j];
        }
    }

    // Display the forward difference table
    printf("Forward Difference Table:\n");
    for(int i = 0; i < n; i++) {
        printf("%.4lf\t", xi[i]);
        for(int j = 0; j < n - i; j++) {
            printf("%.4lf\t", y[j][i]);
        }
        printf("\n");
    }

    // Input the value for interpolation
    printf("\nEnter x: ");
    scanf("%lf", &x);

    // Compute the interpolation
    double u = (x - xi[n/2 - 1]) / (xi[1] - xi[0]);
    double ans = y[0][n/2 - 1];
    double prod = u;
    int fact = 1;
    int c = 1;

    for(int i = 1; i < n; i++) {
        ans += prod * y[i][(n - i - 1) / 2] / fact;
        fact *= (i + 1);
        prod = prod * (u - c);
        if(i % 2 == 0) c++;
    }

    printf("\nTherefore, f(%.3lf) is %.3lf\n", x, ans);

    return 0;
}
*/

/*
// Gauss-Seidel Method
#include<stdio.h>
#include<math.h>

// Define equations
double eqx(double y, double z) {
    return (17 - y + 2 * z) / 10;
}

double eqy(double x, double z) {
    return (20 - 2 * x - z) / 15;
}

double eqz(double x, double y) {
    return (25 - x + y) / 20;
}

int main() {
    double x0 = 0, y0 = 0, z0 = 0; // Initial guesses
    double x1, y1, z1;
    double tol = 1e-6; // Tolerance
    int max_iter = 1000; // Maximum iterations
    int iter = 0;

    do {
        x1 = eqx(y0, z0);
        y1 = eqy(x1, z0);
        z1 = eqz(x1, y1);
        
        if (fabs(x1 - x0) < tol && fabs(y1 - y0) < tol && fabs(z1 - z0) < tol) {
            break;
        }
        
        x0 = x1;
        y0 = y1;
        z0 = z1;
        
        iter++;
    } while (iter < max_iter);

    printf("Solution:\n");
    printf("x = %f\n", x1);
    printf("y = %f\n", y1);
    printf("z = %f\n", z1);

    return 0;
}
*/
