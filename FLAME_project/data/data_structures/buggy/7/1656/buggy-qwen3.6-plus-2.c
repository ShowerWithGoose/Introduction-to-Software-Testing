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
    int i=1; // @@ The height counter `i` is initialized to 1, but it is incremented (`i++`) at the beginning of the loop before checking if the node is placed. For the first node (root), the loop runs, `i` becomes 2, and then the root's value is updated, but its height is never set (remains uninitialized or 0 from malloc). Even for subsequent nodes, the height calculation is off by one or incorrect because the root's height isn't properly established as 1.
    while(1)
    {
        i++;
        if(root->n==-1)
        {
            root->n=num;
            break; // @@ When inserting the first node into the dummy root, the code updates the value `root->n = num` but fails to set `root->high = 1`. This leaves the root's height uninitialized (likely 0), causing the wrong output for the root if it is a leaf.
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