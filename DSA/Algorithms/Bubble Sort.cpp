#include<stdio.h>
int main(void)
{
	int n,i,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int j,k,l,t;
	for(j=0;j<n;j++)
	{
		for(k=0;k<n-j-1;k++)
		{
			if(a[k]<a[k-1])
			{
				t=a[k-1];
				a[k-1]=a[k];
				a[k]=t;
			}
		}
	}
	for(l=0;l<n;l++)
	{
		printf("%d\t",a[l]);
	}
}
