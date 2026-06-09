#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
	int high;
};
struct node *root=NULL,*p,*q;
int n,cnt=1,i,D[1005];
void lorder(struct node* t)
{
	if(t!=NULL)
	{
		cnt++;
		lorder(t->left );		
		if((t->left == NULL ) && (t->right == NULL))
		{
			printf("%d %d\n",t->data ,t->high );
		}
		lorder(t->right );
	}
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&D[i]);
	}
	
	for(i=0;i<n;i++)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data = D[i];
		p->left = NULL;
		p->right = NULL;
		p->high = 1;
		if(root==NULL)
		{
			root = p;
		}
		else
		{
			q=root;
			while(1)
			{
				if(D[i]<q->data )
				{
					if(q->left == NULL)
					{
						p->high ++;
						q->left = p;
						break;
					}
					else 
					{
						q=q->left ;
						p->high ++;
					}	
				}
				else if(D[i]>=q->data )
				{
					if(q->right ==NULL)
					{
						p->high ++;
						q->right = p;
						break;
					}
					else 
					{
						q=q->right ;
						p->high ++;
					}
				}
			} 
		}
	}
	lorder(root);
	return 0;
}

