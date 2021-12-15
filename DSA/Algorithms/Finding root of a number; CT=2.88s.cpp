#include<stdio.h>
int main(void)
{
	float m,i;
	printf("Enter a number:");
	scanf("%f",&m);
	for(i=0;i<m/2;i++)
	{
		if(i*i==m)
		{
			printf("The root is %f",i);
			break;
		}
	}
}
