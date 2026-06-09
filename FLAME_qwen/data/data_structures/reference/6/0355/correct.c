#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int sta[200],top=-1;
int main()
{
	int x,n;
	while(scanf("%d",&x)!=EOF)
	{
		if(x==-1)
			break;
		else if(x==1)
		{
			scanf("%d",&n);
			if(top==99)
				printf("error ");
			else
				sta[++top]=n;
		}
		else if(x==0)
		{
			if(top==-1)
				printf("error ");
			else
				printf("%d ",sta[top--]);
		}
	}
	return 0;
}


