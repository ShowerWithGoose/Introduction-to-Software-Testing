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
    p->num=item; // @@ Error: The field 'num' is used to store the value, but the height is not stored separately. The reference program stores height in a separate field 'num' and the value in 'data'. Here, the value is stored in 'num', but the height is tracked globally with 'count', which is incorrect for determining leaf heights.
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
    printf("%d %d\n",p->num,count); // @@ Error: The height printed is the global 'count' variable, which does not represent the actual height of the leaf node. The height should be the depth from the root (root height = 1), but this code increments and decrements 'count' during traversal, leading to incorrect heights.
    }
    else
    {count++; // @@ Error: Incrementing 'count' before recursive calls changes the global height for all subsequent nodes, but it is not properly reset for sibling subtrees, causing incorrect height values.
    leafprint(p->left);
    leafprint(p->right);
    count--; // @@ Error: Decrementing 'count' after recursive calls attempts to backtrack, but due to the order of operations, the height for leaf nodes is not correctly computed.
    }    
}
int main()
{    int n,i=0,item;
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {    scanf("%d",&item);
        root=insertBST(root,item);                    
    }
    
    leafprint(root);

return 0;
}