#include<stdio.h>
#include<string.h>
struct stack{
	int top;
	int data[1000];
};
struct stack f;
int n,m;
int main()
{	
	f.top=0;
	while(~scanf("%d",&n))
	{
		switch(n)
		{
			case 1:
				scanf("%d",&m);
			if(f.top>=100)
				printf("error ");
			else
			{
				f.data[f.top]=m;
				f.top++;
			}
			break;
			case 0:
				if(f.top<1)
				printf("error ");
			else
			{
				printf("%d ",f.data[f.top-1]);
				f.top--;
			}
			break;
			case -1:
				break;
		}
	}
	
	return 0;
}

