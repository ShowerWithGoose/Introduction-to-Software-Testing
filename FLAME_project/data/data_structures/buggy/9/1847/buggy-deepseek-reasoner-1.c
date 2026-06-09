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
    
    int minx,miny;
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
                line[i].a1=line[j].a1; // @@ [Overwrites the start of i with j's start; should not modify both segments to have identical endpoints]
                line[i].b1=line[j].b1; // @@ [Same issue]
                line[j].a2=line[i].a2; // @@ [Makes j's end equal to i's old end, creating duplicate representation of the same merged segment]
                line[j].b2=line[i].b2; // @@ [Same issue]
                cnt[i]++; // @@ [Only increments by 1 instead of adding the total count of the merged chain]
                cnt[j]++; // @@ [Same; does not accumulate chain length correctly]
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2; // @@ [Overwrites the end of i with j's end; should not duplicate endpoints]
                line[i].b2=line[j].b2; // @@ [Same issue]
                line[j].a1=line[i].a1; // @@ [Makes j's start equal to i's old start, creating duplicate]
                line[j].b1=line[i].b1; // @@ [Same issue]
                cnt[i]++; // @@ [Increment only 1, insufficient]
                cnt[j]++; // @@ [Increment only 1, insufficient]
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
    printf("%d %d %d\n",flag,minx,miny);
    return 0;
}