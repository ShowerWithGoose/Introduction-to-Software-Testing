#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}Tree;
void insert(Tree *head,int elem);
void search(Tree *p,int floor);
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
void insert(Tree *head,int elem)
{
    Tree* p=(Tree *)malloc(sizeof(Tree));
    p=head;
    while(1)
    {

        if(head->data<=elem)
        {
            if(head->right!=NULL)head=head->right;
            else 
            {
                Tree *temp=(Tree*)malloc(sizeof(Tree));
                temp->right=temp->left=NULL;
                temp->data=elem;
                head->right=temp;
                break;
            } 
        }
        else if(head->data>elem)
        {
            if(head->left!=NULL)head=head->left;
            else 
            {
                Tree *temp=(Tree*)malloc(sizeof(Tree));
                temp->right=temp->left=NULL;
                temp->data=elem;
                head->left=temp;
                
                break;
            }
        }        
    }
    head=p;
}
void search(Tree*p,int floor)
{


    if(p->left!=NULL)
    {
        search(p->left,floor+1);
    }
    if(p->right!=NULL)
    {
        search(p->right,floor+1);
    }    
    if(p->right==NULL&&p->left==NULL)
    {
        printf("%d %d\n",p->data,floor);
        return ;
    }
}
