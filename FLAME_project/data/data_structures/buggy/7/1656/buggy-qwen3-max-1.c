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
    int i=1;
    while(1)
    {
        i++;
        if(root->n==-1)
        {
            root->n=num;
            break;
        }
        else if(z->n>num)
        {
            if(z->left==NULL)
            {
                z->left=q;
                q->high=i; // @@ [The height of the inserted node is set to 'i', which starts at 1 and is incremented before checking insertion. For the first node (root), this logic is bypassed, but for subsequent nodes, 'i' becomes 2 before assignment, leading to incorrect heights. However, in the test case with only one node, the root's 'high' field is never set—it remains uninitialized (0), because the root is created with n=-1 and then overwritten without setting 'high'.]
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
                q->high=i; // @@ [Same issue as above: 'high' is only set for child nodes, not for the root when it's the only node. The root's 'high' remains uninitialized (0) because 'creat(-1)' sets n=-1 but doesn't initialize 'high', and when the first real value is assigned to root->n, root->high is never set to 1.]
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
    
    root=creat(-1); // @@ [The root node is initialized with n=-1 and high uninitialized (garbage/0). When the first (and only) number is inserted, the code overwrites root->n but never sets root->high to 1, so it remains 0, causing the output "5678 0" instead of "5678 1".]
    while(m--)
    {
        scanf("%d",&num);
        insert(num);
    }
    
    travel(root);
    
    
    return 0;
 }