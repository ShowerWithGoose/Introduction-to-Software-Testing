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
    leafprint(p->left); // @@ [The height tracking using a global 'count' variable is incorrect because it does not represent the actual depth of the current node in the tree. The count is incremented before traversing children, but this approach fails when backtracking and does not correctly reflect the height of leaf nodes. Additionally, if p is NULL, this function will crash due to dereferencing a null pointer.]
    leafprint(p->right); // @@ [Same issue as above: no null check before accessing p->left or p->right, and incorrect height calculation using a global counter.]
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
    
    leafprint(root); // @@ [If the input n is 0, root will be NULL, and calling leafprint(NULL) will cause a segmentation fault because the function immediately accesses p->left and p->right without checking if p is NULL.]

return 0;
}