#include<stdio.h>
#include<string.h>
int main()
{
	char str[105];
	gets(str);
	int i,j=1,k=0,x;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='.')j=i;
		if(str[i]<='9'&&str[i]>'0'&&k==0)
		{
			printf("%c",str[i]);x=i;
			k=1;
			if(i!=strlen(str)-1)printf(".");
		}
		else if(str[i]<='9'&&str[i]>='0'&&k==1)printf("%c",str[i]);
	}
	if(j<x)
	printf("e%d",j-x);
	else printf("e%d",j-x-1);
	return 0;
}


