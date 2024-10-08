

/* for regular falsi - https://www.codewithc.com/c-program-for-regula-falsi-method/#:~:text=Below%20is%20a%20short%20and%20simple%20source%20code%20in%20C
*/
// Bisection code in c;
/*
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
    do
    {
        if (f(a) * f(x) < 0)
            b = x;
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
*/

/*
// Fixed point iteration
#include<stdio.h>
#include<math.h>

float fun(float x){
    return 3*x - cos(x)-1;
}

float phi(float x){
  return (1+cos(x))/3.0;
}
float phidiff(float x){
  return -sin(x)/3.0;
}
int main(){
    printf("Enter the initial points x0,x1\n");
    float x0,x1;
    scanf("%f %f",&x0,&x1);
    if(fabs(phidiff(x0))>=1){
      printf("This phi function is not valid for this value of x0.\n");
      printf("Either change phi(x) or x.\n");
      return 0;
    }
    float prev=0.0;
    do{
        prev = x0;
        x0 = phi(x0);
        printf("%f\n",x0);
    }while(fabs(x0-prev)>=0.00009);
    printf("%f",x0);

}
*/

/*
//secant method
#include<stdio.h>
#include<math.h>
float func(float x){
    return (x*x*x-5*x+1.0);
}
int main(){
    printf("Enter the initial points x0,x1\n");
    float x0,x1;
    scanf("%f %f",&x0,&x1);
    float x2=x1;
    do{
        x1 = x2;
        x2 = x1 - ((x1-x0)/(func(x1)-func(x0)))*func(x1);
        printf("%f\n",x2);
        x0 = x1;
    }while(fabs(x1-x2)>=0.00009);
    printf("%f",x2);
}
*/

// newton raphson

// #include<stdio.h>
// #include<math.h>

// float f(float x) {
//     return x*x - 4*x -7;
// }

// float f1(float x) {
//     return 2*x- 4;
// }

// int main() {
//     float x, prev;
//     printf("Enter the initial guess x0:\n");
//     scanf("%f", &x);

//     do {
//         prev = x;
//         if (f1(x) == 0) {
//             printf("The derivative is zero. The solution doesn't exist for x = %f\n", x);
//             return 0;
//         }
//         x = x - f(x) / f1(x);
//         printf("Current approximation: %f\n", x);
//     } while (fabs(x - prev) >= 0.00009);

//     printf("The root is approximately: %f\n", x);
//     return 0;
// }



/*
// gauss elimination
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    float arr[n][n+1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j>i)
            {
                float ratio = arr[j][i]/arr[i][i];
                for(int k=0;k<=n;k++)
                {
                    arr[j][k]=arr[j][k]-(ratio*arr[i][k]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }

    float sol[n];
    sol[n-1]=arr[n-1][n]/arr[n-1][n-1];

    for(int i=n-2;i>=0;i--)
    {
        float sum=0;
        for(int j=i+1;j<n;j++)
        {
            sum+=(arr[i][j] * sol[j]);
        }
        sol[i]=(arr[i][n]-sum)/arr[i][i];

    }
    for(int i=0;i<n;i++)
    {
        printf("%f ",sol[i]);
    }
}
*/

/*
// gauss jordan
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    float arr[n][n+1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }

    //upper tri
    for(int i=0;i<n;i++)// current row
    {
        for(int j=i+1;j<n;j++)// All rows below current row
        {
            float ratio = arr[j][i]/arr[i][i];
            for(int k=i;k<=n;k++)// column traversal of each row
            {
               arr[j][k] = arr[j][k] - ratio * arr[i][k];
            }
        }
    }

    //lower tri
    for(int i=n-1;i>=0;i--)// current row
    {
        for(int j=i-1;j>=0;j--)// All rows above current row
        {
            float ratio = arr[j][i]/arr[i][i];
            for(int k=i;k<=n;k++)// column traversal of each row
            {
               arr[j][k] = arr[j][k] - ratio * arr[i][k];
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }

    float sol[n];
    for(int i=n-1;i>=0;i--)
    {
       sol[i] = arr[i][n]/arr[i][i];
    }

    for(int i=0;i<n;i++)
    {
        printf("%f ",sol[i]);
    }
}
*/

