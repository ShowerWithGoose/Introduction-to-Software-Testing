#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int n;

typedef struct Node
{
    int data;
    struct Node *lnext;
    struct Node *rnext;
}Node;
typedef struct Node *LinkList;

int deep = 1;

void through(LinkList T)
{
    if (T!=NULL)
    {
        if (T->lnext==NULL && T->rnext==NULL)
            printf("%d %d\n", T->data, deep);
        deep++;
        through(T->lnext);
        through(T->rnext);
        deep--;
    }
}

int main(int argc, char *argv[], char *envp[])
{
    scanf("%d", &n);
    int num;
    scanf("%d", &num);
    LinkList T = (LinkList)malloc(sizeof(Node));
    T->data = num;
    T->lnext = NULL;
    T->rnext = NULL;
    n--;
    
    while (n--)
    {
        LinkList now = T;
        scanf("%d", &num);
        while (1)
        {
            if (num<now->data)
            {
                if (now->lnext == NULL)
                {
                    LinkList temp = (LinkList)malloc(sizeof(Node));
                    temp->data = num;
                    temp->lnext = NULL;
                    temp->rnext = NULL;
                    now->lnext = temp;
                    break;
                }
                else
                    now = now->lnext;
            }
            else
            {
                if (now->rnext == NULL)
                {
                    LinkList temp = (LinkList)malloc(sizeof(Node));
                    temp->data = num;
                    temp->lnext = NULL;
                    temp->rnext = NULL;
                    now->rnext = temp;
                    break;
                }
                else
                    now = now->rnext;
            }
        }
        
        
        
    }
    through(T);
    return 0;
}





