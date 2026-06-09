#include <stdio.h>
int put[110];
int op;
int num;
int top=0;
int main() {
	while (1) 
	{
		scanf("%d",&op);
		if(op==1)
			{
				
				if(top>=100)
					{
						printf("error ");
						continue;
					}
//				else 
//				{
					top++;
					scanf("%d",&num);
//				}
				put[top]=num;
			}
		if(op==0)
			{
				if(top-1<0)
					{
						printf("error ");
						continue;
					}
//				else
//					{
						printf("%d ",put[top]);
						top--;
//					}
			}
		if(op==-1)
			break;
		
	}
	return 0;
}
