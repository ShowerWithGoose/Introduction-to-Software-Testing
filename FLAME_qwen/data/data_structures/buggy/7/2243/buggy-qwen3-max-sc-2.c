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
    printf("%d %d\n",p->num,count);
    }
    else
    {count++;
    leafprint(p->left); @@ [The height (count) is incremented before traversing children, but if p->left is NULL, the recursive call will dereference a null pointer, causing undefined behavior or crash.]
    leafprint(p->right); @@ [Same issue: if p->right is NULL, this call will crash because leafprint does not check for NULL at the start.]
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
    
    leafprint(root); @@ [If the tree is empty (n=0), root is NULL, and leafprint will immediately dereference NULL, causing a crash.]

return 0;
}