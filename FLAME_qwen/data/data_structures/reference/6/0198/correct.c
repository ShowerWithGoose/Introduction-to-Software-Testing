#include<stdio.h>
#define MAX 100
int main()
{
	int s[MAX];
	int n;int top=-1;int l;
	do{
		scanf("%d ",&n);
		if(n==1)
		{
			scanf("%d ",&l);
			if(top!=99)
			{
			    top++;
				s[top]=l;
			}
			else printf("error ");
		}
		else if(n==0)
		{
			if(top!=-1)
			{
				printf("%d ",s[top]);
			    top--;
			}
			else printf("error ");
		}
	}
	while(n!=-1); 
	return 0;
}

