#include <stdio.h>
#include <stdlib.h>
typedef struct term
{
    int coefficient;
    int exponent;
    struct term *next;
} term;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubblesort(term *r)
{
    term *a=r,*b=r;
    while(a!=NULL)
    {
        b=r;
        while(b->next!=NULL)
        {
            if(b->exponent<b->next->exponent)
            {
                swap(&b->exponent,&b->next->exponent),swap(&b->coefficient,&b->next->coefficient);
            }
            b=b->next;
        }
        a=a->next;
    }
}

int main()
{
    term *p, *p_head, *q, *q_head;
    char ch = 'a';
    p_head = (term *)malloc(sizeof(term));
    scanf("%d%d%c", &p_head->coefficient, &p_head->exponent, &ch);
    p_head->next = NULL;
    p = p_head;
    while (ch != '\n')
    {
        p->next = (term *)malloc(sizeof(term));
        p = p->next;
        scanf("%d%d%c", &p->coefficient, &p->exponent, &ch);
        p->next = NULL;
    }
    ch = 'a';
    q_head = (term *)malloc(sizeof(term));
    scanf("%d%d%c", &q_head->coefficient, &q_head->exponent, &ch);
    q_head->next = NULL;
    q = q_head;
    while (ch != '\n')
    {
        q->next = (term *)malloc(sizeof(term));
        q = q->next;
        scanf("%d%d%c", &q->coefficient, &q->exponent, &ch);
        q->next = NULL;
    }

    // 乘法开始
    term *r, *r_head;
    r_head = (term *)malloc(sizeof(term));
    r_head->coefficient = p_head->coefficient * q_head->coefficient;
    r_head->exponent = p_head->exponent + q_head->exponent;
    r_head->next = NULL;
    r = r_head;
    p = p_head, q = q_head->next;
    // 全乘开，合并同类项，不排序
    term *s;
    int flag = 0;
    while (p != NULL)
    {
        q=q_head->next;
        while (q != NULL)
        {
            flag = 0;
            s = r_head;
            while (s != NULL)
            {
                if (s->exponent == p->exponent + q->exponent)
                {
                    flag = 1;
                    s->coefficient += p->coefficient * q->coefficient;
                    break;
                }
                s = s->next;
            }
            if (flag == 0)
            {
                r->next = (term *)malloc(sizeof(term));
                r = r->next;
                r->coefficient = p->coefficient * q->coefficient;
                r->exponent = p->exponent + q->exponent;
                r->next = NULL;
            }
            q=q->next;
        }
        p=p->next;
    }
    
    // 排序
    bubblesort(r_head);
    //输出
    r=r_head;
    while(r!=NULL)
    {
        printf("%d %d ",r->coefficient,r->exponent);
        r=r->next;
    }
    //清除内存
    while(r_head!=NULL)
    {
        term *tmp=r_head;
        r_head=r_head->next;
        free(tmp);
    }
    while(p_head!=NULL)
    {
        term *tmp=p_head;
        p_head=p_head->next;
        free(tmp);
    }
    while(q_head!=NULL)
    {
        term *tmp=q_head;
        q_head=q_head->next;
        free(tmp);
    }
    return 0;
}