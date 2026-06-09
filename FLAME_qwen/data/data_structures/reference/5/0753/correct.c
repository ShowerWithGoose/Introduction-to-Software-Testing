#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coe;
    int exp;
    struct poly *next;
} * a, *b, *head_a, *head_b, *c, *head_c;

void insert(struct poly *p, struct poly *in)//插入项
{
    in->next = p->next;
    p->next = in;
}

int main()
{
    a = head_a = (struct poly *)malloc(sizeof(struct poly));
    b = head_b = (struct poly *)malloc(sizeof(struct poly));
    c = head_c = (struct poly *)malloc(sizeof(struct poly));//用来存储乘积

    int d;
    while (scanf("%d%d", &a->coe, &a->exp))//这里要取地址
    {
        a = a->next = (struct poly *)malloc(sizeof(struct poly));
        if ((d = getchar()) == '\n')//这里用来截断，注意条件是 等还是不等
            break;
    }
    while (scanf("%d%d", &b->coe, &b->exp))
    {
        b = b->next = (struct poly *)malloc(sizeof(struct poly));
        if ((d = getchar()) == '\n')
            break;
    }

    struct poly *p, *q;//p、q负责a和b的移动
    head_c->coe = 0;
    head_c -> next = NULL;
    for (p = head_a; p != a; p = p->next)
    {
        for (q = head_b; q != b; q = q->next)
        {   
            struct poly *ptr;//ptr为移动指针
            ptr = (struct poly *)malloc(sizeof(struct poly));
            ptr->coe = p->coe * q->coe;
            ptr->exp = p->exp + q->exp;

            for (c = head_c; c != NULL; c = c->next)
            {
                if (!head_c->coe)
                {
                    head_c->coe = ptr->coe;
                    head_c->exp = ptr->exp;
                    break;
                }
                if (c->exp == ptr->exp)
                {
                    c->coe += ptr->coe;
                    break;
                }
                else if (c -> exp > ptr -> exp && c -> next == NULL)
                {   
                    c = c->next = ptr;
                    c -> next = NULL;
                    break;
                }
                else if (c->exp > ptr->exp && c->next->exp < ptr->exp)
                {
                    insert(c, ptr);
                    break;
                }
            }
            //free(ptr);不能free，不然就没了，但ptr可以重新定义
        }
    }
    
    //释放空间
    for (c = head_c; c != NULL; c = c->next)
        printf("%d %d ", c->coe, c->exp);
    for (c = head_c; c != NULL; c = c->next)
        free(c);//不能一边printf一边free，不然会丢失上一个node的位置
    for (p = head_a; p != NULL; p = p->next)
        free(p);
    for (q = head_b; q != NULL; q = q->next)
        free(q);
}


