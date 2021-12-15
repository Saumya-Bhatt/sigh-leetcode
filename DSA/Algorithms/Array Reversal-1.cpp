#include<stdio.h>
int main(void)
{
	int i,j,m,n,a[50],b[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=n-1,i=0;j>=0,i<n;j--,i++)
	{
		b[i]=a[j];
	}
	for(m=0;m<n;m++)
	{
		printf("%d\t",b[m]);
	}
}
