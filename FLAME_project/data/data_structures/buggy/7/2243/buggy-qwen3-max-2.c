#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    int num;
    struct data * left,* right;
}*root=NULL;
int count=1;
struct data *insertBST(struct data *p,int item)
{    if(p==NULL)
    {p=(struct data *)malloc(sizeof(struct data));
    p->num=item;
    p->left=p->right=NULL;
    }
    else if(item<p->num)
    {p->left=insertBST(p->left,item);
    }
    else if(item>=p->num)
    {p->right=insertBST(p->right,item);
    }
    
    return p;
}
void leafprint(struct data *p)
{    if(p->left==NULL && p->right==NULL)
    {
    printf("%d %d\n",p->num,count); // @@ [The 'count' variable is global and shared across recursive calls, so it does not correctly represent the height of each individual leaf node. Height should be passed as a parameter or stored in the node during insertion.]
    }
    else
    {count++;
    leafprint(p->left); // @@ [When p->left is NULL, calling leafprint(p->left) leads to dereferencing a NULL pointer in the next call, causing a runtime error. The function does not check if p is NULL before accessing p->left and p->right.]
    leafprint(p->right); // @@ [Same issue as above: if p->right is NULL, this will cause a NULL pointer dereference in the recursive call.]
    count--;
    }    
}
int main()
{    int n,i=0,item;
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {    scanf("%d",&item);
        root=insertBST(root,item);                    
    }
    
    leafprint(root); // @@ [If the tree is empty (n=0), root is NULL, and leafprint will immediately dereference NULL, causing a runtime error. Also, even for non-empty trees, leafprint lacks a base case for NULL input.]

return 0;
}