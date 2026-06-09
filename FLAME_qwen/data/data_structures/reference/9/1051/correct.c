#include <stdio.h>
#include <string.h>
struct list
{
    int X1, X2, Y1, Y2;
    int flag;
    int count;
    struct list *next;
};
struct list line[105];
struct list *temp;
int main()
{
    int n, i, j, max = -1;
    int ansx = 0, ansy = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &line[i].X1, &line[i].Y1, &line[i].X2, &line[i].Y2);
        line[i].flag = 0;
        line[i].count = 1;
        line[i].next = NULL;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if ((line[i].X1 == line[j].X2) && (line[i].Y1 == line[j].Y2))
            {
                line[i].flag = 1;
                line[j].next = &(line[i]);
            }
            else if ((line[i].X2 == line[j].X1) && (line[i].Y2 == line[j].Y1))
            {
                line[j].flag = 1;
                line[i].next = &(line[j]);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        temp = line[i].next;
        while (temp != NULL)
        {
            line[i].count++;
            temp = temp->next;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (line[i].flag == 0)
        {
            if (line[i].count > max)
            {
                max = line[i].count;
                ansx = line[i].X1;
                ansy = line[i].Y1;
            }
        }
    }
    printf("%d %d %d", max, ansx, ansy);
    return 0;
}
