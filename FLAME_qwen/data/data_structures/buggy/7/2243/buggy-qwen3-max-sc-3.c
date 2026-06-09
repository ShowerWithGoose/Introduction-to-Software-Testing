#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    int num;
    struct data * left,* right;
}*root=NULL;
int count=1; // @@ [Using a global variable 'count' to track height is incorrect because it doesn't represent the actual depth of the current node during traversal; height should be passed as a parameter or computed differently. Also, this causes wrong height values for leaf nodes when backtracking.]
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
    printf("%d %d\n",p->num,count); // @@ [Printing 'count' as height is incorrect because 'count' is a global variable that does not accurately reflect the current node's height in the tree due to shared state across recursive calls.]
    }
    else
    {count++; // @@ [Incrementing a global 'count' before recursing assumes both children exist and share the same incremented height, which breaks the independent height tracking needed for left and right subtrees.]
    leafprint(p->left);
    leafprint(p->right);
    count--; // @@ [Decrementing global 'count' after recursion leads to incorrect height values because multiple recursive paths interfere with each other through this shared variable.]
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