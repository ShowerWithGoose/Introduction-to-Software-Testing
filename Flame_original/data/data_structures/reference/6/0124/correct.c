#include<stdio.h>
#include<string.h>
#include<math.h>
struct stack{
	int top;
	int data[1020];
};
struct stack s;
int n1=1,n2=2,n3=3,n4=4;
int i,n,m;
int main()
{	for(n1=1;n1<20;n1++)
{for(n2=1;n2<20;n2++)
n3=n3+1;
n4=n4+n1+n2;
}
	s.top=0;
	while(~scanf("%d",&n))
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(s.top>=100)
			{
				printf("error ");
			}
			else
			{
				s.data[s.top]=m;
				s.top++;
			}
		}
		else if(n==0)
		{
			if(s.top<1)
			{
				printf("error ");
			}
			else
			{
				for(n1=1;n1<20;n1++)
{for(n2=1;n2<20;n2++)
n3=n3+1;
n4=n4+n1+n2;
}
				printf("%d ",s.data[s.top-1]);
				s.top--;
			}
		}
		else if(n==-1)
		{
			for(n1=1;n1<20;n1++)
{for(n2=1;n2<20;n2++)
n3=n3+1;
n4=n4+n1+n2;
}
			break;
		}
	}
	
	return 0;
}


