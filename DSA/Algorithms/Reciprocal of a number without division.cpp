#include<stdio.h>
#include<cstdlib>
#define epsilon 0.0001
int main(void)
{
	float g1,m;
	printf("Enter a number:\n");
	scanf("%f",&m);
	if(m==0)
	{
		printf("Reciprocal not defined.");
	}
	else
	{
		g1=2/m;
		while(abs(g1-1/m)>epsilon)
		{
			g1=(g1-m/g1)/2;
		}
		printf("It's reciprocal is %f",g1/2);
	}
}
