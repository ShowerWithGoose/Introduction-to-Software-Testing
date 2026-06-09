#include <stdio.h>
#include <stdlib.h>
typedef struct Shi_
{
    int dishu;
    int zhishu;
} Shi;
int cmp(const void *p1, const void *p2)
{
    Shi *s1 = (Shi *)p1;
    Shi *s2 = (Shi *)p2;
    return s2->zhishu - s1->zhishu;
}
int main()
{
    Shi shi1[1000];
    Shi shi2[1000];
    Shi shi3[2000];
    int i = 0, j = 0, k, r, l = 0, q;
    char op;
    while (scanf("%d %d%c", &shi1[i].dishu, &shi1[i].zhishu, &op) != EOF)
    {
        if (op != '\n')
        {
            i++;
        }
        else
        {
            break;
        }
    }
    while (scanf("%d %d%c", &shi2[j].dishu, &shi2[j].zhishu, &op) != EOF)
    {
        if (op != '\n')
        {
            j++;
        }
        else
        {
            break;
        }
    }
    qsort(shi1,i,sizeof(Shi),cmp);
    qsort(shi2,j,sizeof(Shi),cmp);
    for (k = 0; k <= i; k++) // @@ Error: Loop condition should be k < i, not k <= i, because i is the index of the last element (0-based), so the number of elements is i+1, but the loop should iterate over all elements, so condition should be k <= i is correct? Actually, after the input loop, i is the index of the last read element, so the number of elements is i+1. The loop should go from 0 to i inclusive, so k <= i is correct. However, the input loop increments i only when op != '\n', so after reading the last term, i is not incremented, so i is the index of the last term. Thus the number of terms is i+1. So the loop should be k <= i. But wait: the input loop breaks when op == '\n' without incrementing i, so i is the index of the last term. So the number of terms is i+1. So the loop should be k <= i. However, the reference program uses x and y as counts (number of terms), so loops go from 0 to x-1. Here, i is not a count but an index. So the loop should be k <= i. But then the inner loop also uses r <= j, which is similar. This is actually correct if i and j are indices of the last term. However, the problem is that after the input loop, i and j are the indices of the last term, so the number of terms is i+1 and j+1. So the loops should be k <= i and r <= j. But then the multiplication will produce (i+1)*(j+1) terms, which is correct. So this line is not necessarily an error. But the error might be elsewhere.
    {
        for (r = 0; r <= j; r++) // @@ Error: Same issue as above, should be r <= j if j is the index of the last term, but the reference program uses counts, so this might be correct. However, the problem is that the input loop increments i and j only when op != '\n', so after reading the last term, i and j are not incremented, so they are indices. So the loops should be k <= i and r <= j. But then the array shi3 might overflow because l will become (i+1)*(j+1) which could exceed 2000. But that's a different issue.
        {
            shi3[l].dishu = shi1[k].dishu * shi2[r].dishu;
            shi3[l].zhishu = shi1[k].zhishu + shi2[r].zhishu;
            l++;
        }
    }
    qsort(shi3, l, sizeof(Shi), cmp);
    for (q = 0; q < l; q++)
    {
        if (shi3[q].zhishu == shi3[q + 1].zhishu) // @@ Error: Accessing shi3[q+1] when q = l-1 causes out-of-bounds access. Should check q < l-1.
        {
            shi3[q+1].dishu = shi3[q].dishu + shi3[q + 1].dishu;
            shi3[q].dishu = 0;
        }
    }
    for (q = 0; q < l; q++)
    {
        if (shi3[q].dishu != 0)
        {
            printf("%d %d ", shi3[q].dishu, shi3[q].zhishu);
        }
    }
    return 0;
}