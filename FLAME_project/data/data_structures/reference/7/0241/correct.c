#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct node
{
    int data;
    int ling ;
    struct node* lchild;
    struct node* rchild;
};
struct node* q, * p, * head;
int n;
int temp;
void jianlishu();
void bianli(struct node* t);
int main()
{
    jianlishu();
    bianli(head);
}
void jianlishu()
{
    scanf("%d", &temp);
    head = NULL;
    int yi = 0;
    while (yi<temp)
    {
        scanf("%d", &n);
        p = (struct node*)malloc(sizeof(struct node));
        p->data = n;
        p->ling = 1;
        p->lchild = NULL;
        p->rchild = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q = head;
            while (1)
            {
                if (p->data >= q->data)
                {
                    if (q->rchild == NULL)
                    {
                        q->rchild = p;
                        p->ling++;
                        break;
                        
                    }
                    else
                    {
                        q = q->rchild;
                        p->ling++;
                    }
                }
                if (p->data < q->data)
                {
                    if (q->lchild == NULL)
                    {
                        q->lchild = p;
                        p->ling++;
                        break;
                    }
                    else
                    {
                        q = q->lchild;
                        p->ling++;
                    }
                }
            }
        }

        yi++;
    }
}
void bianli(struct node* t)
{
    if (t != NULL)
    {
        if (t->lchild == NULL && t->rchild == NULL)
        {
            printf("%d %d\n", t->data, t->ling);
        }
        bianli(t->lchild);
        bianli(t->rchild);
    }
}


