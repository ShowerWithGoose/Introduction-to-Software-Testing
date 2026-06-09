#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, a, k;
    int temp[4];
    int line[200][4];
    int count, max = 0;
    int x, y;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &line[i][0], &line[i][1], &line[i][2], &line[i][3]);
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (line[i][0] > line[j][0])
            {
                for (a = 0; a < 4; a++)
                {
                    temp[a] = line[i][a];
                }
                for (a = 0; a < 4; a++)
                {
                    line[i][a] = line[j][a];
                }
                for (a = 0; a < 4; a++)
                {
                    line[j][a] = temp[a];
                }
            }
    for (i = 0; i < n; i++)
    {
        count = 1;
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (line[k][2] == line[j][0] && line[k][3] == line[j][1])
            {
                count++;
                k = j;
            }
        }
        if (count > max)
        {
            max = count;
            x = line[i][0];
            y = line[i][1];
        }
    }
    printf("%d %d %d", max, x, y);
    return 0;
}
