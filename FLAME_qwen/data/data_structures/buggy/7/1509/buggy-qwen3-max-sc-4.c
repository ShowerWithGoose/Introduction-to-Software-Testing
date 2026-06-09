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
                p->high++; @@ [The height of the new node is being incremented after assignment, but it should reflect the depth in the tree. The initial height is set to 1, and each time we go down a level, the new node's height should be parent's height + 1, not incrementing its own repeatedly during traversal.]
            q->left=p;
            break;
        }
          else
        {
        p->high++; @@ [Same issue: p->high is being incremented as we traverse down, but p is the new node that hasn't been placed yet. Its height should be determined once when inserted, based on the parent's height + 1. This logic incorrectly accumulates increments during traversal.]
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; @@ [Same error: incorrect height calculation by incrementing after reaching insertion point. Should be q->high + 1, not p->high++.]
                q->right=p;
                break;
            }
            else
            {
            p->high++; @@ [Same error: p->high is modified during traversal, leading to wrong final height.]
            q=q->right;
            }
        }
    }    
    }
    return m;
    }

void visit(struct Node *p)
{
    if(p==NULL) return; @@ [Missing null check before accessing p->left and p->right. If p is NULL (e.g., empty tree or recursive call on non-existent child), this causes segmentation fault. The original code assumes p is never NULL here, but recursive calls may pass NULL.]
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
    while((scanf("%d",&temp))!=EOF) @@ [This loop reads until EOF, but problem states exactly n integers. If input has only n numbers, this may work, but if extra data exists, it reads too many. More critically, if input ends after n numbers, some systems may not trigger EOF immediately, causing undefined behavior. Should loop exactly n times.]
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}