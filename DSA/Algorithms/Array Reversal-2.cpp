#include<stdio.h>
int main(void)
{
	int i,j,n,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int temp;
	for(i=0,j=n-1;i<n/2;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	for(j=0;j<n;j++)
	{
		printf("%d\t",a[j]);
	}
}
