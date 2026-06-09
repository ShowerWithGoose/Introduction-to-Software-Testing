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
                p->high++; // @@ Error: Incrementing p->high here sets the height incorrectly; height should be based on the node's depth in the tree, not incremented per step. This results in all nodes having height 1 or 2, not the actual depth.
            q->left=p;
            break;
        }
          else
        {
        p->high++; // @@ Error: Same issue as above; incrementing p->high here does not reflect the correct depth of the node.
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; // @@ Error: Same issue; height calculation is incorrect.
                q->right=p;
                break;
            }
            else
            {
            p->high++; // @@ Error: Same issue; height calculation is incorrect.
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
    visit(p->left); // @@ Error: If p->left is NULL, this will cause a segmentation fault because visit() dereferences p without checking for NULL.
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
    while((scanf("%d",&temp))!=EOF) // @@ Error: This loop reads until EOF, but the problem specifies reading exactly n integers. This will cause incorrect behavior if input has extra spaces or newlines, and may read beyond the intended input.
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}