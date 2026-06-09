#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int coe;
    int pow;
}node;
node node0[10001], node1[10001], node2[10001];

int cmp(const void *a,const void *b)
{
    node*p1=(node*)a;
    node*p2=(node*)b;
    return p1->pow<p2->pow?1:-1;
}

int main()
{
    int i = 0, j = 0, k = 0, cnt1 = 0, cnt2 = 0;
    char c1, c2;
    do
    {
        scanf("%d%d%c", &node1[i].coe, &node1[i].pow, &c1);
        cnt1++;i++;
    }while(c1 != '\n');
    i = 0;
    do
    {
        scanf("%d%d%c", &node2[i].coe, &node2[i].pow, &c2);
        cnt2++;i++;
    }while(c2 != '\n');
    for(i = 0, k = 0; i < cnt1; i++)
    {
        for(j = 0; j < cnt2; j++)
        {
            node0[k].coe = node1[i].coe * node2[j].coe;
            node0[k].pow = node1[i].pow + node2[j].pow;
            k++;
        }
    }
    int len = k;
    qsort(node0, len, sizeof(node), cmp);
    for(i = 0; i < len; i++)
    {
        if(node0[i].pow == node0[i+1].pow) // @@ [Accessing node0[i+1] when i = len-1 leads to out-of-bounds; also only compares consecutive elements, missing longer runs of equal exponents]
        {
            node0[i].coe += node0[i+1].coe;
            node0[i+1].coe = 0;
            i++; // @@ [Incrementing i inside loop, combined with for loop increment, may skip indices and cause out-of-bounds]
        }
    }
    for(i = 0;i < len; i++){
    if(node0[i].coe != 0)
        printf("%d %d ", node0[i].coe, node0[i].pow);
    }
    return 0;    
}