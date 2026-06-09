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
    
    int minx,miny; // @@ Variables minx and miny are uninitialized; if no merges occur, they will hold garbage values when printed.
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
                line[j].a2=line[i].a2; // @@ Incorrectly modifies line[j]'s endpoint; should mark line[j] as used (e.g., set cnt[j]=0) to prevent double counting and incorrect merges.
                line[j].b2=line[i].b2;
                cnt[i]++; // @@ Should add cnt[j] to cnt[i] (cnt[i] += cnt[j]) because cnt[j] may already represent multiple merged segments.
                cnt[j]++; // @@ Should set cnt[j] = 0 to mark the segment as merged/used, otherwise it will be counted again in later iterations.
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2;
                line[i].b2=line[j].b2;
                line[j].a1=line[i].a1; // @@ Incorrectly modifies line[j]'s start point; should mark line[j] as used instead.
                line[j].b1=line[i].b1;
                cnt[i]++; // @@ Should add cnt[j] to cnt[i] (cnt[i] += cnt[j]) for correct segment count accumulation.
                cnt[j]++; // @@ Should set cnt[j] = 0 to mark the segment as merged/used.
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