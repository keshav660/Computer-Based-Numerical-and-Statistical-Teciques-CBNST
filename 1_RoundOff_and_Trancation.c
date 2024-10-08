#include <stdio.h>

float roundOff(float number)
{
    int fac = 10000; // 10^4
    float temp = number * fac;
    int roundedTemp = (int)(temp + 0.5);

    return (float)roundedTemp / fac;
}

int main()
{
    printf("Input the value: ");
    float a1;
    scanf("%f", &a1);

    float rounded_value = roundOff(a1);

    printf("Rounded value to 4 decimal places: %.4f\n", rounded_value);

    return 0;
}
