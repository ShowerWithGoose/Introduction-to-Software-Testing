#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct links
{
    int p1[2];
    int p2[2];
    int num;
    struct links *next;
} Link;
int main()
{
    freopen("out.txt", "r", stdin); // @@ [Error: This line opens a file for input, but the problem expects input from stdin. This will cause the program to read from a file that may not exist, leading to undefined behavior or compilation issues if the file is not present.]
    int N;
    scanf("%d", &N);
    Link *st = NULL;
    Link *ed = NULL;
    Link *p = NULL;
    Link *q = NULL;
    int flag;
    for (int i = 0; i < N; i++)
    {
        flag = 0;
        int a1, a2, b1, b2;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        if (st != NULL)
        {
            q = st;
            p = q;
            while (1)
            {
                if (a1 == p->p1[0] && a2 == p->p1[1])
                {
                    p->p1[0] = b1;
                    p->p1[1] = b2;
                    p->num++;
                    flag = 1;
                    break;
                }
                else if (a1 == p->p2[0] && a2 == p->p2[1])
                {
                    p->p2[0] = b1;
                    p->p2[1] = b2;
                    p->num++;
                    flag = 1;
                    break;
                }
                else if (b1 == p->p1[0] && b2 == p->p1[1])
                {
                    p->p1[0] = a1;
                    p->p1[1] = a2;
                    p->num++;
                    flag = 1;
                    break;
                }
                else if (b1 == p->p2[0] && b2 == p->p2[1])
                {
                    p->p2[0] = a1;
                    p->p2[1] = a2;
                    p->num++;
                    flag = 1;
                    break;
                }
                if (p->next == NULL)
                {
                    break;
                }
                else
                {
                    q = p->next;
                    p = q;
                }
            }
        }
        if (flag == 0)
        {
            q = (Link *)malloc(sizeof(Link));
            if (st == NULL)
            {
                st = q;
                q->p1[0] = a1;
                q->p1[1] = a2;
                q->p2[0] = b1;
                q->p2[1] = b2;
                q->num = 1;
                q->next = NULL;
            }
            else
            {
                p->next = q;
                q->p1[0] = a1;
                q->p1[1] = a2;
                q->p2[0] = b1;
                q->p2[1] = b2;
                q->num = 1;
                q->next = NULL;
            }
        }
    }
    // 输入数据完成，下面是整理过程
    q = st;
    p = q;
    Link *pst = st;
    while (1)
    {
        int flag = 0;
        if (pst == st)
        {
            // p = st;
            q = st->next;
            if (q == NULL)
            {
                break;
            }
            pst = st;
            while (1)
            {
                if (memcmp(pst->p1, q->p1, 2 * sizeof(int)) == 0)
                {
                    pst->p1[0] = q->p2[0];
                    pst->p1[1] = q->p2[1];
                    pst->num += q->num;
                    p->next = q->next;
                    free(q);
                    q = p;
                    flag = 1;
                }
                else if (memcmp(pst->p2, q->p1, 2 * sizeof(int)) == 0)
                {
                    pst->p2[0] = q->p2[0];
                    pst->p2[1] = q->p2[1];
                    pst->num += q->num;
                    p->next = q->next;
                    free(q);
                    q = p;
                    flag = 1;
                }
                else if (memcmp(pst->p1, q->p2, 2 * sizeof(int)) == 0)
                {
                    pst->p1[0] = q->p1[0];
                    pst->p1[1] = q->p1[1];
                    pst->num += q->num;
                    p->next = q->next;
                    free(q);
                    q = p;
                    flag = 1;
                }
                else if (memcmp(pst->p2, q->p2, 2 * sizeof(int)) == 0)
                {
                    pst->p2[0] = q->p1[0];
                    pst->p2[1] = q->p1[1];
                    pst->num += q->num;
                    p->next = q->next;
                    free(q);
                    q = p;
                    flag = 1;
                }
                if (q->next == NULL)
                {
                    break;
                }
                else
                {
                    p = q;
                    q = p->next;
                }
            }
            if (pst->next == NULL)
            {
                break;
            }
            else if (flag == 0)
            {
                p = pst;
                pst = p->next;
            }
        }
        else
        {
            p = st;
            q = p; //
            if (q == NULL || pst->next == NULL)
            {
                break;
            }
            else
            {
                while (1)
                {
                    if (q == pst)
                    {
                        p = q;
                        q = p->next;
                    }
                    if (memcmp(pst->p1, q->p1, 2 * sizeof(int)) == 0)
                    {
                        pst->p1[0] = q->p2[0];
                        pst->p1[1] = q->p2[1];
                        pst->num += q->num;
                        p->next = q->next;
                        free(q);
                        q = p;
                        flag = 1;
                    }
                    else if (memcmp(pst->p2, q->p1, 2 * sizeof(int)) == 0)
                    {
                        pst->p2[0] = q->p2[0];
                        pst->p2[1] = q->p2[1];
                        pst->num += q->num;
                        p->next = q->next;
                        free(q);
                        q = p;
                        flag = 1;
                    }
                    else if (memcmp(pst->p1, q->p2, 2 * sizeof(int)) == 0)
                    {
                        pst->p1[0] = q->p1[0];
                        pst->p1[1] = q->p1[1];
                        pst->num += q->num;
                        p->next = q->next;
                        free(q);
                        q = p;
                        flag = 1;
                    }
                    else if (memcmp(pst->p2, q->p2, 2 * sizeof(int)) == 0)
                    {
                        pst->p2[0] = q->p1[0];
                        pst->p2[1] = q->p1[1];
                        pst->num += q->num;
                        p->next = q->next;
                        free(q);
                        q = p;
                        flag = 1;
                    }
                    if (q->next == NULL)
                    {
                        break;
                    }
                    else
                    {
                        p = q;
                        q = p->next;
                    }
                }
            }
            if (pst->next == NULL)
            {
                break;
            }
            else if (flag == 0)
            {
                p = pst;
                pst = p->next;
            }
        }
    }
    // 下面是输出部分
    int ans = 0;
    int a1, a2, b1, b2;
    p = st;
    q = st;
    while (1)
    {
        if (q->num > ans)
        {
            a1 = q->p1[0];
            a2 = q->p1[1];
            b1 = q->p2[0];
            b2 = q->p2[1];
            ans = q->num;
            p = q;
            q = p->next;
            free(p);
        }
        else
        {
            p = q;
            q = p->next;
            free(p);
        }
        if (q == NULL)
        {
            break;
        }
    }
    printf("%d %d %d", ans, a1, a2);
    fclose(stdin);
    return 0;
}