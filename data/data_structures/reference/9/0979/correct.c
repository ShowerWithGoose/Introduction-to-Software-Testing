#include <stdio.h>
int find(int num, int x[][2], int y[][2], int count, int i, int p, int q, int n)
{
    int j;
    for (j = 0; j < num; j++)
    {
        if (j != i && j != n)
        {
            if ((x[j][p] == x[i][q] && y[j][p] == y[i][q]) || (x[j][q] == x[i][q] && y[j][q] == y[i][q]))
            {
                count++;
                if (x[j][p] == x[i][q])
                    count = find(num, x, y, count, j, p, q, i);
                else
                    count = find(num, x, y, count, j, q, p, i);
                return count;
            }
        }
    }
    return count;
}
int main()
{
    int num, flag = 0, x[100][2], y[100][2], i, j, count = 0, tmp, locx, locy;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d%d%d%d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
    }
    for (i = 0; i < num; i++)
    {
        flag = 0;
        for (j = 0; j < num; j++)
        {
            if (((x[i][0] == x[j][0] && y[i][0] == y[j][0]) || (x[i][0] == x[j][1] && y[i][0] == y[j][1])) && (j != i))
            {
                flag=1;
                break;
            }
            // else
            // {
            //     tmp = find(num, x, y, 1, i, 0, 1, -1);
            //     if (tmp > count)
            //     {
            //         count = tmp;
            //         locx = x[i][0];
            //         locy = y[i][0];
            //     }
            // }
        }
        if (flag == 0)
        {
            tmp = find(num, x, y, 1, i, 0, 1, -1);
            if (tmp > count)
            {
                count = tmp;
                locx = x[i][0];
                locy = y[i][0];
            }
        }
    }
    printf("%d %d %d", count, locx, locy);
    return 0;
}
