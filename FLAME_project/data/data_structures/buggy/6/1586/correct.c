#include<stdio.h>
typedef struct haha
{
	int x;
	int y[1000];
}haha;
int main()
{
	haha s;
	s.x=0;
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		if(a==1)
		{
			if(s.x!=100){
			scanf("%d",&s.y[s.x++]);
		}
		else if(s.x==100)
		{
			printf("error ");
		}
		
		}
		else if(a==0)
		{
			if(s.x==0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",s.y[--s.x]);
			}
			
		}
		else if(a==-1)
			{
				break;
			}
	}
	return 0;
}
