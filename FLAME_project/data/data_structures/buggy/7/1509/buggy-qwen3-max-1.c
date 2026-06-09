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
                p->high++; @@ // Error: Incrementing p->high after setting it to 1, but height should be parent's height + 1, not just incremented arbitrarily in loop
            q->left=p;
            break;
        }
          else
        {
        p->high++; @@ // Error: Same issue - height is being incremented per traversal step, but this approach doesn't correctly track the actual depth
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; @@ // Error: Same incorrect height calculation
                q->right=p;
                break;
            }
            else
            {
            p->high++; @@ // Error: Same incorrect height calculation
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
    visit(p->left); @@ // Error: No null check before recursive call; will cause segmentation fault when p->left is NULL
    visit(p->right); @@ // Error: No null check before recursive call; will cause segmentation fault when p->right is NULL
    return;
}
int main()
{
    struct Node *root,*p;
    root=NULL;
    int n;
    int temp;
    scanf("%d",&n);
    while((scanf("%d",&temp))!=EOF) @@ // Error: Loop condition reads until EOF, but problem specifies exactly n integers; may read extra inputs or hang
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}