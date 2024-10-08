#include <stdio.h>
#include <math.h>
float fun(float x) {
    return cos(x) - 3 * x + 1;
}
float phi(float x) {
    return (cos(x) + 1) / 3;
}
float phidiff(float x) {
    return -sin(x) / 3;
}
int main()
{
    int max_iterations;
    float a, b, x0, allerr;

    printf("Enter a , b ,allowed error and maximum iterations::\n");
    scanf("%f %f %f %d", &a, &b,&allerr, &max_iterations);
    x0 = (a + b) / 2;
    if (fabs(phidiff(x0)) > 1)
    {
        printf("This phi function is not valid for this value of x0.\n");
        printf("Either change phi(x) or x.\n");
        return 0;
    }
    float prev = 0.0;
    int iterations = 0;
    do
    {
        
        prev = x0;
        x0 = phi(x0);
        iterations++;
        printf("At Iteration no. %3d, x = %9.6f\n", iterations, x0);
        if (fabs(x0 - prev) < allerr)
        {
            printf("After %3d iterations, root = %8.6f\n", iterations, x0);
            return 0;
        }
    } while (iterations < max_iterations);
    printf("The required solution does not converge or iterations are insufficient\n");
    return 0;
}
