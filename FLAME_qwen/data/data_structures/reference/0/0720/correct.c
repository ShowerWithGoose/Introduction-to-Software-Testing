#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100010
int istype(char a,char b)
{
	if(isdigit(a)&&isdigit(b))return 1;
	else if(isupper(a)&&isupper(b))return 1;
	else if(islower(a)&&islower(b))return 1;
	else return 0;
}
char s[MAX];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	int i=0;
	while(i<=len-1)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
			i++;
		}
		else
		{
			if(i==0)
			{
				printf("%c",s[i]);
				i++;
			}
			else
			{
				if(istype(s[i-1],s[i+1]))
				{
					int num=s[i+1]-s[i-1];
					for(int j=1;j<=num;j++)printf("%c",s[i-1]+j);
					i+=2;
				}
				else
				{
					printf("%c",s[i]);
					i++;
				}
			}
		}
	}
	return 0;
}


