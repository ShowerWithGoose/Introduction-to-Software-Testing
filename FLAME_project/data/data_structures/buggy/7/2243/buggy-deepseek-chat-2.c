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
    p->num=item; // @@ Error: The field 'num' is being used to store the value, but the problem requires storing the height in a separate field. The reference program uses 'data' for value and 'num' for height. Here, 'num' is used for the value, and there is no field to track the height of the node.
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
    printf("%d %d\n",p->num,count); // @@ Error: 'count' is a global variable that is incremented/decremented during traversal, but it does not correctly represent the height of each leaf node. The height should be computed recursively based on the depth from the root, not by a global counter that is shared across different branches.
    }
    else
    {count++; // @@ Error: Incrementing count before traversing children incorrectly modifies the height for sibling subtrees. This will cause incorrect height values for leaf nodes.
    leafprint(p->left);
    leafprint(p->right);
    count--; // @@ Error: Decrementing count after traversal does not restore the correct height context because the counter is global and affects all recursive calls.
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