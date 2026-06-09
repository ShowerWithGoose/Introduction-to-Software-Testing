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
    
    int minx,miny; // @@ [minx and miny are uninitialized; if no segment has count > 1, they will be used uninitialized in printf]
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
                line[i].a1=line[j].a1; // @@ [Incorrect merging: overwrites start of i without considering order, and does not ensure increasing x. Also, both segments are modified, leading to inconsistent state.]
                line[i].b1=line[j].b1; // @@ [Same issue as above.]
                line[j].a2=line[i].a2; // @@ [Incorrect: should not set j's end to i's original end; this corrupts data.]
                line[j].b2=line[i].b2; // @@ [Same issue as above.]
                cnt[i]++; // @@ [Double counting: each merger should only add one to the chain count, not increment both.]
                cnt[j]++; // @@ [Double counting: see above.]
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2; // @@ [Incorrect: overwrites end of i without proper forward extension; also corrupts j's data.]
                line[i].b2=line[j].b2; // @@ [Same issue.]
                line[j].a1=line[i].a1; // @@ [Incorrect: changes j's start to i's start, not keeping the leftmost point.]
                line[j].b1=line[i].b1; // @@ [Same issue.]
                cnt[i]++; // @@ [Double counting, same as above.]
                cnt[j]++; // @@ [Double counting.]
            }
             
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(cnt[i]>flag) // @@ [If all cnt are 1, flag remains 1, but minx/miny are not assigned; also starting point may not be leftmost.]
        {
            flag=cnt[i];
            minx=line[i].a1; // @@ [Starting point (a1,b1) may not be the leftmost endpoint if the merging was done incorrectly.]
            miny=line[i].b1; // @@ [Same issue.]
        }
    }
    printf("%d %d %d\n",flag,minx,miny);
    return 0;
}