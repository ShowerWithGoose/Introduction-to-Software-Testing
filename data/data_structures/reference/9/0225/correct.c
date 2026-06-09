#include <stdio.h>

struct Line
{
    int x1, x2, y1, y2;
    int father1, father2;
}L[200];

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d", &L[i].x1, &L[i].y1, &L[i].x2, &L[i].y2);
        L[i].father1 = i;
        L[i].father2 = i;
        for (int j = 0; j < i; j++)
        {
            if (L[j].x1 == L[i].x1 && L[j].y1 == L[i].y1)
            {
                L[i].father1 = j;
                L[j].father1 = i;
            }
            if (L[j].x2 == L[i].x1 && L[j].y2 == L[i].y1)
            {
                L[i].father1 = j;
                L[j].father2 = i;
            }
            if (L[j].x1 == L[i].x2 && L[j].y1 == L[i].y2)
            {
                L[i].father2 = j;
                L[j].father1 = i;
            }
            if (L[j].x2 == L[i].x2 && L[j].y2 == L[i].y2)
            {
                L[i].father2 = j;
                L[j].father2 = i;
            }
        }
    }
    int max = 0, maxX = 0, maxY = 0;
    for (int i = 0; i < t; i++)
    {
        int cnt = 0;
        int j = i;
        while (1)
        {
            if (L[j].father2 == j)
            {
                break;
            }
            j = L[j].father2;
            cnt++;
        }
        if (cnt > max)
        {
            max = cnt;
            maxX = L[i].x1;
            maxY = L[i].y1;
        }
    }
    printf("%d %d %d", max + 1, maxX, maxY);
    return 0;
}

