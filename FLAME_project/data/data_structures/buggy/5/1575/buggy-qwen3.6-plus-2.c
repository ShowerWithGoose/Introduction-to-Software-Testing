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
            ans3[x].xi=ans[o].xi*ans2[q].xi; // @@ [Logic Error: The coefficient and exponent for the same term are calculated in separate loops. Here only the coefficient is set, but the exponent is uninitialized/garbage until the next loop runs. This separates the data incorrectly.]
            x++;
        }
    }
    x=0; // @@ [Logic Error: Resetting x to 0 here overwrites the count of terms generated in the previous loop. The subsequent loop will overwrite the coefficients calculated above starting from index 0, and the total count x will be incorrect (only reflecting the second loop's iterations if it weren't for the overwrite). The multiplication logic should be in a single nested loop setting both .xi and .mi and incrementing x once.]
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
                ans3[w].xi+=ans3[w].xi; // @@ [Calculation Error: This adds the coefficient to itself (doubling it) instead of adding the coefficient of the matching term ans3[e].xi. It should be ans3[w].xi += ans3[e].xi.]
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