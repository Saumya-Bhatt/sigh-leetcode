#include<stdio.h>
int main(void)
{
	int n,i,a[50],k,mid;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",k);
	int low=0;
	int high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]<k)
		{
			low=mid+1;
		}
		else if(a[mid]>k)
		{
			high=mid-1;
		}
		else
		{
		  printf("position %d",mid);
		}
	}
 return(0);
}
