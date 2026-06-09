#include<stdio.h>
#include<string.h> 

int main()
{
	char s[100];
	scanf("%s",s);
	char*p,*q;
	p=s;
	int i;
	char j;
	for(i=0;i<strlen(p);i++)
	{
		if(p[i]=='-')
		{
			if(p[i-1]>='a'&&p[i-1]<='z'&&p[i+1]>='a'&&p[i+1]<='z')
			{
				q=p;
				q[i]='\0';
				printf("%s",q);
				for(j=p[i-1]+1;j<p[i+1];j++)
				{
					printf("%c",j);
				}
				p=&p[i+1];
				i=0;
			}
			else if(p[i-1]>='A'&&p[i-1]<='Z'&&p[i+1]>='A'&&p[i+1]<='Z')
			{
				q=p;
				q[i]='\0';
				printf("%s",q);
				for(j=p[i-1]+1;j<p[i+1];j++)
				{
					printf("%c",j);
				}
				p=&p[i+1];
				i=0;
			}
			else if(p[i-1]>='0'&&p[i-1]<='9'&&p[i+1]>='0'&&p[i+1]<='9')
			{
			q=p;
				q[i]='\0';
				printf("%s",q);
				for(j=p[i-1]+1;j<p[i+1];j++)
				{
					printf("%c",j);
				}
				p=&p[i+1];
				i=0;
			}
		}	
	}
	printf("%s",p);
	
	return 0;
 } 



