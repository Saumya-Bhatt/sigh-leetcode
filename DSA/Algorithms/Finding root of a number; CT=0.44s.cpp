#include<stdio.h>
#include<cmath>
# define epsilon 0.0001
int main(void)
{
	float m,g1,g2;
	printf("Enter a number:\n");
	scanf("%f",&m);
	g1=m/2;
	while(fabs(g1*g1-m)> epsilon)
	{
		g1=(g1+m/g1)/2;
	}
	printf("%f's root is %f",m,g1);
}
