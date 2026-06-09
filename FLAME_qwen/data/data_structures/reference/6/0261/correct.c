#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
	int op,st[100],t=0,num;
	while(scanf("%d",&op))
	{
		if(op==1)
		{
			scanf("%d",&num);
			if(t==100) printf("error ");
			else 
			{
				st[t]=num;
				t++;
			}
		}
		else if(op==0)
		{
			if(t==0) printf("error ");
			else
			{
				printf("%d ",st[t-1]);
				st[t]=0;
				t--;
			}
		}
		else if(op==-1) return 0;
	}
}

