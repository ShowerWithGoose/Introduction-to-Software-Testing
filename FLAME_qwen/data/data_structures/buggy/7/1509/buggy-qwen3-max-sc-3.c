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
                p->high++; @@ [The height is incremented only once when attaching, but it should reflect the depth from root. The initial p->high=1 is wrong; height should be parent's height + 1.]
            q->left=p;
            break;
        }
          else
        {
        p->high++; @@ [Incrementing p->high while traversing is incorrect; p is the new node and its height should be set based on the parent's height at insertion point, not during traversal.]
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; @@ [Same issue: height should be parent's height + 1, not incrementing from 1 during traversal.]
                q->right=p;
                break;
            }
            else
            {
            p->high++; @@ [Incorrectly modifying the new node's height during traversal; this leads to wrong height values.]
            q=q->right;
            }
        }
    }    
    }
    return m;
    }

void visit(struct Node *p)
{
    if(p==NULL) return; @@ [Missing null check before accessing p->left and p->right; causes segmentation fault when p is NULL.]
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
    while((scanf("%d",&temp))!=EOF) @@ [This loop reads until EOF, but problem states exactly n integers; may read extra inputs or hang if input doesn't end with EOF. Should loop n times.]
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}