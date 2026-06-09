#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{	int num;
	struct stack *front;
	struct stack* behind;
};
int main()
{	int op,count=0;
	struct stack *head,*end,*p;
	head=end=NULL;
	scanf("%d",&op);
	while(op!=-1)
	{	p=(struct stack*)malloc(sizeof(struct stack));
		if(op==1)
		{	scanf("%d",&p->num);
			p->behind=NULL;
			if(count==100)
			printf("error ");
			else
			{	if(head==NULL)
				{	head=end=p;
					count++;
				}
				else
				{	end->behind=p;
					p->front=end;
					end=p;
					count++;
				}
			}
		}
		else
		{	if(count==0)
			printf("error ");
			else
			{	printf("%d ",end->num);
				if(count==1)
				head=end=NULL;
				else
				{	end=end->front;
					end->behind=NULL;
				}
				count--;
			}
		}
		scanf("%d",&op);
	}
	return 0;
} 

