#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	char *p=NULL;
	int i,j;
	scanf("%s",s);
	int len=strlen(s);
	p=strchr(s,'.');
	if(p==NULL)
	{
		puts(s);
	}
	else if(p-s==1)
	{
		if(s[0]=='0')
		{
			for(i=0;i<len;i++)
			{
				if(s[i]!='0'&&s[i]!='.')
				{
					j=i;
					break;
				}
			}
			if(j==len-1)//如0.0000000000x型
			{
				printf("%c",s[j]);
				printf("e-%d",j-1);
			} 
			else//如0.0000000abcd型 
			{
				printf("%c",s[j]);
				printf(".");
				for(i=j+1;s[i]!='\0';i++)
				{
					printf("%c",s[i]);
				}
				printf("e-%d",j-1);
			}
		}
		else//如x.asdhfklasjfh型
		{
			for(i=0;i<len;i++)
			{
				printf("%c",s[i]);
			}
			printf("e0");
		} 
	}
	else
	{
		j=p-s;//小数点的位置
		printf("%c",s[0]);
		printf(".");
		for(i=1;i<p-s;i++)
		{
			printf("%c",s[i]);
		} 
		for(i=p-s+1;s[i]!='\0';i++) 
		{
			printf("%c",s[i]);
		}
		printf("e%d",j-1);
	}
	return 0;
}
	




