#include <stdio.h>
#include <stdlib.h>

typedef struct _line
{
    int point1[2];
    int point2[2];
} Line;

int main()
{
    int N, i = 0, j = 0, p = 0, pd = 0;
    int max = 0, num = 0;
    scanf("%d", &N);
    Line lines[101], temp, out_line;
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &lines[i].point1[0], &lines[i].point1[1], &lines[i].point2[0], &lines[i].point2[1]);
    }

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (lines[i].point1[0] > lines[j].point1[0])
            {
                temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
        do
        {
            for (j = i + 1, pd = 0; j < N; j++)
            {
                if (lines[i].point2[0] == lines[j].point1[0] && lines[i].point2[1] == lines[j].point1[1])
                {
                    temp = lines[i + 1];
                    lines[i + 1] = lines[j];
                    lines[j] = temp;
                    pd = 1;
                    i++;
                }
            }
        } while (pd != 0);
    }

    for (i = 0; i < N; i++)
    {
        for (p = i, num = 1, j = i + 1; j < N; j++)
        {
            if (lines[p].point2[0] == lines[j].point1[0] && lines[p].point2[1] == lines[j].point1[1])
            {
                num++;
                p++;
            }
        }
        if (num > max)
        {
            max = num;
            out_line = lines[i];
        }
    }
    printf("%d %d %d", max, out_line.point1[0], out_line.point1[1]);
    return 0;
}
