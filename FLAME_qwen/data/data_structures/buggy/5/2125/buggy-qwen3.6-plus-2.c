/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int factor, exponent;
}term;

int cmp(const void*, const void*);

term a1[50000], a2[50000], ans[50000], temp[50000];

int main()
{
    int i, j;
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a1[i].factor, &a1[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len1 = i + 1;
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    
    int n = len1 * len2;
    for(i = 0; i < len1; i++)
    {
        for(j = 0; j < len2; j++)
        {
            ans[i * len2 + j].factor = a1[i].factor * a2[j].factor;
            ans[i * len2 + j].exponent = a1[i].exponent + a2[j].exponent;
        }
    }
    int a[50000] = {}; // @@ Compilation error: empty initializer list is not valid in standard C; should be {0}.
    for(i = 0; i < n; i++)
        a[i] = i;
    qsort(a, n, sizeof(int), cmp);
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++)
    {
        if(temp[i - 1].exponent == temp[i]. exponent) // @@ Syntax error: invalid space between '.' and 'exponent' causes compilation failure.
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ Logical error: after decrementing n, the loop condition should be j < n to correctly shift all remaining elements left.
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--;
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent);
    
    return 0;
}

int cmp(const void *p, const void *q)
{
    int x = *(int*)p, y = *(int*)q;
    if(ans[x].exponent > ans[y].exponent)
        return -1;
    if(ans[x].exponent < ans[y].exponent)
        return 1;
    return 0;
}