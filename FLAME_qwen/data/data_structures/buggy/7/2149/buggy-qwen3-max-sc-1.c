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
    DFS(tree->l,floor+1); // @@ [If tree->l is NULL, calling DFS on it will cause a segmentation fault. The function does not check for NULL before recursing.]
    DFS(tree->r,floor+1); // @@ [If tree->r is NULL, calling DFS on it will cause a segmentation fault. The function does not check for NULL before recursing.]

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
    DFS(tree,1); // @@ [If the input N is 0, tree remains NULL, and passing NULL to DFS will cause a segmentation fault because DFS immediately accesses tree->l and tree->r without checking if tree is NULL.]
    return 0;

}