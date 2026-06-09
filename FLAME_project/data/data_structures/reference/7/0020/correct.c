#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int data;
	int depth;
	struct bst *lchild,*rchild;	
}tree,*Tree;
Tree root,p,q;
void print(Tree temp)
{
	if(temp!=NULL)
    {
        if(temp->lchild==NULL&&temp->rchild==NULL)
            printf("%d %d\n",temp->data,temp->depth);
        print(temp->lchild);
        print(temp->rchild);
        return NULL;
    }
    
}
int main()
{
	int n,x,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		q=(Tree)malloc(sizeof(tree));
	    q->data=x;
	    q->lchild=q->rchild=NULL;
	    q->depth=1;
	    if(root==NULL){
	        root=q;
	    }
	    else{
	    	p=root;
	        while(1)
	        {
	            if(x<p->data)
	            {
	                if(p->lchild==NULL)
	                {
	                    q->depth++;
	                    p->lchild=q;
	                    break;
	                }
	                else{
	                    q->depth++;
	                    p=p->lchild;
	                }
	            }
	            else
	            {
	                if(p->rchild==NULL){
	                    q->depth++;
	                    p->rchild=q;
	                    break;
	                }
	                else{
	                    q->depth++;
	                    p=p->rchild;
	                }
	            }
	        }
		}
		j=root;
	}
	print(j);
	return 0;
}


