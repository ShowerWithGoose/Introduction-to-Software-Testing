#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int exponent; // 指数
    int coefficient; // 系数
    struct node * next;
} Node;

void insert(Node * head, int exp, int coe);

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    Node * head1 = malloc(sizeof(Node));
    Node * head2 = malloc(sizeof(Node));
    int getC, getE;

    Node * p = head1;
    while (scanf("%d %d", &getC, &getE) != EOF)
    {
        p->next = malloc(sizeof(Node));
        p = p->next;
        p->next = NULL;
        p->coefficient = getC;
        p->exponent = getE;
        if (getchar() == '\n')
        {
            break;
        }
    }
    p = head2;
    while (scanf("%d %d", &getC, &getE) != EOF)
    {
        p->next = malloc(sizeof(Node));
        p = p->next;
        p->next = NULL;
        p->coefficient = getC;
        p->exponent = getE;
    }
    
    Node * head3 = malloc(sizeof(Node));
    head3->next = NULL;
    Node * p1 = head1->next;
    while (p1 != NULL)
    {
        Node * p2 = head2->next;
        while (p2 != NULL)
        {
            // printf("%d^%d*%d^%d\n", p1->coefficient, p1->exponent, p2->coefficient, p2->exponent);
            int tmpExp = p1->exponent+p2->exponent;
            int tmpCoe = p1->coefficient*p2->coefficient;
            insert(head3, tmpExp, tmpCoe);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    p = head3->next;
    while (p != NULL)
    {
        printf("%d %d ", p->coefficient, p->exponent);
        p = p->next;
    }

    return 0; 
}

void insert(Node * head, int exp, int coe)
{
    Node * pre = head;
    Node * p = head->next;
    while (p != NULL && p->exponent > exp)
    {
        pre = p;
        p = p->next;
    }
    if (p != NULL)
    {
        if (p->exponent == exp)
        {
            p->coefficient += coe;
        }
        else
        {
            pre->next = malloc(sizeof(Node));
            pre->next->next = p;
            p = pre->next;
            p->coefficient = coe;
            p->exponent = exp;
        }
    }
    else
    {
        pre->next = malloc(sizeof(Node));
        p = pre->next;
        p->coefficient = coe;
        p->exponent = exp;
        p->next = NULL;
    }
}
