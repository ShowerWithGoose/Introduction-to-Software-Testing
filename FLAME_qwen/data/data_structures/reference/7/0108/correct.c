#include<stdio.h>
#include<stdlib.h>
struct tree{
    int num;
    int floor;
    struct tree *lchild;
    struct tree *rchild;
};
void insert(struct tree *current,struct tree* root)
{
    int floors=1;
    struct tree* tool=root;
    while(tool!=NULL)
    {
        floors++;
        if(current->num<tool->num)
        {
            if(tool->lchild==NULL)
            {
                tool->lchild=current;
                current->floor=floors;
                break;
            }
            else tool=tool->lchild;
        }
        else
        {
            if(tool->rchild==NULL)
            {
                tool->rchild=current;
                current->floor=floors;
                break;
            }
            else tool=tool->rchild;
        }
    }
}
void putout(struct tree* root)
{
    if(root!=NULL){
    putout(root->lchild);
    if(root->lchild==NULL&&root->rchild==NULL)
        printf("%d %d\n",root->num,root->floor);
    putout(root->rchild);
    }
}
int main(void)
{
    int n,i;
    scanf("%d",&n);
    struct tree *root=NULL;
    root=(struct tree*)malloc(sizeof(struct tree));
    root->lchild=NULL;
    root->rchild=NULL;
    root->floor=1;
    for(i=0;i<n;i++)
    {
        int child;
        scanf("%d",&child);
        if(i==0) root->num=child;
        else{
            struct tree *current=NULL;
            current=(struct tree*)malloc(sizeof(struct tree));
            current->num=child;
            current->lchild=NULL;
            current->rchild=NULL;
            insert(current,root);
        }
    }
    putout(root);
}
