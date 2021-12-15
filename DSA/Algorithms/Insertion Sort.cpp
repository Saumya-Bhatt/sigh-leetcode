#include<stdio.h>
int main(void)
{
	int n,i,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int j,d,t;
	for(j=1;j<n;j++)
	{
		d=i;
		while(d>0 && a[d-1]>a[d])
		{
			t=a[d-1];
			a[d-1]=a[d];
			a[d]=t;
			d--;
		}
	}
	int k;
	for(k=0;k<n;k++)
	{
		printf("%d\t",a[k]);
	}
}
