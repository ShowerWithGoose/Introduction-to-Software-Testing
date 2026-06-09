#include<stdio.h>
#include<stdlib.h>
typedef struct Node * PtrN;
struct Node
{
    int num;
    PtrN l;
    PtrN r;

};
PtrN Insret(PtrN tree,PtrN temp)
{
    PtrN node=tree;
    if(tree==NULL)
    {
        tree=temp;
        return tree;
    }
    else
    {
        while(node!=NULL)
        {
            if(temp->num<node->num)
            {
                if(node->l!=NULL)
                {
                    node=node->l;
                }
                else
                {
                    node->l=temp;
                    break;
                }
            }
            else
            {
                if(node->r!=NULL)
                {
                    node=node->r;
                }
                else
                {
                    node->r=temp;
                    break;
                }

            }
        }
        return tree;
    }
}
void DFS(PtrN tree,int floor)
{
    if(tree->l==NULL&&tree->r==NULL) // @@ Dereferencing 'tree' without checking if it is NULL will cause a segmentation fault when the function is called with a NULL pointer
    {
        printf("%d %d\n",tree->num,floor);
        return;
    }
    DFS(tree->l,floor+1); // @@ Missing NULL check for 'tree->l' before recursive call, causes segmentation fault when left child is NULL
    DFS(tree->r,floor+1); // @@ Missing NULL check for 'tree->r' before recursive call, causes segmentation fault when right child is NULL

}
int main()
{
    PtrN tree=NULL;
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) // @@ Declaring loop variable inside 'for' statement is not allowed in C89/C90 standard, which may cause a compilation error
    {
        int x;
        scanf("%d",&x);
        PtrN temp=(PtrN)malloc(sizeof(struct Node));
        temp->num=x;
        temp->l=NULL;
        temp->r=NULL;
        tree=Insret(tree,temp);

    }
    DFS(tree,1);
    return 0;

}