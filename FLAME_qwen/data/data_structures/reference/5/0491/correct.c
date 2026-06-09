#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct poly{
    int num;
    int cnt;
};
struct poly a[1000], b[1000], c[1000];
typedef struct poly m;
int cmp(const void *a, const void *b);
int cmp(const void *a, const void *b)
{
    struct poly *p = (struct poly*)a;
    struct poly *q = (struct poly*)b;
    return q -> cnt - p -> cnt;
}
int main()
{
    char ch = ' ';
    int i = 0;
    char ch1 = ' ';
    int j = 0;
    while(ch != '\n')
    {
        scanf("%d %d%c", &a[i].num, &a[i].cnt, &ch);
        i++;
    }
    while(ch1 != '\n')
    {
        scanf("%d %d%c", &b[j].num, &b[j].cnt, &ch1);
        j++;
    }
    int n1 = i + 1;
    int n2 = j + 1;
    int k = 0;
    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            c[k].num = a[i].num * b[j].num;
            c[k].cnt = a[i].cnt + b[j].cnt;
            k++;
        }
    }
    for(i = 0; i < k; i++)
    {
        for(j = i + 1; j < k; j++)
        {
            if(c[i].cnt == c[j].cnt)
            {
                c[j].num = c[i].num + c[j].num;
                c[i].num = 0;
            }
        }
    }
    qsort(c, k, sizeof(m), cmp);
    for(i = 0; i < k; i++)
    {
        if(c[i].num != 0)
            printf("%d %d ",c[i].num, c[i].cnt);
    }
    return 0;
}




