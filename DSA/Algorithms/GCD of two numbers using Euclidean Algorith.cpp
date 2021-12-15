#include<stdio.h>
int gcd(int a, int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}
int main(void)
{
	int a,b,c;
	printf("Enter two numbers:\n");
	scanf("%d %d",&a,&b);
	if(a>b)
	{
		a=a;
		b=b;
	}
	else
	{
		c=a;
		a=b;
		b=c;
	}
	printf("The GCD of %d and %d is %d",a,b,gcd(a,b));
}