/*
// newton forward interpolation
#include <stdio.h>

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
    printf("Enter the number of data points and the point of calculation: ");
    scanf("%d", &n);
    printf("\n");

    double x[100], y[100], x0, h, result;

    printf("Enter the point at which you want to calculate the interpolation: ");
    scanf("%lf", &x0);

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double forwardTable[100][100] = {0};

    generateForwardDifferenceTable(y, forwardTable, n);

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
// gauss forward interpolation

#include<stdio.h>
#include<math.h>
int main(){
  int n;
  printf("Enter the number of observations: ");
  scanf("%d", &n);
  double y[n][n];
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) y[i][j]=0;
  double xi[n];
  double x;
  printf("Enter row xi: \n");
  for(int i=0; i<n; i++) scanf("%lf", &xi[i]);
  printf("Enter f(xi) row:\n");
  for(int i=0; i<n; i++) scanf("%lf", &y[0][i]);

  for(int i=1; i<n; i++){
    for(int j=0; j<n-i; j++){
      y[i][j] = y[i-1][j+1] - y[i-1][j];
    }
  }
  for(int i=0; i<n; i++){
    printf("%.4lf\t", xi[i]);
    for(int j=0; j<n-i; j++){
      printf("%.4lf\t", y[j][i]);
    }
    printf("\n");
  }


  printf("\nEnter x: ");
  scanf("%lf", &x);

  double u = (x-xi[n/2-1])/(xi[1]-xi[0]);
  printf("%lf \n",u);
  double ans = y[0][n/2-1];
  printf("%lf ",ans);
  double prod=u;
  int fact=1;
  int c=1;

  for(int i=1; i<n; i++){
    //printf("%lf \n",y[i][(n-i-1)/2]);
    ans += prod*y[i][(n-i-1)/2]/fact;
    fact *= (i+1);
    if(i%2)
    prod=prod*(u-c);
    else{
        prod=prod*(u-c);
        c++;
    }
  }
  printf("\nTherefore, f(%.3lf) is %.3lf\n", x, ans);
  return 0;
}
*/

/*
// Gauss siedal method

double eqx(double y,double z){
    return 1ll*((17-y+2*z)/20.0);
}
double eqy(double x, double z){
    return 1ll*((-18-3*x+z)/20.0);
}
double eqz(double x,double y){
    return 1ll*((25-2*x+3*y)/20.0);
}

#include<stdio.h>
#include<math.h>
signed main()
{
    double x1,y1,z1;
    int c=0;
    double prevX1=0.0,y=0.0,z=0.0;
    do{
        c++;
        prevX1=x1;
        y=y1;
        z=z1;
      x1=eqx(y,z);
      y1=eqy(x1,z);
      z1=eqz(x1,y1);
}while(!(fabs(x1-prevX1)<=0.10000 && fabs(y1-y)<=0.10000 && fabs(z1-z)<=0.10000 ));
printf("x %lf\n",x1 );
printf("y %lf\n",y1);
printf("z %lf\n",z1);
printf("Total no of iterations : %d",c);
}
*/

/*

// newton backward interpolation
#include <stdio.h>

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

double evaluateInterpolation(double x, double x0, double forwardTable[][100], double h, int n) {
    double result = forwardTable[n-1][0];
    double term = (x0 - x) / h;
    double act = term;
    int fact = 1;

    for (int i = 1; i < n; i++) {
        double val = (term * forwardTable[n-1-i][i]) / fact;
        result += val;
        fact *= (i + 1);
        term = term * (act - i);
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number of data points and the point of calculation: ");
    scanf("%d", &n);
    printf("\n");

    double x[100], y[100], x0, h, result;

    printf("Enter the point at which you want to calculate the interpolation: ");
    scanf("%lf", &x0);

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double forwardTable[100][100] = {0};

    generateForwardDifferenceTable(y, forwardTable, n);

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
    result = evaluateInterpolation(x[n-1], x0, forwardTable, h, n);
    printf("\nInterpolated value at x = %.2lf is %.6lf\n", x0, result);

    return 0;
}

*/