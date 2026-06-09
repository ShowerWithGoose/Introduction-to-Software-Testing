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
    x=0; // @@ [This resets x to 0, discarding the previously stored coefficients. The exponents are then written to the same array but starting from index 0, causing coefficient and exponent data to be misaligned.]
    for(int o=0;o<i;o++)
    {
        for(int q=0;q<n;q++)
        {
            ans3[x].mi=ans[o].mi+ans2[q].mi;
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
                ans3[w].xi+=ans3[w].xi; // @@ [This should add ans3[e].xi to ans3[w].xi, not double ans3[w].xi. This causes incorrect coefficient accumulation.]
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