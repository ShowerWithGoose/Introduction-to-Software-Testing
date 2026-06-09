#include<stdio.h>
#include<string.h>

#include<stdlib.h>

struct stack{
	int x;
	int y[1020];
};
struct stack s;


int main()
{	
	s.x=0;
	int i,n,m;
	while(~scanf("%d",&n))
	{
		if(1==n){
			scanf("%d",&m);
			if(s.x>=100){
				printf("error ");
			}
			else{
				s.y[s.x]=m;
				s.x++;
			}
		}
		else if(0==n){
			if(s.x<1){
				printf("error ");
			}
			else{
				printf("%d ",s.y[s.x-1]);
				s.x--;
			}
		}
		else if(-1==n)
		{
			break;
		}
	}
	
	return 0;
}

