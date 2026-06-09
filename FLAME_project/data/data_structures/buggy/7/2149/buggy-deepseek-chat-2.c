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
    if(tree->l==NULL&&tree->r==NULL) // @@ [Error: If tree is NULL, dereferencing it causes a segmentation fault. The function does not check for NULL before accessing tree->l and tree->r.]
    {
        printf("%d %d\n",tree->num,floor);
        return;
    }
    DFS(tree->l,floor+1); // @@ [Error: If tree->l is NULL, the recursive call will pass NULL to DFS, leading to the same NULL dereference issue.]
    DFS(tree->r,floor+1); // @@ [Error: Same issue as above for tree->r.]

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