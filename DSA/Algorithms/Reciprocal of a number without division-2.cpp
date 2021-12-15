#include<stdio.h>
#include<cmath>
#define epsilon 0.0001f
int main(void)
{
	float m,diff,g1,g2,c;
	printf("Enter a number:");
	scanf("%f",&m);
	g1=epsilon;
	g2=m;
	do
	{
		c=(g1+g2)/2;
		diff=m*c-1.0f;
		if(diff>0)
		{
			g2=c;
		}
		else
		{
			g1=c;
		}
	}
	while(fabs(diff)>epsilon);
	printf("The reciprocal of %f is %f",m,c);
}
