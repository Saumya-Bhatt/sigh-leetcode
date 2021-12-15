#include <stdio.h>
int main() {
	int a;
	char c;
	printf("Enter a number: \n");
	scanf("%d",&a);
	printf("Enter a character: \n");
	scanf(" %c",&c);
	printf("Size of %d is %d\n",a,sizeof(a));
	printf("Size of %c is %d\n",c,sizeof(c));
}
