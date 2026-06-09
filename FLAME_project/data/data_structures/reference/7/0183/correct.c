#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


typedef struct node
{
    int data;
    int high;
    struct node *lchild, *rchild;
}Node;

Node *root;

Node *insert(Node *T,int temp,int len)
{
    len++;
    if (T==NULL)
    {
        T=(Node *)malloc(sizeof(Node));
        T->data=temp;
        T->lchild=T->rchild=NULL;
        root=T;
        T->high=len;
    }

    else if (temp<T->data)
    {
        T->lchild=insert(T->lchild,temp,len);
    }
    else if (temp>=T->data)
    {
        T->rchild=insert(T->rchild,temp,len);
    }
    return T;
    
}

void print(Node *T)
{
    if (T)
    {
        if (!(T->lchild) && !(T->rchild))
        {
            printf("%d %d\n",T->data,T->high);
        }
        print(T->lchild);
        print(T->rchild);
    
    }
    
    
}

int main()
{
    Node *T=NULL;
    int n;
    int temp;
    int i=0;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&temp);

        int len=0;
        T=insert(T,temp,len);

    }
    print(T);

    return 0;
    
}
