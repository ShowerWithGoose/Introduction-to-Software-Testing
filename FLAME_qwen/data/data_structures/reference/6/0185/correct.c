#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100];

int main()
{
	int top=-1;
	char str[500];
	int s[500];
	int j=0;
	gets(str);
	char *p=str,*q=p;
	while(strchr(p,' ')!=NULL)
	{
		q=strchr(p,' ');
		*q='\0';
		s[j++]=atoi(p);
		p=q+1;
	}
	s[j]=atoi(p);
	int i;
	for(i=0;i<=j;i++)
	{
		if(s[i]==-1)
		return 0;
		else if(s[i]==0)
		{
			if(top==-1)
			printf("error ");
			else
			{
				printf("%d ",stack[top--]);
			}
		}
		else if(s[i]==1)
		{
			i++;
			stack[++top]=s[i];
		}
	}
	
	
	
	return 0;
 } 

