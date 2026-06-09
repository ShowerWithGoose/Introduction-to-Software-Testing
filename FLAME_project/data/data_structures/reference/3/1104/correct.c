#include<stdio.h>
#include<string.h>
char s[300];
int main()
{
	gets(s);
	int i=0,l,n,m,x,y;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[0]!='0')
		{
			if(s[i]=='.')
			{
				n=i;
				m=n-1;
				printf("%c.",s[0]);
				for(i=1;i<n;i++)
				{
					printf("%c",s[i]);
				}
				for(i=n+1;i<l;i++)
				{
					printf("%c",s[i]);
				}
				printf("e%d",m);
				break;
			}
		}
		else if(s[0]=='0')
		{
			if(s[i]!='.'&&s[i]!='0')
			{
				n=i;
				m=n-1;
				if(i<l-1)
				{
				    printf("%c.",s[i]);
				    for(i=n+1;i<l;i++)
				    {
					    printf("%c",s[i]);
				    }
				    printf("e-%d",m);
				    break;
				}
				else
				{
					printf("%ce-%d",s[i],m);
					
				}
			}
		}
	}
	return 0;
}
