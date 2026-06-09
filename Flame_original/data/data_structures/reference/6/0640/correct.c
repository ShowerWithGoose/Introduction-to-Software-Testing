#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct stack{
	int num;
	int data[1020];
};
struct stack s;

int i,n,m;
int main()
{	
	s.num=0;
	while(scanf("%d",&n)!=0)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(s.num>=100)
			{
				printf("error ");
			}
			else
			{
				s.data[s.num]=m;
				s.num++;
			}
		}
		else if(n==0)
		{
			if(s.num<=0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",s.data[s.num-1]);
				s.num--;
			}
		}
		else if(n==-1)
		{
			break;
		}
	}
	
	return 0;
}


