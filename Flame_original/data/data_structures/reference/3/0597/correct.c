#include<stdio.h>
#include<string.h>
char s[200];
int main()
{
	int c,i,p,k,t,p1,p2;
	gets(s);
	c=strlen(s);
	for(i=0;i<c;i++)
	{
		if(s[i]=='.')
		{
			p=i;
			break;
		}
	}
    if(s[0]=='0')
    {
    	for(k=p+1;k<c;k++)
    	{
    		if(s[k]!='0')
    		{p1=k;
    		break;
			}
		}
		printf("%c",s[p1]);
		if(p1!=c-1)
		printf(".");
		for(k=p1+1;k<c;k++)
		printf("%c",s[k]);
		printf("e-%d",p1-p);
		return 0;
	}
	else
	{
		printf("%c.",s[0]);
		for(t=1;t<c;t++)
		{
			if(s[t]!='.')
			printf("%c",s[t]);
		}
		printf("e%d",p-1);
		return 0;
	}
}

