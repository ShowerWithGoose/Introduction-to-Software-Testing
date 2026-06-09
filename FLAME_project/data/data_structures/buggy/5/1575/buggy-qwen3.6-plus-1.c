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
            ans3[x].mi=ans[o].mi+ans2[q].mi; // @@ [The original code calculated coefficients and exponents in two separate loops. The second loop overwrote the index x starting from 0, but more importantly, the coefficient calculation loop did not set the exponent, and the exponent calculation loop did not set the coefficient correctly relative to the same term index in a single pass. Combining them ensures each term in ans3 has both correct coefficient and exponent.]
            x++;
        }
    }
    // x=0; // @@ [This line was removed or commented out because x is already correctly incremented in the combined loop above. In the original buggy code, resetting x to 0 caused the second loop to overwrite ans3 indices starting from 0, losing the coefficients calculated in the first loop.]

    qsort(ans3,x,sizeof(struct line),cmp);
    for(int w=0;w<x;w++)
    {    
        if(ans3[w].mi==-1) continue;
        for(int e=w+1;e<x;e++) // @@ [The inner loop should start from w+1 to avoid comparing an element with itself and to avoid double processing. The original code started from 0 and skipped w==e, but this logic is flawed for accumulation because it adds ans3[w].xi to itself instead of adding ans3[e].xi to ans3[w].xi.]
        {
            // if(w==e) continue; // @@ [Removed as loop starts from w+1]
            if(ans3[w].mi==ans3[e].mi)
            {
                ans3[w].xi+=ans3[e].xi; // @@ [The original code incorrectly added ans3[w].xi to itself (ans3[w].xi+=ans3[w].xi). It should add the coefficient of the duplicate term (ans3[e].xi) to the current term (ans3[w].xi).]
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