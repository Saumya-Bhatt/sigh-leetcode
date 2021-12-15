#include<stdio.h>
#include<cmath>
# define Epsilon 0.0001
float f(float x)
{
	return x*x*x-x*x+2;
}
void bisection(float a, float b)
{
	if(f(a)*f(b)>0)
	{
		printf("No root within this interval.");
	}
	float c;
	while(fabs(b-a)>Epsilon)
	{
		c=(a+b)/2;
		if(f(a)*f(c)<0)
		{
			b=c;
		}
		else if(f(b)*f(c)<0)
		{
			a=c;
		}
		else if(f(c)==0)
		{
			printf("The root of x^3-x^2+2 is %f",c);
			break;
		}
	}
	printf("The root of x^3-x^2+2 is %f",c);
}
int main(void)
{
	float u,l;
	printf("Enter upper limit:\n");
	scanf("%f",&u);
	printf("Enter lower limit:\n");
	scanf(" %f",&l);
	bisection(l,u);
}
