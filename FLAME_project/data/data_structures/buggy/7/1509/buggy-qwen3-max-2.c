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
                p->high++; // @@ [The height is incremented only once when attaching to parent, but it should reflect the depth from root. The initial height is 1, and each level down should increase by 1, but this logic incorrectly increments only at insertion point without tracking current depth.]
            q->left=p;
            break;
        }
          else
        {
        p->high++; // @@ [Incorrectly incrementing p->high as we traverse; p->high should be set based on the depth of the parent node + 1, not by incrementing during traversal. This leads to wrong height values.]
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; // @@ [Same issue: height is incremented only once at insertion, but not based on actual tree depth.]
                q->right=p;
                break;
            }
            else
            {
            p->high++; // @@ [Same incorrect accumulation of height during traversal. Height should not be modified while descending the tree.]
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
    visit(p->left); // @@ [If p->left is NULL, this will cause a segmentation fault (runtime error). Need to check for NULL before recursive call.]
    visit(p->right); // @@ [Same issue: calling visit on NULL pointer causes runtime error.]
    return;
}
int main()
{
    struct Node *root,*p;
    root=NULL;
    int n;
    int temp;
    scanf("%d",&n);
    while((scanf("%d",&temp))!=EOF) // @@ [This loop reads until EOF, but problem states exactly n integers. If input has only n numbers, this may work, but if extra newlines or EOF handling differs, it could read more or less. However, primary issue is in height calculation and NULL dereference.]
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}