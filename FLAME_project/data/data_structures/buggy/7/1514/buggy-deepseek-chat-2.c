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
                        point->left->level=point->level+1; // @@ This line incorrectly updates the level of an existing node instead of just moving to it. The level should only be set when inserting a new node, not when traversing.
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
                        point->right->level=point->level+1; // @@ Same issue as above: incorrectly updates the level of an existing node during traversal.
                        point=point->right;
                    }
                }
                else{
                    break; // @@ This handles duplicate values by simply breaking, but the problem requires that duplicates go to the right (>=). This causes the duplicate 100 to be ignored, so it never appears as a leaf.
                }
            }
        }    
    }
    tree* stack[100];
    tree* p=root;
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