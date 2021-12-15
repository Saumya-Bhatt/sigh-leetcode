#include<stdio.h>
int main(void)
{
	int m1[10][10],m2[10][10],c[10][10];
	int r1,r2,c1,c2;
	printf("Enter row, column for matrix1:\n");
	scanf("%d %d",&r1,&c1);
	printf("Enter row, column fro matrix2:\n");
	scanf("%d %d",&r2,&c2);
	while(c1!=r2)
	{
		printf("Matrix multiplication not possible. Try again\n");
		printf("Enter row, column for matrix1:\n");
		scanf("%d %d",&r1,&c1);
		printf("Enter row, column fro matrix2:\n");
		scanf("%d %d",&r2,&c2);
	}
	printf("Entering values for matrix1:\n");
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			printf("Enter m1[%d][%d]th element: ",i+1,j+1);
			scanf("%d",&m1[i][j]);
		}
	}
	printf("\nMatrix1 is:\n");
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			printf("%d\t",m1[i][j]);
		}
		printf("\n");
	}
	printf("\nEntering values for matrix2:\n");
	for(int i=0;i<r2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			printf("Enter m2[%d][%d]th element: ",i+1,j+1);
			scanf("%d",&m2[i][j]);
		}
	}
	printf("\nMatrix2 is:\n");
	for(int i=0;i<r2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			printf("%d\t",m2[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			c[i][j]=0;
		}
	}
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			for(int k=0;k<c1;k++)
			{
				c[i][j]+=m1[i][k]*m2[k][j];
			}
		}
	}
	printf("\nThe resultant matrix is:\n");
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	
}

