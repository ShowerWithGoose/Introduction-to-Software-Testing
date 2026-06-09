#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int max;
typedef struct bstree{
    int n;
    int high;
    struct bstree *left,*right;
}node;
node* creat(int num)
{
    node*p;
    p=(node*)malloc(sizeof(node));
    p->left=p->right=NULL;
    p->n=num;
    
    return p;
}
node* root;
void insert(int num)
{
    node *z=root,*q;
    q=creat(num);
    int i=1; // @@ The height counter 'i' is initialized to 1, but it is incremented at the beginning of the loop before checking the root. For the first node (root), the loop runs, 'i' becomes 2, and if the root was empty (n==-1), it sets the value but doesn't set the height. More importantly, for subsequent nodes, the height calculation is off because 'i' starts at 1 and increments immediately, meaning the root's children get height 2 (correct if root is 1), but the logic for setting the root's height is missing entirely in the `if(root->n==-1)` block.
    while(1)
    {
        i++; // @@ Incrementing 'i' here means the first check (for root replacement) happens with i=2. If this is the first actual data node being inserted into the dummy root, its height should be 1, but the code doesn't assign height here. For deeper nodes, the height will be calculated as depth + 1 relative to the start, but since the root dummy node isn't counted correctly or handled, the heights are wrong. Specifically, for the test case with 1 element, the dummy root is replaced by the value, but `q->high` is never set for the root case, leaving it uninitialized (or 0).
        if(root->n==-1) // @@ This condition handles the first insertion by replacing the dummy node's value. However, it does not set `root->high`. The node `q` created for this number is leaked (memory leak), and the root node retains its uninitialized `high` value (likely 0). It should set `root->high = 1` and free `q`, or handle the first insertion differently.
        {
            root->n=num;
            break;
        }
        else if(z->n>num)
        {
            if(z->left==NULL)
            {
                z->left=q;
                q->high=i;
                break;
            }
            else
            z=z->left;
        }
        else if(z->n<=num)
        {
            if(z->right==NULL)
            {
                z->right=q;
                q->high=i;
                break;
            }
            else
            z=z->right;
        }
        
    }
    
}
void travel(node*p)
{
    if(p==NULL) return;
    
    if(p->left==NULL&&p->right==NULL) 
    printf("%d %d\n",p->n,p->high);
    
    travel(p->left);
    travel(p->right);
    
}
int main()
{
    int m,num;
    scanf("%d",&m);
    
    root=creat(-1);
    while(m--)
    {
        scanf("%d",&num);
        insert(num);
    }
    
    travel(root);
    
    
    return 0;
 }