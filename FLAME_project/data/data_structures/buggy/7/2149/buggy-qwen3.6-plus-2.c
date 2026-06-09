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
void DFS(PtrN tree,int floor) // @@ The function does not check if 'tree' is NULL before accessing its members, causing a Runtime Error (segmentation fault) when it tries to traverse the left or right child of a leaf node (which are NULL).
{
    if(tree->l==NULL&&tree->r==NULL)
    {
        printf("%d %d\n",tree->num,floor);
        return;
    }
    DFS(tree->l,floor+1);
    DFS(tree->r,floor+1);

}
int main()
{
    PtrN tree=NULL;
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
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