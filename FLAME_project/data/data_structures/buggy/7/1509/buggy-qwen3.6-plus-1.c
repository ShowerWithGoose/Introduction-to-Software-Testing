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
                p->high++; // @@ The height calculation is incorrect. It only increments by 1 relative to the initial value of 1, regardless of depth. It should be q->high + 1.
            q->left=p;
            break;
        }
          else
        {
        p->high++; // @@ The height calculation is incorrect here as well. It increments cumulatively in a wrong way. It should not modify p->high here, but rather set it when the node is placed.
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++; // @@ The height calculation is incorrect. It should be q->high + 1.
                q->right=p;
                break;
            }
            else
            {
            p->high++; // @@ The height calculation is incorrect here as well.
            q=q->right;
            }
        }
    }    
    }
    return m;
    }

void visit(struct Node *p)
{
    if(p==NULL) return; // @@ Missing null check causes Runtime Error (Segmentation Fault) when visiting children of leaf nodes or empty trees.
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
    while((scanf("%d",&temp))!=EOF) // @@ Logic error: reads until EOF instead of reading exactly n integers. However, given the input format, this might work if input ends, but strictly it should loop n times. More critically, if the input stream doesn't close immediately after n numbers, it hangs. But the primary crash is in visit. Let's look closer. The problem says "read n integers". The loop condition `!=EOF` will keep waiting for more input if stdin is interactive, or fail if strict. But usually in OJ, EOF comes after all input. The bigger issue is the logic inside insertBST height.
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}