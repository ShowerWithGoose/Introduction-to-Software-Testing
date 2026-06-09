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
                p->high++; // @@ Error: This increments p->high but does not update the height of the node being inserted relative to the root; the height should be calculated based on the depth from the root, not incremented per step. Also, the height of the root should be 1, but this logic sets p->high to 1 initially and then increments, which may result in incorrect heights for leaf nodes.
            q->left=p;
            break;
        }
          else
        {
        p->high++; // @@ Error: Same issue as above; incrementing p->high here does not correctly track the depth because p is a new node and its height should be set after finding its position, not incremented during traversal.
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; // @@ Error: Same issue; incorrect height calculation.
                q->right=p;
                break;
            }
            else
            {
            p->high++; // @@ Error: Same issue; incorrect height calculation.
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
    visit(p->left); // @@ Error: If p->left is NULL, this will cause a segmentation fault because the function does not check for NULL before recursing. The original logic assumes both children exist when it reaches this point, but if only one child is NULL, the recursion will crash.
    visit(p->right); // @@ Error: Same issue as above; if p->right is NULL, this will cause a segmentation fault.
    return;
}
int main()
{
    struct Node *root,*p;
    root=NULL;
    int n;
    int temp;
    scanf("%d",&n);
    while((scanf("%d",&temp))!=EOF) // @@ Error: This loop reads until EOF, but the problem specifies reading exactly n integers. This will cause the program to wait for more input or read incorrectly if the input ends after n numbers. It should use a for loop with n iterations instead.
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}