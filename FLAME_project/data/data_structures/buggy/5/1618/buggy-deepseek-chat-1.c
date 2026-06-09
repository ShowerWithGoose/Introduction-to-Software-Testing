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
    for (k = 0; k <= i; k++) // @@ The loop condition should be k < i, not k <= i, because i is the index of the last element (0-based), so the number of elements is i+1, but after the input loop, i is the last index, so the count is i+1. However, the loop uses k <= i, which iterates one extra time (k = i+1) accessing uninitialized memory. The correct condition is k < i+1 or equivalently k <= i, but since i is the last index, the number of elements is i+1, so the loop should be k < i+1. But note: in the input loop, i is incremented only when op != '\n', so after reading the last term, i is not incremented, so i is the index of the last term. Therefore, the number of terms is i+1. The loop should be k < i+1, not k <= i. Actually, k <= i would iterate i+1 times (from 0 to i inclusive), which is correct because there are i+1 terms. Wait, let's re-evaluate: In the input loop, i starts at 0. For each term read, if op != '\n', i is incremented. When the last term is read (with '\n'), the loop breaks without incrementing i. So after the loop, i is the index of the last term. For example, if there are 2 terms, indices 0 and 1, i will be 1 after the loop. So the number of terms is i+1 = 2. The loop for (k = 0; k <= i; k++) will iterate k=0,1 (since i=1), which is correct (2 iterations). So k <= i is actually correct. The error is elsewhere.
    {
        for (r = 0; r <= j; r++) // @@ Similar to above, r <= j is correct if j is the last index. But the real issue is that the loops should iterate over all terms, and the condition should be r <= j, which is correct. However, the problem is that after the multiplication, the array shi3 may have duplicate exponents that need to be combined, but the combining logic is flawed.
        {
            shi3[l].dishu = shi1[k].dishu * shi2[r].dishu;
            shi3[l].zhishu = shi1[k].zhishu + shi2[r].zhishu;
            l++;
        }
    }
    qsort(shi3, l, sizeof(Shi), cmp);
    for (q = 0; q < l; q++)
    {
        if (shi3[q].zhishu == shi3[q + 1].zhishu) // @@ This line accesses shi3[q+1] which may be out of bounds when q = l-1. Also, the logic for combining like terms is incorrect: it only combines adjacent terms after sorting, but if there are more than two terms with the same exponent, it will not combine all of them correctly. Additionally, it sets shi3[q].dishu = 0, but then later prints only non-zero coefficients, which might skip terms that should be printed. The correct approach is to combine all terms with the same exponent into one term, not just adjacent pairs.
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