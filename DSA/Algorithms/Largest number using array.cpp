#include<stdio.h>
int main(void)
{
	int n,i,j,num[50];
	printf("Enter total number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dth number",i+1);
		scanf("%d",&num[i]);
	}
	for(j=0;j<n;j++)
	{
		if(num[0]<num[j])
		{
			num[0]=num[j];
		}
	}
	printf("The largest number is %d",num[0]);
}
