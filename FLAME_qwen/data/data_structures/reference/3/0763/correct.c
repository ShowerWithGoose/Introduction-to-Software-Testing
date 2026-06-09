#include<stdio.h>
int main()
{
	int n,x=1;
	char a[1000];
	scanf("%s",&a);
	if(a[0]!='0')
	{
	for(n=0;a[n]!='.';n++)
	x=n;
	printf("%c.",a[0]);
	for(n=1;a[n]!='\0';n++)
	{
		if(a[n]!='.')
		printf("%c",a[n]);
	}
	printf("e%d",x);
    }
    else {
    	for(n=2;a[n]=='0';n++)
    	x=n;
    	printf("%c",a[n]);
    	if(a[x+2]!='\0')
    	printf(".");
    	for(n=x+2;a[n]!='\0';n++)
    	printf("%c",a[n]);
    	printf("e-%d",x);
	}
	return 0;
}

