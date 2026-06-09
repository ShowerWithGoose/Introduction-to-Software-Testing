#include <stdio.h>
int main()
{
	int head=1,tail=1;
	int que[105]={0};
	int x,tmp;
	while(~scanf("%d ",&x))
	{
		switch(x)
		{
			//入栈 
			case 1:{
				//栈满时入栈 
				if(tail==100)printf("error ");
				else{
					tail++;
					scanf("%d",&tmp);
					que[tail]=tmp; 
				}
				break;
			}
			
			//出栈 
			case 0:{
				//栈空时出栈 
				if(head==tail)printf("error ");
				else{
					printf("%d ",que[tail]);
					tail--;
				}
				break;
			}
			
			//结束	
			case -1:break;
		}
	}
	
	return 0;
}

