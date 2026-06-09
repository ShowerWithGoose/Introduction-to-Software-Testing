#include<stdio.h>
#include<stdlib.h>
struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct node* link;
}a[105],temp;
typedef struct node node;
typedef struct node* nodeptr;
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    }
    int j, flag;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = i + 1; j < n; j++)
        {
            if (a[j].x1 < a[i].x1)
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    int cnt, max = 0, now,startx,starty;
    for (i = 0; i < n; i++)
    {
        cnt = 1;
        now = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j].x1 == a[now].x2 && a[j].y1 == a[now].y2)
            {
                now = j;
                cnt++;
            }
        }
        if (cnt > max)
        {
            max = cnt;
            startx = a[i].x1;
            starty = a[i].y1;
        }
    }
    printf("%d %d %d", max, startx, starty);
    return 0;
}

