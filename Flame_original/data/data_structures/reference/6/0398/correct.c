#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int z[100],c[1000],top=-1,top_2=-1;
int main()
{
	int i=0,j;
	while(i!=-1)
	{
		scanf("%d",&i);
		if(i==1)
		{
			if(top==99)
			{
				scanf("%d",&j);
				c[++top_2]=-1;
			}
			else
				scanf("%d",&z[++top]);
		}
		else if(i==0)
		{
			if(top==-1)
				c[++top_2]=-1;
			else
				c[++top_2]=z[top--];
		}
	}
	for(i=0;i<=top_2;i++)
	{
		if(c[i]==-1)
			printf("error ");
		else
			printf("%d ",c[i]);
	}
	return 0;
}

