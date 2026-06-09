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
    p->left=p->right=NULL; // @@ [high field not initialized; may cause undefined behavior]
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
            root->n=num; // @@ [root height not set; should set root->high=1]
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