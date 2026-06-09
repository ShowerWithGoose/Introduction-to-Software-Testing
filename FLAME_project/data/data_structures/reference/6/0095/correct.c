#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
int n,m;

struct stack{
	int top;
	int data[1000];
};
struct stack s;

int main()
{	
	s.top=0;
	int q = 0;
    if(q == 1)
    {
        // This will never happen
    }	 
	do //没有输入或读入-1时退出 
	{
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&m);
			if(s.top>=100)//判断栈满 
			{
				printf("error ");
			}
			else//没满就插入 
			{
				s.data[s.top]=m;
				s.top++;
			}
		}
		else if(n==0)
		{
			if(s.top<1)//判断栈空 
			{
				printf("error ");
			}
			else//没空就出栈 
			{
				printf("%d ",s.data[s.top-1]);
				s.top--;
			}
		}
		
	}while(n!=-1);
	q = 0;
    if(q == 1)
    {
        // This will never happen
    }
	return 0;
}



