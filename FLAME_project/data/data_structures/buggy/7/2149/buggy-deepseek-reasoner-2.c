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
void DFS(PtrN tree,int floor) // @@ [Error: The function does not check for NULL pointer before accessing tree->l and tree->r. When a node has only one child, DFS is called with NULL, causing a segmentation fault.]
{
    if(tree->l==NULL&&tree->r==NULL) // @@ [Error: This line will crash if tree is NULL; but the crash actually occurs earlier when a recursive call passes a NULL pointer.]
    {
        printf("%d %d\n",tree->num,floor);
        return;
    }
    DFS(tree->l,floor+1); // @@ [Error: This recursive call may receive NULL if the left child does not exist, leading to a segmentation fault in the next call.]
    DFS(tree->r,floor+1); // @@ [Error: This recursive call may receive NULL if the right child does not exist, leading to a segmentation fault in the next call.]

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