#include<stdio.h>
struct branch{
	int num;
	struct branch *left;
	struct branch *right;
	int du;
};
typedef struct branch Branch;
typedef struct branch *branchptr;
Branch *p,*q,*root;
void search(Branch *p);
int main()
{
	int n,i,temp,count;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %d",&temp);
		if(root==NULL)	
		{
			p=(branchptr)malloc(sizeof(Branch));
		    p->left=NULL;
		    p->right=NULL;
			root=p;
			p->num=temp;
			p->du=1;
		}
		else
		{
			p=root;
			q=(branchptr)malloc(sizeof(Branch));
			q->left=NULL;
		    q->right=NULL;
		    q->num=temp;
			while(1)
			{
				if(temp>=p->num) 
				{
					if(p->right!=NULL)p=p->right;
					else 
					{
						p->right=q;
						break;
					}
				}
				else 
				{
					if(p->left!=NULL)p=p->left;
					else 
					{
						p->left=q;
						break;
					}
				}
				count++;
			}								    
		    q->du=count+1;
		    count=1;
		 } 
	}
	p=root;
	search(root);
 } 
void search(Branch *p)
{
	if(p->left==NULL&&p->right==NULL) 
	{
		printf("%d %d\n",p->num,p->du);
		return;
	}
	if(p->left!=NULL) search(p->left);
	if(p->right!=NULL)search(p->right); 
	return;
}



