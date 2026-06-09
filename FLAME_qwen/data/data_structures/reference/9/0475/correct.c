#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    int x1, y1, x2, y2;
    struct link *next;
    struct link *front;
};
int main()
{
    struct link **line, *p;
    int n, i, j, max = 0, l, x0, y0, xout, yout;
    scanf("%d", &n);
    line = (struct link **)malloc(sizeof(struct link *) * n);
    for (i = 0; i < n; i++)
    {
        line[i] = (struct link *)malloc(sizeof(struct link));
    }
    for (i = 0; i < n; i++) //读取
    {
        scanf("%d%d%d%d", &((*(line + i))->x1), &((*(line + i))->y1), &((*(line + i))->x2), &((*(line + i))->y2));
        (*(line + i))->next = NULL;
        (*(line + i))->front = NULL;
    }
    for (i = 0; i < n; i++) //连线
    {
        // test1 = *(line + i);
        for (j = 0; j < i; j++)
        {
            //  test2 = *(line + j);
            if ((*(line + j))->next == NULL && (*(line + i))->front == NULL)
            {
                if ((*(line + j))->x2 == (*(line + i))->x1 && (*(line + j))->y2 == (*(line + i))->y1)
                {
                    (*(line + j))->next = *(line + i);
                    (*(line + i))->front = *(line + j);
                }
            }
            if ((*(line + j))->front == NULL && (*(line + i))->next == NULL)
            {
                if ((*(line + j))->x1 == (*(line + i))->x2 && (*(line + j))->y1 == (*(line + i))->y2)
                {
                    (*(line + j))->front = *(line + i);
                    (*(line + i))->next = *(line + j);
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        p = *(line + i);
        if (p->front == NULL)
        {
            l = 1;
            x0 = p->x1;
            y0 = p->y1;
            while (p->next != NULL)
            {
                l++;
                p = p->next;
            }
            if (l > max)
            {
                max = l;
                xout = x0;
                yout = y0;
            }
        }
    }
    printf("%d %d %d", max, xout, yout);
    for (i = 0; i < n; i++)
    {
        free(line[i]);
    }
    free(line);
    return 0;
}
