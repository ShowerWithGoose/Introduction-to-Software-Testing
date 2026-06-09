#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct p{
    int data;
    struct p *right;
    struct p *left;
}Tree;
void insert(Tree *head,int a);
void search(Tree *p,int depth);
int main()
{
    Tree *root=(Tree*)malloc(sizeof(Tree));
    root->left=root->right=NULL;
    int n;
    scanf("%d",&n);
    int a;//数据
    scanf("%d",&a);
    root->data=a;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a);
        insert(root,a);
    }
    search(root,1);
    
    return 0;
}
void insert(Tree *head,int a)
{
    Tree* p=(Tree *)malloc(sizeof(Tree));
    p=head;
    while(1)
    {

        if(head->data<=a)
        {
            if(head->right!=NULL)head=head->right;
            else 
            {
                Tree *temp=(Tree*)malloc(sizeof(Tree));
                temp->right=temp->left=NULL;
                temp->data=a;
                head->right=temp;
                break;
            } 
        }
        else if(head->data>a)
        {
            if(head->left!=NULL)head=head->left;
            else 
            {
                Tree *temp=(Tree*)malloc(sizeof(Tree));
                temp->right=temp->left=NULL;
                temp->data=a;
                head->left=temp;
                
                break;
            }
        }        
    }
    head=p;
}
void search(Tree*p,int depth)
{


    if(p->left!=NULL)
    {
        search(p->left,depth+1);
    }
    if(p->right!=NULL)
    {
        search(p->right,depth+1);
    }    
    if(p->right==NULL&&p->left==NULL)
    {
        printf("%d %d\n",p->data,depth);
        return ;
    }
}
