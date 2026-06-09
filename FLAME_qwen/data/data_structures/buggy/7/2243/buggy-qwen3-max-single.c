#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    int num;
    struct data * left,* right;
}*root=NULL;
int count=1; // @@ [Using a global variable 'count' to track height is incorrect because it doesn't represent the actual depth of the current node in the recursive traversal. Height should be passed as a parameter or computed based on recursion depth, not modified globally during traversal.]
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
    printf("%d %d\n",p->num,count); // @@ [Printing 'count' here assumes it reflects the current node's height, but due to flawed global state management during recursion (incrementing before recursing and decrementing after), it does not correctly track the height of leaf nodes.]
    }
    else
    {count++; // @@ [Incorrectly increments global 'count' before traversing children, which corrupts height tracking for sibling subtrees. Height should be passed down as a parameter, not managed via a global variable.]
    leafprint(p->left);
    leafprint(p->right);
    count--; // @@ [Decrementing global 'count' after recursion leads to incorrect height values when backtracking, especially when one subtree is deeper than another. This approach cannot correctly maintain per-path depth.]
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