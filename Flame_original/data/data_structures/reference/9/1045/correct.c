#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long

int num[100000][5]; //0:x, 1:y, 2:a, 3:b, 4:flag
int cmp(const void *a, const void *b)
{
    int *ai = (int *)a;
    int *bi = (int *)b;
    return (*ai - *bi);
}
int ans = 0;
int begin;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d", &num[i][0], &num[i][1], &num[i][2], &num[i][3]);
    qsort(num, n, sizeof(int[5]), cmp);
    for (int i = 0; i < n; i++)
    {
        if (num[i][4] == 1)
            continue;
        int a = num[i][2];
        int b = num[i][3];
        int ansi = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (num[j][0] == a && num[j][1] == b)
            {
                ansi++;
                num[j][4] = 1;
                a = num[j][2];
                b = num[j][3];
                if (ansi > ans)
                {
                    ans = ansi;
                    begin = i;
                }
            }
        }
    }
    printf("%d %d %d\n", ans, num[begin][0], num[begin][1]);

    return 0;
}
