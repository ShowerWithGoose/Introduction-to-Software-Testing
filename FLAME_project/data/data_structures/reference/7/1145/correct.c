#include<stdio.h>
#include<stdlib.h>
#define M 100
typedef struct NODE
{
    int data;
    int floor;
    struct Node *left;
    struct Node *rght;
}Node;
Node* R;
Node leave;
Node* kong;
Node *newleave(Node* LL,int f,int new){
    f++;
    if (LL == NULL)
    {
        LL = (Node *)malloc(sizeof(Node));
        LL -> data = new;
        LL -> left = NULL;
        LL -> rght = NULL;
        kong = LL;
        LL -> floor = f;
    }
    else if (new < LL->data)
    {
        LL -> left = newleave( LL->left, f , new);
    }
    else if (new >= LL->data)
    {
        LL -> rght = newleave( LL->rght, f , new);
    }
    return LL;
}
void print(Node *Root)
{
    if (Root != NULL)
    {
        if ((Root -> left) == NULL && (Root -> rght) == NULL)
        {
            printf("%d %d\n", Root -> data, Root -> floor);
        }
        print(Root -> left);
        print(Root -> rght);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[M] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i] );
    }
    for (int i = 0; i < n; i++)
    {
       int y=0;
       R=newleave(R,y,arr[i]);
    }
    print(R);
    return 0;
}
