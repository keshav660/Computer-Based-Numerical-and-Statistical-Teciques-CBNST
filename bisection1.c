//Write a C program to find the real root of the function f(x) = x^3-x-1, correct upto 4 decimal places.
#include<stdio.h>	
#include<stdlib.h>
#include<math.h>

float f(float x){
	return (pow(x,3)-x-1);
}

int main(){

	float x0=0, x1=0, x2;

	while(f(x0)>=0) x0--;
	while(f(x1)<0) x1++;

	printf("Initial Guess : X0 = %f        X1 = %f\n\n",x0,x1);

	while(1){
		x2 = (x0+x1)/2;

		if(fabs(f(x2))<0.0001){
			printf("Root = %f\n",x2);
			printf("Value at root = %f\n", f(x2));
			break;
		}
		else if(f(x2)<0){
			x0=x2;
		}
		else{
			x1=x2;
		}
	}

	return 0;
}