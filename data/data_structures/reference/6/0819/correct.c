#include<stdio.h>

int main()
{
	int ctl ,stack[110] ,top = 0;
	scanf("%d",&ctl);
	while(ctl != -1){
		if(ctl == 1)
			scanf("%d",&stack[top++]);
		else if(top > 0)
			printf("%d ",stack[(top--) - 1]);
		else 
			printf("error ");
		scanf("%d",&ctl);
	}
}


