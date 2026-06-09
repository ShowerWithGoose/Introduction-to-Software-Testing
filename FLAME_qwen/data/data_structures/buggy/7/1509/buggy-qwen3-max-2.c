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
                p->high++; // @@ [The height is incremented only once when attaching to parent, but it should reflect the depth from root. The initial height is 1, and each level down should increase by 1, but this logic doesn't correctly accumulate height during traversal.]
            q->left=p;
            break;
        }
          else
        {
        p->high++; // @@ [Same issue: height is being incremented per step in traversal, but since p is a new node, its height should be set based on the current depth of q, not by incrementing as we traverse. This leads to incorrect height values.]
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; // @@ [Same height calculation error as above.]
                q->right=p;
                break;
            }
            else
            {
            p->high++; // @@ [Same height calculation error as above.]
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
    while((scanf("%d",&temp))!=EOF) // @@ [This loop reads until EOF, but the problem specifies exactly n integers. If more than n integers are present (or input ends early), behavior is undefined. It should read exactly n integers, not until EOF.]
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}