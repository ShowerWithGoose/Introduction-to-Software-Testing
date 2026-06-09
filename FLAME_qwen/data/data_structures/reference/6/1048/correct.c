#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *left;
	struct stack *right;
} Stack;
int main()
{
	Stack *Head,*Node,*End;
	Head=(Stack *)malloc(sizeof(Stack));
	End=Head;
	int m,n,num;
	num=0;
	while(scanf("%d",&m)!=-1)
	{
		if(m==1)                    //ÈëÕ» 
		{
			if(num==100) 
			{
				printf("error "); 
			}
			else
			{
				num=num+1;
				scanf("%d",&n);
				Node=(Stack *)malloc(sizeof(Stack));
				Node->data=n;
				Node->left=End;
				End->right=Node;
				End=Node;
			}
		}
		if (m==0)              //³öÕ» 
		{
			if(num!=0)
			{
				num=num-1;
				printf("%d ",End->data);
				End=End->left;
				free(End->right);
			}
			else
			{
				printf("error ");
			}
		}
	}
	return 0;
}



