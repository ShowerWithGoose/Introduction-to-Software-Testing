#include <stdio.h>
#include <stdlib.h>
struct line
{
    int x1;
    int x2;
    int y1;
    int y2;
    struct line *next;
};
void link(struct line *segement, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else
            {
                if (((segement + i)->x2 == (segement + j)->x1) && ((segement + i)->y2 == (segement + j)->y1))
                {
                    (segement + i)->next = (segement + j);
                }
            }
        }
    }
}
int judge(struct line *segement)
{
    int count = 0;
    while (segement->next != NULL)
    {
        segement = segement->next;
        count++;
    }
    return count;
}
int main()
{
    struct line *segement, *begin1, *begin2;
    int n;
    scanf("%d", &n);
    begin1 = segement = (struct line *)malloc(sizeof(struct line) * n);
    for (int i = 0; i < n; i++)
    {
        struct line *q;
        q = (struct line *)malloc(sizeof(struct line));
        q = NULL;
        scanf("%d%d%d%d", &(segement + i)->x1, &(segement + i)->y1, &(segement + i)->x2, &(segement + i)->y2);
        (segement + i)->next = q;
    }
    link(segement, n);
    int max = -1;
    struct line *temp;
    for (int i = 0; i < n; i++)
    {
        int m = judge(segement + i);
        if (m > max)
        {
            max = m;
            temp = segement + i;
        }
    }
    printf("%d %d %d", max + 1, temp->x1, temp->y1);
}



