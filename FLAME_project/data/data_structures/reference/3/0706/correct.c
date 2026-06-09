#include<stdio.h>
#define M 108
char s[M];
int main()
{
	gets(s);
	int l=0,r=0,i,flag=0,p;
	for(i=0;s[i]!='.';i++)
	l++;
	for(i+=1;s[i]!='\0';i++)
	r++;
	if(l==1&&s[0]=='0')
	{
		for(i=2;s[i]!='\0';i++)
		{
			if(s[i]!='0'&&flag==0)
			{
				flag=1;
				printf("%c",s[i]);
				p=i-1;
				if(s[i+1]!='\0')
				printf(".");
				continue;
			}
			if(flag==1)
			printf("%c",s[i]);
		}
		printf("e-%d",p);
	}
	else if(l==1)
	{
		printf("%s",s);
		printf("e0"); 
	}
	else if(l>1)
	{
		printf("%c.",s[0]);
		for(i=1;i<l;i++)
		printf("%c",s[i]);
		for(i=l+1;s[i]!='\0';i++)
		printf("%c",s[i]);
		printf("e%d",l-1);
	}
	return 0;
}

