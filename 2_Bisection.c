#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (x * x * x - x - 1);
}
void bisect(float *x, float a, float b, int *itr)
{
    *x = (a + b) / 2;
    ++(*itr);
    printf("iteration no. %3dx=%75f\n", *itr, *x);
} 
int main()
{
    int itr = 0, maxitr;
    float a, b, aerr, x, x1;
    printf("enter the value of a,b,allowed error,maximum iteration\n");
    scanf("%f%f%f%d", &a, &b, &aerr, &maxitr);
    bisect(&x, a, b, &itr);
    do{
        if (f(a) * f(x) < 0){ b = x;}
        else
            a = x;
        bisect(&x1, a, b, &itr);
        if (fabs(x - x1) < aerr)
        {
            printf("after %d iteration,root=%f", itr, x1);
            return 0;
        }
        x = x1;
    } while (itr < maxitr);
    printf("solution does not converge");
    return (1);
}
