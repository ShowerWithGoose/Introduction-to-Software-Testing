#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    struct node* left;
    int num;
    int level;
    struct node* right;
}tree;
int main()
{
    tree* point=NULL;
    tree* root=NULL;
    tree* temp=NULL;
    int n=0,aim=0,level_count=1;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&aim);
        getchar();
        temp=(tree*)malloc(sizeof(tree));
        temp->num=aim;
        temp->left=NULL;temp->right=NULL;
        if(root==NULL) 
        {
            root=temp;
            root->level=1;
        }
        else
        {
            point=root;
            while(1){
                if(aim<point->num)
                {
                    if(point->left==NULL)
                    {
                        point->left=temp;
                        point->left->level=point->level+1;
                        break;
                    }
                    else
                    {
                        point->left->level=point->level+1; // @@ updates level of an existing node incorrectly; each node's level should be set only at creation
                        point=point->left;
                    }
                }
                else if(aim>point->num)
                {
                    if(point->right==NULL)
                    {
                        point->right=temp;
                        point->right->level=point->level+1;
                        break;
                    }
                    else
                    {
                        point->right->level=point->level+1; // @@ same issue: incorrectly updates level of an existing node
                        point=point->right;
                    }
                }
                else{
                    break; // @@ should insert on right for equal values; here it just breaks, causing the node to be lost (memory leak) and violating BST definition
                }
            }
        }    
    }
    tree* stack[100];
    tree* p=root; // @@ if root is NULL (n==0), p is NULL and subsequent operations will cause undefined behavior (e.g., stack underflow)
    int top=-1;
    do{
        while(p!=NULL)
        {
            top++;
            stack[top]=p;
            p=p->left;
        }
        p=stack[top];
        top--;
        if(p->left==NULL&&p->right==NULL)
        {
            printf("%d %d\n",p->num,p->level);
        }
        p=p->right;
    }while(!(p==NULL&&top==-1));
    return 0;
}