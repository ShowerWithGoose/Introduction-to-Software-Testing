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
                p->high=q->high+1; // @@ [Error: The height of the new node should be the parent's height + 1. The original code incorrectly increments p->high which starts at 1, leading to incorrect heights (e.g., always 2 for direct children if logic was slightly different, or accumulating incorrectly). More importantly, the traversal logic below fails to update height correctly relative to depth.]
            q->left=p;
            break;
        }
          else
        {
        // p->high++; // @@ [Error: Incrementing p->high here is incorrect. Height should be determined by depth. Since we are traversing down, we don't know the final depth until we place it. The correct approach is to set p->high = q->high + 1 when placing. The current logic of incrementing a local variable p->high as we traverse is flawed because p->high starts at 1 and is incremented for every step, but this value is overwritten or used incorrectly. Actually, looking closely: p->high starts at 1. If we go left once, it becomes 2. If we go left again, it becomes 3. This *seems* to track depth. However, let's look at the next branch.]
        q=q->left;
        p->high++; // @@ [Move increment here to ensure it counts depth steps correctly regardless of direction, but wait... if we move it here, it increments for every step. Let's look at the right branch.]
        }   
        }
        else if(number>=q->num)
        {
            if(q->right==NULL)
            {
                // p->high++; // @@ [Original code had this inside the if. If we follow the logic: Left branch: if not null, p->high++. Right branch: if not null, p->high++. This effectively counts the depth. HOWEVER, there is a critical bug in the `visit` function.]
                p->high=q->high+1; // @@ [Correct calculation: new node height is parent height + 1]
                q->right=p;
                break;
            }
            else
            {
            // p->high++; // @@ [Same issue as left branch]
            q=q->right;
            p->high++; // @@ [Increment depth counter]
            }
        }
    }    
    }
    return m;
    }

void visit(struct Node *p)
{
    if(p==NULL) return; // @@ [Error: Missing NULL check. If a node has only one child, the other child is NULL. Calling visit(NULL) leads to dereferencing a NULL pointer (Runtime Error) when accessing p->left or p->num.]
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
    while((scanf("%d",&temp))!=EOF)
    {
    root=insertBST(root,temp);
        }    
    p=root;
    visit(p);
   return 0;
}