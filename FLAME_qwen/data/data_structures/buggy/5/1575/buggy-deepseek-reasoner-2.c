#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024
typedef struct line {
    int xi;
    int mi;
} line;
int cmp(const void* a,const void* b)
{
    return ((struct line *)b)->mi - ((struct line *)a)->mi;
}

int main() {
    line ans[MAX];
    line ans2[MAX];
    line ans3[MAX];
    char ch;
    int i = 0;
    int n = 0;
    int x = 0;
    do {
        scanf("%d%d%c", &ans[i].xi, &ans[i].mi, &ch);
        i++;
    } while (ch != '\n');
    do {
        scanf("%d%d%c", &ans2[n].xi, &ans2[n].mi, &ch);
        n++;
    } while (ch != '\n');

    for(int o=0;o<i;o++)
    {
        for(int q=0;q<n;q++)
        {
            ans3[x].xi=ans[o].xi*ans2[q].xi;
            x++;
        }
    }
    x=0; // @@ Error: Resetting x causes the exponent values to overwrite the coefficient values from the previous loop. The product terms' coefficients and exponents are stored separately, leading to incorrect results. They should be stored together in the same loop.
    for(int o=0;o<i;o++)
    {
        for(int q=0;q<n;q++)
        {
            ans3[x].mi=ans[o].mi+ans2[q].mi; // @@ Error: Overwrites the previously stored coefficient at index x with the exponent, losing the coefficient. Additionally, the index x is reset to 0, so this loop writes exponent values over the coefficient values from the first loop.
            x++;
        }
    }

    qsort(ans3,x,sizeof(struct line),cmp);
    for(int w=0;w<x;w++)
    {    
        if(ans3[w].mi==-1) continue;
        for(int e=0;e<x;e++)
        {
            if(w==e) continue;
            if(ans3[w].mi==ans3[e].mi)
            {
                ans3[w].xi+=ans3[w].xi; // @@ Error: This doubles the coefficient of the current term instead of adding the coefficient of the other term (ans3[e].xi). It should be ans3[w].xi += ans3[e].xi.
                ans3[e].xi=0;ans3[e].mi=-1;    
            }
        }
    }
        for(int w=0;w<x;w++)
        {
            if(ans3[w].xi!=0)
            printf("%d %d ",ans3[w].xi,ans3[w].mi);
        }
    
    return 0;
}