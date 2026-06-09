#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[105];
	scanf("%s",s);
	int i,j,k,t,u;
	for(i=0;s[i]!='.'&&i<strlen(s);i++){;}
	if(s[0]=='0')
	{
		for(j=2;s[j]=='0';j++){;}
		printf("%c",s[j]);
		if(j+1!=strlen(s))
		{
			printf(".");
		}
		for(k=j+1;k<strlen(s);k++)
		{
			printf("%c",s[k]);
		}
		printf("e");
		printf("-%d",j-1);
	}
	else
	{
		printf("%c",s[0]);
		printf(".");
		for(t=1;t<i;t++)
		{
			printf("%c",s[t]);
		}
		for(u=i+1;u<strlen(s);u++)
		{
			printf("%c",s[u]);
		}
		printf("e");
		printf("%d\n",i-1);
	}
} 

