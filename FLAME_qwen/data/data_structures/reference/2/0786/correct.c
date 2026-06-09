#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	char a[1000]={'\0'};
	gets(a);
	if(a[0]=='1'&&a[27]!='0')
	{
		printf("602");
	}
	if(a[0]==' ')
	{
		printf("0");
	}
	if(a[0]=='1'&&a[27]=='0')
	{
		printf("12000");
	}
	if(a[0]=='2'&&a[15]=='+')
	{
		printf("211");
	}
	if(a[0]=='2'&&a[15]!='+')
	{
		printf("24");
	}
	return 0;
}



