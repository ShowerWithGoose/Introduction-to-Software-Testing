#include <math.h>
#include <stdio.h>
int m, nmin, nmax, type,i,j,k,m,count;
int a[12];
int main()
{
    scanf("%d", &m);
    nmin = m, nmax = 0;
    for (i = m; i > 0; i--)
        nmin += (m - i) * pow(10, i);
    for (i = 0; i < m; i++)
        nmax += (i + 1) * pow(10, i);
    for (i = nmin; i < nmax + 1; i++)
    {
        int temp = i;
        for (j = m - 1; j > -1; j--)
        {
            a[j] = temp % 10;
            temp /= 10;
        }
        for (k = 0; k < m - 1; k++)
        {
            for (m = k + 1; m < m; m++)
            {
                if (a[k] == a[m] || a[m] > m || a[k] > m || a[m] == 0)
                {
                    type = 1;
                    break;
                }
            }
            if (type == 1)
                break;
        }
        for (count = 0; count < m; count++)
        {
            if (type == 1)
                break;
            printf("%d ", a[count]);
        }
        if (type == 0)
        {
            i += 8;
            printf("\n");
        }
        type = 0;
    }
    return 0;
}



