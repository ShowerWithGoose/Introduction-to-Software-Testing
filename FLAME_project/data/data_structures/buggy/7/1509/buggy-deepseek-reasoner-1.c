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
                p->high++;
            q->left=p;
            break;
        }
          else
        {
        p->high++;
        q=q->left;
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                p->high++;
                q->right=p;
                break;
            }
            else
            {
            p->high++;
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
    visit(p->left); // @@ This recursive call does not check if p->left is NULL. If p has only a right child, p->left is NULL, and visiting it will dereference a null pointer in the next call, causing a segmentation fault.
    visit(p->right); // @@ Similarly, this recursive call does not check if p->right is NULL. If p has only a left child, p->right is NULL, leading to a segmentation fault when attempting to access p->left inside the next visit call.
    return;
}
int main()
{
    struct Node *root,*p;
    root=NULL;
    int n;
    int temp;
    scanf("%d",&n);
    while((scanf("%d",&temp))!=EOF)
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}