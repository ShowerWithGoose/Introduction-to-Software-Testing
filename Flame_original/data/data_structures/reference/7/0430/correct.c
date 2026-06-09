#include<stdio.h>
#include<strings.h>

int floor;
int *m = &floor;

typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    int value;
}tree;

tree *head;

tree *insert(tree *p,int i)
{
    tree *q;
    if(p == NULL)
    {
        p = (tree*)malloc(sizeof(tree));
        p->value = i;
        p->lchild = NULL;
        p->rchild = NULL;
        return p;
    }
    else 
    {
        if(i >= p->value)
        {
            if(p->rchild == NULL)
            {
                q = (tree*)malloc(sizeof(tree));
                p->rchild = q;
                q->value = i;
                q->lchild = NULL;
                q->rchild = NULL;
            }
            else insert(p->rchild,i);
        }
        else
        {
            if(p->lchild == NULL)
            {
                q = (tree*)malloc(sizeof(tree));
                p->lchild = q;
                q->value = i;
                q->lchild = NULL;
                q->rchild = NULL;
            }
            else insert(p->lchild,i);
        }
    }
    return head;
}

void find(tree *p,int high)
{
    if(p == NULL) return;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        printf("%d %d\n",p->value,high);
    }
    else 
    {
        find(p->lchild,high + 1);
        find(p->rchild,high + 1);
    }
}

int main()
{
    int n;
    int num[1000] = {0};
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) scanf("%d",&num[i]);
    for(int i = 0 ; i < n ; i ++) head = insert(head,num[i]);
    find(head,1);
    system("pause");
    return 0;
}
