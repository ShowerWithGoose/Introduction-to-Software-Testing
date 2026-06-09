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
                p->high++; @@ [The height is incremented only once when attaching to parent, but it should reflect the depth from root. The initial height is 1, and each level down should increase height by 1, but this logic incorrectly increments only at insertion point without considering full path depth.]
            q->left=p;
            break;
        }
          else
        {
        p->high++; @@ [Incorrectly incrementing p->high while traversing; p is the new node, not the current tree node. Height should be computed based on traversal depth, not modified on the new node during descent.]
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; @@ [Same error as above: incorrect height calculation by incrementing p->high only at attachment point.]
                q->right=p;
                break;
            }
            else
            {
            p->high++; @@ [Same error: modifying new node's height during traversal instead of tracking depth properly.]
            q=q->right;
            }
        }
    }    
    }
    return m;
    }

void visit(struct Node *p)
{
    if(p==NULL) return; @@ [Missing null check before accessing p->left and p->right; causes segmentation fault when called on NULL child.]
    if(p->left==NULL&&p->right==NULL)
    {
    printf("%d %d\n",p->num,p->high);
    return;
    }
    visit(p->left);
    visit(p->right);
    return;
}
int main()
{
    struct Node *root,*p;
    root=NULL;
    int n;
    int temp;
    scanf("%d",&n);
    while((scanf("%d",&temp))!=EOF) @@ [This loop reads until EOF, but problem states exactly n integers. If input has only n numbers, this may read beyond or behave unexpectedly depending on input buffering. Should loop exactly n times.]
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}