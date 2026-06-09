#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define Status int
int fudian(char s[],int L);
int main()
{
	char s[200];
	gets(s);
	int L, k, p;
	L=strlen(s);
	if(s[0]=='0')//首位为0 
	{
		for(int i=2;i<L;i++)
		{
			if(s[i]!='0')	
			{
				if(i==L-1)
				{
					printf("%ce%d\n",s[i],-i+1);
					break;
				}
				else
				{
					printf("%c.",s[i]);
					for(int j=i+1;j<L;j++)
						printf("%c",s[j]);
					printf("e%d\n",-i+1);
					break;
				}
			}
		}
	}
	else	//首位不为0 
	{
		for(int i=0;i<L;i++)
		{
			if(s[i]=='.')
			{
				for(p=i+1;p<L;p++)
					s[p-1]=s[p];
				printf("%c.",s[0]);
				for(int j=1;j<L-1;j++)
					printf("%c",s[j]);
				printf("e%d\n",i-1);
				break;
			}
			else if(fudian(s,L))
			{
				printf("%c.",s[0]);
				for(int j=1;j<L;j++)
					printf("%c",s[j]);
				printf("e%d\n",L-1);
				break;
			}
		}
	}
	return 0;
}
int fudian(char s[],int L)
{
	for(int i=0;i<L;i++)
		if(s[i]=='.')
			return 0;
	return 1;
} 



