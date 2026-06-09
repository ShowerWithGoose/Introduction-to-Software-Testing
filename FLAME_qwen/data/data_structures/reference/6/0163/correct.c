#include <stdio.h>
int main()
{
	int a[105],top=-1,op;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==-1) break;
		if(op==1) scanf("%d",&a[++top]);
		if(op==0) 
		{
			if(top==-1) printf("error ");
			else printf("%d ",a[top--]);
		}
	}
	return 0;
} 

