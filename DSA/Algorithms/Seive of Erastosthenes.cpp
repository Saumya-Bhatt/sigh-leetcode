#include<stdio.h>
int main(void)
{
	int i,j,n,m,p,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	for(j=2;j*j<n;j++)
	{
		if(a[j]!=1234)
		{
			for(m=2*j;m<n;m+=j)
			{
				a[m]=1234;
			}
		}
	}
	for(p=0;p<n;p++)
	{
		if(a[p]!=1234)
		{
			printf("%d\t",a[p]);
		}
	}
}
