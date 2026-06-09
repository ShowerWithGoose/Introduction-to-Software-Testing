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
    if(tree->l==NULL&&tree->r==NULL)
    {
        printf("%d %d\n",tree->num,floor);
        return;
    }
    DFS(tree->l,floor+1); // @@ [Calling DFS on NULL pointer when tree->l is NULL, leading to segmentation fault or undefined behavior]
    DFS(tree->r,floor+1); // @@ [Calling DFS on NULL pointer when tree->r is NULL, leading to segmentation fault or undefined behavior]

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