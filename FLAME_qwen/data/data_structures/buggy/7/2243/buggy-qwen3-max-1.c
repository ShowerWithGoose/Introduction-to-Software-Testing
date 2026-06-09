#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    int num;
    struct data * left,* right;
}*root=NULL;
int count=1; // @@ [Using a global variable 'count' to track height is incorrect because it doesn't represent the actual depth of the current node during traversal; height should be passed as a parameter or tracked via recursion stack, not a shared global state.]
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
    printf("%d %d\n",p->num,count); // @@ [Printing 'count' here is wrong because 'count' does not correctly reflect the height of the current leaf node due to flawed global state management during traversal.]
    }
    else
    {count++; // @@ [Incrementing a global 'count' before recursing assumes both subtrees share the same depth, which breaks when backtracking; this leads to incorrect height values for leaves in different branches.]
    leafprint(p->left);
    leafprint(p->right);
    count--; // @@ [Decrementing global 'count' after recursion fails to correctly restore height context for sibling or parent nodes, causing inconsistent and incorrect height tracking.]
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