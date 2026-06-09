#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#define ll long long
typedef struct An
{
    int xishu;
    int zhishu;
} DXS;
DXS a[1000], b[1000], c[1000];
int i, j, k, s;

int cmp(const void *p1, const void *p2)
{
    DXS *a = (DXS *)p1;
    DXS *b = (DXS *)p2;
    return -(a->zhishu - b->zhishu);
}

int main()
{
    while (1)
    {
        scanf("%d %d", &a[i].xishu, &a[i].zhishu);
        i++;
        if (getchar() == '\n')
            break;
    }
    int lena = i;
    while (1)
    {
        scanf("%d %d", &b[j].xishu, &b[j].zhishu);
        j++;
        if (getchar() == '\n')
            break;
    }
    int lenb = j;
    for (i = 0; i < lena; i++)
    {
        for (j = 0; j < lenb; j++)
        {
            c[k].xishu = a[i].xishu * b[j].xishu;
            c[k++].zhishu = a[i].zhishu + b[j].zhishu;
        }
    }
    qsort(c, k, sizeof(DXS), cmp);
    for (j = 0; j < k; j++)
    {
        c[s].xishu = c[j].xishu;
        for (i = j; i < k; i++)
        {
            if (c[i + 1].zhishu == c[i].zhishu)
            {
                c[s].xishu += c[i + 1].xishu;
                c[i + 1].xishu = 0;
            }else break;
        }
        s++;
    }

    for (i = 0; i < s; i++)
        if(c[i].xishu) printf("%d %d ", c[i].xishu, c[i].zhishu);
    return 0;
}

// for (i = 0; i < k;)
// {
//     c[s].zhishu = c[i].zhishu;
//     int flag = 0;
//     for (j = i + 1; j < k; j++)
//     {
//         if (c[i].zhishu == c[j].zhishu)
//         {
//             c[s].xishu += c[j].xishu;
//             flag = 1;
//         }
//         else
//             break;
//     }
//     i = j;
//     if(flag)
//         i--;
//     s++;
// }
