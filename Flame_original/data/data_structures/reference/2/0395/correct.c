#include <stdio.h>
#include <string.h>
int ji(int a,int b,char c);
int main()
{
	int a[2];
	char b[1];
	scanf("%d",&a[0]);
	scanf(" %c",&b[0]);
	while(b[0] != '=')
	{
		scanf("%d",&a[1]);
		if((b[0] == '*') ||(b[0] == '/'))
		{
			
			a[0]=ji(a[0],a[1],b[0]);
			scanf(" %c",&b[0]);
		}
		else if((b[0] == '+') || (b[0] == '-'))
		{
			char b1;
			int next;
			scanf(" %c",&b1);
			if((b1 != '=' ) && (b1 == '+' || b1 == '-'))
			{
				
				a[0]=ji(a[0],a[1],b[0]);
				b[0]=b1;
				
			}
			else if(b1 == '=')
			{
				a[0]=ji(a[0],a[1],b[0]);
				break;
			}
			else
			{
				while((b1 != '=') && (b1 == '*' || b1 == '/'))
				{
					scanf("%d",&next);
					a[1]=ji(a[1],next,b1);
				
					scanf(" %c",&b1);
				}
				if(b1 == '=')
				{
					a[0]=ji(a[0],a[1],b[0]);
					break;
				}
				else
				{
					a[0]=ji(a[0],a[1],b[0]);
					b[0]=b1;
				}
			
			}
		
				
		}	
	}
	printf("%d",a[0]);
	
	return 0;
}

int ji(int a,int b,char c)
{
	int ret=0;
	if(c == '*')
		ret = a * b;
	else if(c == '/')
		ret = a / b;
	else if(c == '+')
		ret = a + b;
	else if(c == '-')
		ret = a - b;
	return ret;
}

