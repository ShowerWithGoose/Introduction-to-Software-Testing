#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>	
typedef struct node
{
	int inum;
	struct node *lc;
	struct node *rc;
	int dep;
}BTnode,*BTree;
void mvisit(BTree T)
{
	if(T)
	{
		mvisit(T->lc);
		if(T->lc==NULL&&T->rc==NULL)
			printf("%d %d\n",T->inum,T->dep);
		mvisit(T->rc);
	}
}
int main()
{
	int nums[200]={},n,i;
	scanf("%d",&n);
	BTree T;
	scanf("%d",&nums[0]);
	T=(BTree)malloc(sizeof(BTnode));
	T->inum=nums[0];
	T->dep=1;
	T->lc=NULL;
	T->rc=NULL;
	BTree p=T;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d",&nums[i]);
		BTree S;
		S=(BTree)malloc(sizeof(BTnode));
		S->lc=NULL;
		S->rc=NULL;
		S->dep=1;
		S->inum=nums[i];
		while(1)
		{
			if(S->inum<p->inum)
			{
				if(p->lc!=NULL)
				{
					p=p->lc;
					S->dep++;
				}	
				else
				{
					S->dep++;
					p->lc=S;
					break;
				}
			}
			else
			{
				if(p->rc!=NULL)
				{
					p=p->rc;
					S->dep++;	
				}
				else
				{
					S->dep++;
					p->rc=S;
					break;
				}
			}
				
		}
		p=T;
		
	}
	mvisit(T);
	return 0;
	
	
	
}

