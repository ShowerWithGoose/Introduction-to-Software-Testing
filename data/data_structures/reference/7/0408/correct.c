#include <stdio.h>
#include <malloc.h>
typedef struct Tnode{  //可以在结构体中加入high 
	int data;
	struct Tnode *left;
	struct Tnode *right;
}link;
link *p,*head,*r,*q;

int high=1;
void PreOrderPrintnLeaves(link *BT) //NB!!!  
{
	if(BT)
	{
		if(!BT->left&&!BT->right) 
			printf("%d %d\n",BT->data,high);
	    else
	    {
	    	high++;
		    PreOrderPrintnLeaves(BT->left);
		    PreOrderPrintnLeaves(BT->right);
		    high--;
		}
	}
}
int main()
{
	int n,i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		r=(link*)malloc(sizeof(link));
		if(i==0)
		{
			head=p=r;
			head->data=num;
			head->left=NULL,head->right=NULL;
		}
		else
		{
			while(p)
			{
				if(num<p->data) 
				{
					q=p;
					p=p->left;
				}
				else
				{
					q=p;
					p=p->right;
				}
			}
			if(num<q->data) p=q->left=r;
			else p=q->right=r; 
			p->data=num;
			p->left=p->right=NULL;
			p=head; 
		}
		
 }
	PreOrderPrintnLeaves(p);
	return 0;
}

