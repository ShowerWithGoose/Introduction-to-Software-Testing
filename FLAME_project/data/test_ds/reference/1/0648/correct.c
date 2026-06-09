#include <stdio.h>
#include <string.h>
char n[100000], o[100000];
void sert(int a, int b, int c, int d)
{
    int p;
    for (b = 1; b <= c; b++)
    {
        n[a + b - 1] = n[a - 1] + b;
    }
    for (p = 0; p < d; p++)
    {
        n[a + c + p] = o[p];
    }
}
int main()
{
    gets(n);
    int  a = 0,b,c,d = 0,k,l,m;
    int e, f, g, h, i, j;
    m = strlen(n);
    for (a = 0; a < m; a++)
    {
        if (n[a] == '-' && n[a + 1] > n[a - 1])
        {
            c = n[a + 1] - n[a - 1] - 1;
            k = a;
            for (k++, d = 0; k < m; k++, d++)
            {
                o[d] = n[k];
            }
            e = n[a - 1] - 'a';
            f = n[a + 1] - 'a';
            g = n[a - 1] - 'A';
            h = n[a + 1] - 'A';
            i = n[a - 1] - '0';
            j = n[a + 1] - '0';
            if (0 <= e && e < 25 && 0 < f && f <= 25)
            {
                sert(a, b, c, d);
            }
            else if (0 <= g && g < 25 && 0 < h && h <= 25)
            {
                sert(a, b, c, d);
            }
            else if (j <= 9 && 0 < j && 0 <= i && i < 9 )
            {
                sert(a, b, c, d);
            }
            m = strlen(n);
        }
    }
    printf("%s", n);
    return 0;
}
