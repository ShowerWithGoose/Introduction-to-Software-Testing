#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
	int data;
	int deep;
	struct node *lchild,*rchild;
}Treenode,*BTREE;
int num[100]={0};
int ans[100]={0};
int h[100]={0};

void inorder(BTREE T,int *j)
{
	if(T!=NULL)
	{
		inorder(T->lchild,j);
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			ans[(*j)]=T->data;
			h[(*j)]=T->deep;
			(*j)++;
		}
		inorder(T->rchild,j);
	}
}

int main()
{
	int n,i=0,j=0;
	BTREE T,q,p;
	scanf("%d",&n);
	T=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		p=(BTREE)malloc(sizeof(Treenode));
	    p->data=num[i];
	    p->deep=1;
	    p->lchild=NULL;
	    p->rchild=NULL;
	    if(T==NULL)
	    T=p;
	    else
	    {
	    	q=T;
	    	while(1)
	    	{
	    		if(num[i]<q->data)
	    		{
	    			if(q->lchild!=NULL)
	    			{
	    				q=q->lchild;
	    				p->deep=p->deep+1;
					}
					else
					{
						q->lchild =p;
						p->deep=p->deep+1;
						break;
					} 
				}
				else
				{
					if(q->rchild !=NULL)
					{
						q=q->rchild;
						p->deep=p->deep+1;
					}
					else
					{
						q->rchild=p;
						p->deep=p->deep+1;
						break;
					}
				}
			}
		}
	}
	inorder(T,&j);
	for(i=0;i<j;i++)
	{
		printf("%d %d\n",ans[i],h[i]);
	}
	return 0;
}
