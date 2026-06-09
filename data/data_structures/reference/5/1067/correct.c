#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define maxn 1000
typedef struct 
{
    int exp;
    int ind;
}node;
node a[maxn], b[maxn], mul[maxn], ans[maxn];
int Comp(const void *a, const void *b)
{
    node *A = (node *)a;
    node *B = (node *)b;
    return(B->exp - A->exp);
}
int main()
{
    int i = -1;
    char ch = 0;
    //scanf("%d%d", &a[i].ind, &a[i].exp);
    //ch = getchar();
    while(ch != '\n')
    {
        i ++;
        scanf("%d%d", &a[i].ind, &a[i].exp);
        ch = getchar();
    }
    int lena = ++ i;
    i = -1;
    ch = 0;
    //scanf("%d%d", &b[i].ind, &b[i].exp);
    //ch = getchar();
    while(ch != '\n')
    {
        i ++;
        scanf("%d%d", &b[i].ind, &b[i].exp);
        ch = getchar();
    }
    int lenb = ++ i;
    int k = 0;
    for(i = 0; i < lena; i ++)
    {
        for(int j = 0; j < lenb; j ++)
        {
            mul[k].exp = a[i].exp + b[j].exp;
            mul[k].ind = a[i].ind * b[j].ind;
            k ++;
        }
    }
    int tmp, flag = 0, l = -1;
    qsort(mul, k, sizeof(node), Comp);
    for(i = 0; i < k; i ++)
    {
        if(tmp != mul[i].exp)
            flag = 1;
        else flag = 0;
        if(flag == 1)
        {
            ans[++ l].exp = mul[i].exp;
        }
        ans[l].ind += mul[i].ind;
        tmp = mul[i].exp;
    }
    for(i = 0; i <= l ; i ++)
        printf("%d %d ", ans[i].ind, ans[i].exp);
}
