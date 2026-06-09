#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Trees
{
    int value;
    struct Trees *leftson;
    struct Trees *rightson;
} tree;

void outprint(tree*,int);

int main()
{
    int n;
    scanf("%d",&n);
    tree* root=(tree*)malloc(sizeof(tree));//释放
    memset(root,0,sizeof(tree));
    scanf("%d",&root->value);
    n--;    
    while (n--)
    {
        tree* grow=root;
        int leaf;
        scanf("%d",&leaf);
        while (1)
        {
            if(leaf<grow->value)
            {
                if(grow->leftson==NULL)
                {
                    grow->leftson=(tree*)malloc(sizeof(tree));
                    memset(grow->leftson,0,sizeof(tree));
                    grow->leftson->value=leaf;
                    break;
                }
                grow=grow->leftson;
            }
            else if(leaf>=grow->value)
            {
                if(grow->rightson==NULL)
                {
                    grow->rightson=(tree*)malloc(sizeof(tree));
                    memset(grow->rightson,0,sizeof(tree));
                    grow->rightson->value=leaf;
                    break;
                }
                grow=grow->rightson;
            }
        }        
    }
    outprint(root,1);
    system("pause");
    return 0;
}


void outprint(tree* root,int depth)
{
    if(root->leftson==NULL&&root->rightson==NULL)
    {
        printf("%d %d\n",root->value,depth);
    }
    if(root->leftson!=NULL)outprint(root->leftson,depth+1);
    if(root->rightson!=NULL)outprint(root->rightson,depth+1);
    free(root);
    return ;
}


