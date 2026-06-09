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
            p->next = q; // @@ [In the first iteration of the first input loop, 'p' is uninitialized when list1 is not NULL. This leads to undefined behavior when assigning p->next = q.]
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
            p->next = q; // @@ [After the first loop, 'p' points to the last node of list1. In the second loop, when list2 is not NULL, we incorrectly use 'p' (which belongs to list1) to link nodes of list2, corrupting list1 and causing undefined behavior.]
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
                        free(s); // @@ [After freeing 's', the code continues to potentially use 's' in subsequent iterations or conditions within the same inner loop, leading to use-after-free if the loop doesn't break. Also, the loop doesn't break after merging, so it may process the same term multiple times.]
                        break; // @@ [Missing break after merging coefficients; without it, the freed pointer 's' might be used again or the term could be inserted multiple times.]
                    }
                    else if (t->zhishu > s->zhishu)
                    {
                        if (t->next == NULL)
                            t->next = s;
                        else if (t->next->zhishu < s->zhishu)
                        {
                            s->next = t->next;
                            t->next = s;
                        }
                        break; // @@ [Missing break after inserting 's'; without it, the loop continues and may insert or modify the same node again.]
                    }
                    else if (t == list_ans && t->zhishu < s->zhishu)
                    {
                        s->next = head->next;
                        head->next = s;
                        list_ans = head->next;
                        break; // @@ [Missing break after inserting at head; without it, the loop continues unnecessarily and may cause duplicate insertion or corruption.]
                    }
                }
            }
        }
    }
    for (p = list_ans; p != NULL; p = p->next)
        printf("%d %d ", p->xishu, p->zhishu);
    return 0;
}