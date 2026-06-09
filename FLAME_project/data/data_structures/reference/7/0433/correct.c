#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct node{
	struct node*lson;
	struct node*rson;
	int content;
	int depth;
};
void Print(struct node*gen)
{//printf("%d ",gen->content);
	if(gen->lson==NULL&&gen->rson==NULL)
	{
		printf("%d %d\n",gen->content,gen->depth);
	}
	else
	{
		if(gen->lson!=NULL)
			Print(gen->lson);
		if(gen->rson!=NULL)
			Print(gen->rson);
	}
}
int main()
{
	int x,n; 
	scanf("%d",&n);
	struct node *gen;
	gen=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&gen->content);
	n--;
	gen->depth=1;
	gen->lson=NULL;
	gen->rson=NULL;
	struct node*k;
	while(n--)
	{
		scanf("%d",&x);
		k=gen;
		int flag=0;//1ÊÇ×ó 
		while(1)
		{
			if(x>=k->content)
			{
				if(k->rson==NULL)	break;
				k=k->rson;
			}
			else 
			{
				if(k->lson==NULL)
				{
					flag=1;
					break;
				}	
				k=k->lson;
			}
		}
		struct node*p=(struct node*)malloc(sizeof(struct node));
		p->lson=NULL;
		p->rson=NULL;
		p->content=x;
		p->depth=k->depth+1;
		if(flag==1)	k->lson=p;
		else k->rson=p;
	}
	//ÏÈÐ´¸öµÝ¹é°É
	Print(gen); 
	return 0;
} 

