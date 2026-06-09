#include<stdio.h>
#include<stdlib.h>
struct Node {
    int num;
    int high;
    struct Node *left,*right;
};
struct Node* insertBST(struct Node *m,int number)
{
    struct Node *p,*q;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->num=number;
    p->high=1;
    p->left=p->right=NULL;
    if(m==NULL)
    m=p;
    else
    {
    q=m;
    while(1)
    {
        if(number<q->num)
    {
      if(q->left==NULL)
        {
                p->high++; // @@ The height of the new node is incremented only when moving down, but the height of the root is not correctly set to 1 for the root, and the height calculation is incorrect because it increments p->high for each level traversed, but p->high starts at 1 and should represent the node's depth. However, the logic here increments p->high for each step, which is correct for the new node's depth, but the root's height is set to 1 in the initial assignment. The issue is that when inserting, the height of existing nodes is not updated, but the problem only requires leaf node heights, so this part is actually correct. The real error is that the function returns m, but when m is NULL and a new root is created, the assignment `m=p` only changes the local pointer, not the root in main. This is a classic error: the function parameter is passed by value, so modifying m inside the function does not affect the caller's root variable.
            q->left=p;
            break;
        }
          else
        {
        p->high++;
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++;
                q->right=p;
                break;
            }
            else
            {
            p->high++;
            q=q->right;
            }
        }
    }    
    }
    return m;
    }

void visit(struct Node *p)
{
    if(p->left==NULL&&p->right==NULL)
    {
    printf("%d %d\n",p->num,p->high);
    return;
    }
    visit(p->left); // @@ If p->left is NULL, this will cause a segmentation fault because visit(NULL) is called, and then it tries to access p->left and p->right on a NULL pointer.
    visit(p->right); // @@ Same issue: if p->right is NULL, calling visit(NULL) leads to a crash.
    return;
}
int main()
{
    struct Node *root,*p;
    root=NULL;
    int n;
    int temp;
    scanf("%d",&n);
    while((scanf("%d",&temp))!=EOF)
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}