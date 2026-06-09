#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Lines{
    int a1;
    int b1;
    int a2;
    int b2;
}line[100];

int main(int argc, char *argv[]) 
{
    int n,i,j;
    int flag=1;
    int cnt[100];
    
    int minx,miny; // @@ [minx and miny are used uninitialized if no cnt[i] > flag (i.e., when all cnt[i] == 1). This leads to undefined behavior when printing them.]
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&(line[i].a1),&(line[i].b1),&(line[i].a2),&(line[i].b2));
        cnt[i]=1;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==i) continue;
            if((line[i].a1==line[j].a2)&&(line[i].b1==line[j].b2))
            {
                line[i].a1=line[j].a1;
                line[i].b1=line[j].b1;
                line[j].a2=line[i].a2;
                line[j].b2=line[i].b2;
                cnt[i]++;
                cnt[j]++; // @@ [Incorrectly incrementing cnt[j] breaks the count logic. When merging segments, only one of the segments should absorb the other; incrementing both double-counts shared segments and corrupts the chain length.]
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2;
                line[i].b2=line[j].b2;
                line[j].a1=line[i].a1;
                line[j].b1=line[i].b1;
                cnt[i]++;
                cnt[j]++; // @@ [Same error as above: cnt[j] should not be incremented here. This causes overcounting and incorrect segment counts.]
            }
             
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(cnt[i]>flag)
        {
            flag=cnt[i];
            minx=line[i].a1;
            miny=line[i].b1;
        }
    }
    printf("%d %d %d\n",flag,minx,miny); // @@ [If all cnt[i] are 1 (no connections), minx and miny remain uninitialized, leading to undefined output. Also, due to overcounting from earlier errors, flag may be wrong.]
    return 0;
}