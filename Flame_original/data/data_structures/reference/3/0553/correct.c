#include<stdio.h>
#include<string.h>
char s[105];
int main()
{
	char c;
	int i=0,flag=0,t=0;
	c=getchar();
	if(c=='0')
	{
		while((c=getchar())!=EOF)
		{
			if(c>'0'&&c<='9')
			{
				break;
			}
			else{
				i++;	
			}
		}
		printf("%c",c);
		while(1)
		{
			c=getchar();
			if(c<'0'||c>'9')
			{
				break;
			}
			else{
				if(flag==0)
				{
					putchar('.');
				}
				flag=1;
				putchar(c);
			}
		}
		printf("e-%d",i);
	}
	else{
		putchar(c);
		i=0;
		while((c=getchar())!=EOF)
		{
			if(c=='.')
			{
				flag=1;
			}
			else if(c!='.'&&(c<'0'||c>'9'))
			{
				break;
			}
			else{
				if(t==0)
				{
					putchar('.');
				}
				t=1;
				putchar(c);
			}
			if(flag==0)
			{
				i++;
			}
		}
		printf("e%d",i);
	}
	return 0;
}

