#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lines
{
    int x1;
    int y1;
    int x2;
    int y2;
    int lines_num;
} l[64];

int main()
{
    int i, j, k;
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        scanf("%d%d%d%d", &l[j].x1, &l[j].y1, &l[j].x2, &l[j].y2);
        l[j].lines_num = 1;
    }

    int n = i;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
            {
                if (l[j].x2 == l[k].x1 && l[j].y2 == l[k].y1)
                {
                    l[j].x2 = l[k].x2;
                    l[j].y2 = l[k].y2;
                    l[j].lines_num += l[k].lines_num;
                    l[k].x1 = 0;
                    l[k].x2 = 0;
                    l[k].y1 = 0;
                    l[k].y2 = 0;
                    l[k].lines_num = 0;
                }
            }

    int max = 0;
    int flag = -1;
    for (i = 0; i < n; i++)
    {
        if(l[i].lines_num>=max)
        {
            flag = i;
            max = l[i].lines_num;
        }
    }

    printf("%d %d %d\n", l[flag].lines_num, l[flag].x1, l[flag].y1);

    system("pause");
    return 0;
}
