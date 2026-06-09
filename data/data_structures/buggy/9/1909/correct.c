#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
struct line
{
    int leftx;
    int lefty;
    int rightx;
    int righty;
    struct line *to;
    struct line *up;
    int times;
};
void checklink(struct line *a, struct line *b)
{
    struct line *temp;
    int time;
    if (a->leftx < b->leftx)
    {
        if (a->rightx == b->leftx && a->righty == b->lefty)
        {
            temp = a;
            a->to = b;
            b->up = a;
            time = b->times + a->times;
            while (temp != NULL)
            {
                temp->times = time;
                temp = temp->up;
            }
            temp = a;
            while (temp != NULL)
            {
                temp->times = time;
                temp = temp->to;
            }
        }
    }
    else if (a->leftx > b->leftx)
    {
        if (b->rightx == a->leftx && b->righty == a->lefty)
        {
            temp = a;
            b->to = a;
            a->up = b;
            time = b->times + a->times;
            a->times = time;
            b->times = time;
            while (temp != NULL)
            {
                temp->times = time;
                temp = temp->up;
            }
            temp = a;
            while (temp != NULL)
            {
                temp->times = time;
                temp = temp->to;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    struct line total[200];
    for (int i = 0; i < 200; i++)
    {
        total[i].up = NULL;
        total[i].times = 1;
        total[i].to = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &total[i].leftx, &total[i].lefty, &total[i].rightx, &total[i].righty);
        for (int u = 0; u < i; u++)
        {
            checklink(&total[u], &total[i]);
        }
    }
    int ma = total[0].times;
    int name = 0;
    for (int i = 0; i < n; i++)
    {
        if (total[i].times > ma)
        {
            name = i;
            ma = total[i].times;
        }
    }
    struct line *tem = &total[name];
    while (tem->up != NULL)
    {
        tem = tem->up;
    }
    printf("%d %d %d", tem->times, tem->leftx, tem->lefty);

    return 0;
}
