#include <stdio.h>
#include <stdlib.h>
struct term
{
    int coe;
    int pow;
} list1[1024], list2[1024], list3[1024];
int cmp(const void *p1, const void *p2)
{
    struct term *a = (struct term *)p1;
    struct term *b = (struct term *)p2;
    return b->pow - a->pow;
}
int main()
{
    int m = 0, n = 0;
    char c;
    do
    {
        scanf("%d%d%c", &list1[m].coe, &list1[m].pow, &c);
        m++;

    } while (c != '\n');
    do
    {
        scanf("%d%d%c", &list2[n].coe, &list2[n].pow, &c);
        n++;

    } while (c != '\n');
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int powplus = list1[i].pow + list2[j].pow;
            int coemul = list1[i].coe * list2[j].coe;
            int op = 0;
            for (int p = k - 1; p >= 0; p--) // @@ The loop should start from k-1, not k, because list3 indices go from 0 to k-1. Accessing list3[k] is out of bounds and may cause undefined behavior or miss existing terms.
            {
                if (powplus == list3[p].pow)
                {
                    list3[p].coe += coemul;
                    op = 1;
                    break; // @@ Missing break after combining like terms; without it, the same term might be added multiple times if there are duplicate exponents later in the array (though unlikely here due to logic, but still logically incorrect).
                }
            }
            if (op == 1)
            {
                continue;
            }
            else
            {
                list3[k].coe = coemul;
                list3[k].pow = powplus;
                k++;
            }
        }
    }
    qsort(list3, k, sizeof(list3[0]), cmp);
    for (int i = 0; i < k; i++)
    {
        printf("%d %d ", list3[i].coe, list3[i].pow);
    }
    return 0;
}