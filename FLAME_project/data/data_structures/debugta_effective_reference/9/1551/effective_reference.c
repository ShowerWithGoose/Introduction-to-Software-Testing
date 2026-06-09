#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>

struct segment
{
    int x_1;
    int y_1;
    int x_2;
    int y_2;
    struct segment *next;
};

bool if_con(struct segment *p, struct segment *q)
{
    if (p->x_2 == q->x_1 && p->y_2 == q->y_1)
        return true;
    else
        return false;
}
int cmp(const void *p, const void *q)
{
    return (((struct segment *)p)->x_1) - (((struct segment *)q)->x_1);
}

int main()
{
    int num;
    scanf("%d", &num);
    struct segment input[100];
    memset(input, 0, sizeof(input));
    for (int i = 0; i < num; i++)
    {
        scanf("%d%d%d%d", &(input[i].x_1), &(input[i].y_1), &(input[i].x_2), &(input[i].y_2));
    }
    qsort(input, num, sizeof(struct segment), cmp);
    struct segment *a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i] = NULL;
    }
    struct segment *p, *q;
    for (int i = 0; i < num; i++)
    {
        int flag = 0;
        q = (struct segment *)malloc(sizeof(struct segment));
        q->x_1 = input[i].x_1;
        q->x_2 = input[i].x_2;
        q->y_1 = input[i].y_1;
        q->y_2 = input[i].y_2;
        int j;
        for (j = 0; a[j] != NULL; j++)
        {
            p = a[j];
            while (p->next != NULL)
            {
                p = p->next;
            }
            if (if_con(p, q))
            {
                p->next = q;
                q->next = NULL;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            a[j] = q;
            a[j]->next = NULL;
        }
    }
    int max_num = 0, cur_num, flag;
    for (int i = 0; a[i] != NULL; i++)
    {
        p = a[i];
        for (cur_num = 1; p->next != NULL; cur_num++)
        {
            p = p->next;
        }
        if (cur_num > max_num)
        {
            max_num = cur_num;
            flag = i;
        }
    }
    printf("%d %d %d", max_num, a[flag]->x_1, a[flag]->y_1);
    return 0;
}
