#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    int num;
    struct data * left,* right;
}*root=NULL;
int count=1; // @@ [Using a global variable 'count' to track height is incorrect because it doesn't represent the actual depth of the current node during traversal; height should be passed as a parameter or computed differently.]
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
    printf("%d %d\n",p->num,count); // @@ [Printing 'count' here assumes it reflects the current node's height, but due to flawed increment/decrement logic and global state, it does not correctly represent the height of the leaf node.]
    }
    else
    {count++; // @@ [Incorrectly increments 'count' before recursing; this disrupts the height tracking because multiple recursive paths interfere with the same global variable.]
    leafprint(p->left);
    leafprint(p->right);
    count--; // @@ [Decrementing after recursion may not restore correct height due to interleaved recursive calls modifying the same global 'count'.]
    }    
}
int main()
{    int n,i=0,item;
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {    scanf("%d",&item);
        root=insertBST(root,item);                    
    }
    
    leafprint(root); // @@ [Calling leafprint on an empty tree (if n==0) would cause a segmentation fault since p is NULL and p->left is accessed without checking.]

return 0;
}