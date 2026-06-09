#include <stdio.h>
#include <math.h>

#define MAXN 100000

void perorder(int t[], int b);

int main()
{
    int n;
    scanf("%d", &n);
    int t[MAXN];
    for (int i = 0; i < MAXN; i++)
        t[i] = -100;
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        if (i == 1)
            t[i] = num;
        else
        {
            int j = 1;
            while (t[j] != -100)
                if (num >= t[j])
                    j = 2 * j + 1;
                else
                    j *= 2;
            t[j] = num;
        }
    }
    perorder(t, 1);
}

void perorder(int t[], int b)
{
    if (t[2 * b] == -100 && t[2 * b + 1] == -100)
    {
        int cnt = 0;
        for (int k = b; k; k /= 2, cnt++)
            ;
        printf("%d %d\n", t[b], cnt);
        return;
    }
    if (t[2*b] != -100)
        perorder(t, 2 * b);
    if (t[2*b + 1] != -100)
        perorder(t, 2 * b + 1);
    
}

