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
                p->high++; // @@ Error: This increments p->high for each level, but p->high starts at 1 and should represent the node's height. However, the logic is flawed because p->high is incremented before the node is inserted, and the increment happens for each comparison, not based on the actual depth. The correct approach is to track the depth during traversal and assign it to the new node.
            q->left=p;
            break;
        }
          else
        {
        p->high++; // @@ Error: Same issue as above; p->high is incremented incorrectly during traversal.
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; // @@ Error: Same issue as above.
                q->right=p;
                break;
            }
            else
            {
            p->high++; // @@ Error: Same issue as above.
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
    visit(p->left); // @@ Error: This will cause a segmentation fault if p->left is NULL, because the function does not check for NULL before recursing. The original code checks for NULL before calling print_tree on children.
    visit(p->right); // @@ Error: Same issue as above; no NULL check before recursion.
    return;
}
int main()
{
    struct Node *root,*p;
    root=NULL;
    int n;
    int temp;
    scanf("%d",&n);
    while((scanf("%d",&temp))!=EOF) // @@ Error: This loop reads until EOF, but the problem specifies reading exactly n integers. This will cause the program to wait for more input or read incorrectly if the input ends.
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}