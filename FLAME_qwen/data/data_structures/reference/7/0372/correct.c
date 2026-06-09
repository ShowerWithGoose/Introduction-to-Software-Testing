#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct bst{
	int data;
	int high;
	struct bst *left,*right;
};
typedef struct bst node,*nodep;
int len=0;
nodep insert(nodep p,int m,int high)
{
	len++;
	if(p==NULL)
	{
        p=(nodep)malloc(sizeof(node));
        p->data=m;
        p->left=p->right=NULL;
        p->high=len;
    }
    else if(m<p->data)
        p->left=insert(p->left,m,len);
    else if(m>=p->data)
       p->right=insert(p->right,m,len);
  	return p;   
}
void print(nodep root)
{
    if(root)
    {
        if(!(root->left)&&!(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
        print(root->left);
        print(root->right);
    }
}
int main()
{
	int i,n,m;
	scanf("%d",&n);
	nodep root=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		len=0;
		root=insert(root,m,len);
	}
	print(root);
	return 0;
}

