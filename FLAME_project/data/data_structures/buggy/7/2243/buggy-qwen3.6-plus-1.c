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
{    if(p==NULL) return; // @@ The function does not check for NULL pointer before accessing members, causing Runtime Error when traversing empty subtrees. Also, the logic for tracking height using a global variable is flawed for in-order traversal of leaves, but the immediate crash is due to missing NULL check.
    if(p->left==NULL && p->right==NULL)
    {
    printf("%d %d\n",p->num,count);
    }
    else
    {count++;
    leafprint(p->left);
    leafprint(p->right);
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
    
    leafprint(root);

return 0;
}