#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Zhan{
	int top;
	int Shu[1000];
} s;
int main()
{
	int n,m;
	s.top=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(s.top<100)
			{
				s.top++;
				s.Shu[s.top]=m;
			}
			else
			{
				printf("error ");
			}
		}
		if(n==-1)
		{
			break;
		}
		if(n==0)
		{
			if(s.top>0)
			{
				printf("%d ",s.Shu[s.top]);
				s.top--;
			}
			else
			{
				printf("error ");
			}
		}
	}
	return 0;
}


