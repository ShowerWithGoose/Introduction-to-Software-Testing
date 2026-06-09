#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int xishu, zhishu;
    struct node *next;
} node;

int main()
{
    node *list1 = NULL;
    node *list2 = NULL;
    node *list_ans = NULL;
    node *p, *q;
    // 录入数据
    int m, n;
    char c;
    while (1)
    {
        q = (node *)malloc(sizeof(node));
        q->next = NULL;
        scanf("%d%d%c", &m, &n, &c);
        q->xishu = m;
        q->zhishu = n;
        if (list1 == NULL)
            list1 = q;
        else
            p->next = q;
        p = q;
        if (c == '\n')
            break;
    }
    while (1)
    {
        q = (node *)malloc(sizeof(node));
        q->next = NULL;
        scanf("%d%d%c", &m, &n, &c);
        q->xishu = m;
        q->zhishu = n;
        if (list2 == NULL)
            list2 = q;
        else
            p->next = q;
        p = q;
        if (c == '\n')
            break;
    }
    // 计算结果
    node *s, *t;
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->next = list_ans;
    for (p = list1; p != NULL; p = p->next)
    {
        for (q = list2; q != NULL; q = q->next)
        {
            s = (node *)malloc(sizeof(node));
            s->next = NULL;
            s->xishu = (p->xishu) * (q->xishu);
            s->zhishu = (p->zhishu) + (q->zhishu);
            if (list_ans == NULL)
                list_ans = s;
            else
            {
                for (t = list_ans; t != NULL; t = t->next)
                {
                    if (t->zhishu == s->zhishu)
                    {
                        t->xishu += s->xishu;
                        free(s); // @@ [After freeing, the loop continues without a break, potentially causing use-after-free or double processing]
                    }
                    else if (t->zhishu > s->zhishu)
                    {
                        if (t->next == NULL)
                            t->next = s; // @@ [Insertion at end, but no break; loop continues and will revisit s, leading to duplicate operations and possible use-after-free]
                        else if (t->next->zhishu < s->zhishu)
                        {
                            s->next = t->next; // @@ [Incomplete insertion logic and lack of break cause loop to reprocess s, resulting in undefined behavior]
                            t->next = s; // @@ [Same issue; after insertion, loop continues and will encounter s again, causing errors]
                        }
                    }
                    else if (t == list_ans && t->zhishu < s->zhishu)
                    {
                        s->next = head->next; // @@ [Insertion at head, but no break; loop continues and will revisit s, leading to incorrect list structure and potential crash]
                        head->next = s; // @@ [Same as above]
                        list_ans = head->next; // @@ [Same as above]
                    }
                }
            }
        }
    }
    for (p = list_ans; p != NULL; p = p->next)
        printf("%d %d ", p->xishu, p->zhishu);
    return 0;
}