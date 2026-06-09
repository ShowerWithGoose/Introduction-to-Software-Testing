#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAXSIZE 100
int data[MAXSIZE];
int main()
{
	int flag, n;
	int top=-1;
	int tmp;
	while(scanf("%d",&flag)!=EOF)
	{
		if(flag==1)
		{
			if(top>=MAXSIZE-1)
			{
				printf("error ");
				continue;
			}
			
		
			else
			{
				scanf("%d",&n);
				data[top+1] = n;
				top++;
			}
		}
		else if(flag==0)
		{
			if(top==-1)
			{
				printf("error ");
				continue;
			}
			else
			{
				printf("%d ",data[top]);
				top--;
			}
		}
		else if(flag==-1)
		break;
	}
	return 0;
}

