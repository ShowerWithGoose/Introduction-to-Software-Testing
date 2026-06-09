#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100];
int main()
{	int op,top=-1;
	while(1)
	{scanf("%d",&op);
	if(op==1)
	{top++;
	if(top<100)
	scanf("%d",&stack[top]);
	else
	{printf("error ");
	top--;
	}
	}
	else if(op==0)
	{if(top>=0)
	{printf("%d ",stack[top]);
	top--;
	}
	else
	printf("error ");
	}
	else if(op==0)
	break;
	}
	

return 0;
}


