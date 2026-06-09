#include <stdio.h>
struct line
{
    int a[2];
    int b[2];
} lines[105], temp1;
int main()
{
    int n, i, j, k, a, b, max, num, ansa, ansb;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &lines[i].a[0], &lines[i].a[1], &lines[i].b[0], &lines[i].b[1]);
    }
    for (max = 1, k = 1; k <= n; k++)
    {
        temp1 = lines[k];
        for (num = 1, i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (lines[j].a[0] == temp1.b[0] && lines[j].a[1] == temp1.b[1])
                {
                    num++;
                    temp1.b[0] = lines[j].b[0];
                    temp1.b[1] = lines[j].b[1];
                    break;
                }
            }
        }
        if (num >= max)
        {
            max = num;
            ansa = temp1.a[0];
            ansb = temp1.a[1];
        }
    }
    printf("%d %d %d\n", max, ansa, ansb);
    return 0;
}
