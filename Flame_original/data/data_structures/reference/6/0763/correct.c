#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct stack{
	int *data;
	int top;
	int size;
}Stack;
Stack *zhan;
int main()
{
	zhan=(Stack *)malloc(sizeof(Stack ));
	zhan->data=(int *)malloc(sizeof(int )*(100));
	zhan->top=-1;
	zhan->size=100;
	int x,n;
	while(scanf("%d",&x)!=-1)
	{
		if(x==1)
		{
			scanf("%d",&n);
			zhan->data[(zhan->top)+1]=n;
			zhan->top=zhan->top+1;
		}
		if(x==0)
		{
			if(zhan->top==-1)
			printf("error ");
			else {
				printf("%d ",zhan->data[zhan->top]);
				zhan->top=zhan->top-1;
			} 
		}
		if(x==-1)
		break;
	}
	return 0;
}

