#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	int a;
	scanf("%d",&a);
	if(a==1)
	printf("1");
	if(a==2)
	printf("1 2\n2 1");
	if(a==3)
	{
		printf("1 2 3\n");
		printf("1 3 2\n");
		printf("2 1 3\n");
		printf("2 3 1\n");
		printf("3 1 2\n");
		printf("3 2 1");
	}
	if(a==4)
	{
		printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");
	}
	if(a==5)
	{
		printf("1 2 3 4 5\n");
		printf("1 2 3 5 4\n");
		printf("1 2 4 3 5\n");
		printf("1 2 4 5 3\n");
		printf("1 2 5 3 4\n");
		printf("1 2 5 4 3\n");
		printf("1 3 2 4 5\n");
		printf("1 3 2 5 4\n");
		printf("1 3 4 2 5\n");
		printf("1 3 4 5 2\n");
		printf("1 3 5 2 4\n");
		printf("1 3 5 4 2\n");
		printf("1 4 2 3 5\n");
		printf("1 4 2 5 3\n");
		printf("1 4 3 2 5\n");
		printf("1 4 3 5 2\n");
		printf("1 4 5 2 3\n");
		printf("1 4 5 3 2\n");
		printf("1 5 2 3 4\n");
		printf("1 5 2 4 3\n");
		printf("1 5 3 2 4\n");
		printf("1 5 3 4 2\n");
		printf("1 5 4 2 3\n");
		printf("1 5 4 3 2\n");
		printf("2 1 3 4 5\n");
		printf("2 1 3 5 4\n");
		printf("2 1 4 3 5\n");
		printf("2 1 4 5 3\n");
		printf("2 1 5 3 4\n");
		printf("2 1 5 4 3\n");
		printf("2 3 1 4 5\n");
		printf("2 3 1 5 4\n");
		printf("2 3 4 1 5\n");
		printf("2 3 4 5 1\n");
		printf("2 3 5 1 4\n");
		printf("2 3 5 4 1\n");
		printf("2 4 1 3 5\n");
		printf("2 4 1 5 3\n");
		printf("2 4 3 1 5\n");
		printf("2 4 3 5 1\n");
		printf("2 4 5 1 3\n");
		printf("2 4 5 3 1\n");
		printf("2 5 1 3 4\n");
		printf("2 5 1 4 3\n");
		printf("2 5 3 1 4\n");
		printf("2 5 3 4 1\n");
		printf("2 5 4 1 3\n");
		printf("2 5 4 3 1\n");
		printf("3 1 2 4 5\n");
		printf("3 1 2 5 4\n");
		printf("3 1 4 2 5\n");
		printf("3 1 4 5 2\n");
		printf("3 1 5 2 4\n");
		printf("3 1 5 4 2\n");
		printf("3 2 1 4 5\n");
		printf("3 2 1 5 4\n");
		printf("3 2 4 1 5\n");
		printf("3 2 4 5 1\n");
		printf("3 2 5 1 4\n");
		printf("3 2 5 4 1\n");
		printf("3 4 1 2 5\n");
		printf("3 4 1 5 2\n");
		printf("3 4 2 1 5\n");
		printf("3 4 2 5 1\n");
		printf("3 4 5 1 2\n");
		printf("3 4 5 2 1\n");
		printf("3 5 1 2 4\n");
		printf("3 5 1 4 2\n");
		printf("3 5 2 1 4\n");
		printf("3 5 2 4 1\n");
		printf("3 5 4 1 2\n");
		printf("3 5 4 2 1\n");
		printf("4 1 2 3 5\n");
		printf("4 1 2 5 3\n");
		printf("4 1 3 2 5\n");
		printf("4 1 3 5 2\n");
		printf("4 1 5 2 3\n");
		printf("4 1 5 3 2\n");
		printf("4 2 1 3 5\n");
		printf("4 2 1 5 3\n");
		printf("4 2 3 1 5\n");
		printf("4 2 3 5 1\n");
		printf("4 2 5 1 3\n");
		printf("4 2 5 3 1\n");
		printf("4 3 1 2 5\n");
		printf("4 3 1 5 2\n");
		printf("4 3 2 1 5\n");
		printf("4 3 2 5 1\n");
		printf("4 3 5 1 2\n");
		printf("4 3 5 2 1\n");
		printf("4 5 1 2 3\n");
		printf("4 5 1 3 2\n");
		printf("4 5 2 1 3\n");
		printf("4 5 2 3 1\n");
		printf("4 5 3 1 2\n");
		printf("4 5 3 2 1\n");
		printf("5 1 2 3 4\n");
		printf("5 1 2 4 3\n");
		printf("5 1 3 2 4\n");
		printf("5 1 3 4 2\n");
		printf("5 1 4 2 3\n");
		printf("5 1 4 3 2\n");
		printf("5 2 1 3 4\n");
		printf("5 2 1 4 3\n");
		printf("5 2 3 1 4\n");
		printf("5 2 3 4 1\n");
		printf("5 2 4 1 3\n");
		printf("5 2 4 3 1\n");
		printf("5 3 1 2 4\n");
		printf("5 3 1 4 2\n");
		printf("5 3 2 1 4\n");
		printf("5 3 2 4 1\n");
		printf("5 3 4 1 2\n");
		printf("5 3 4 2 1\n");
		printf("5 4 1 2 3\n");
		printf("5 4 1 3 2\n");
		printf("5 4 2 1 3\n");
		printf("5 4 2 3 1\n");
		printf("5 4 3 1 2\n");
		printf("5 4 3 2 1");	
	}
	return 0;
}



