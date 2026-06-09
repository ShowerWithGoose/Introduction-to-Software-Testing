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
                line[i].a1=line[j].a1;
                line[i].b1=line[j].b1;
                line[j].a2=line[i].a2;
                line[j].b2=line[i].b2;
                cnt[i]++;
                cnt[j]++; // @@ Error: This incorrectly increments cnt[j] when merging, but the logic for merging is flawed. The program does not sort segments by x1, so merging may not follow the required increasing x order. Also, the merging updates both segments' endpoints in a way that can create incorrect connections and double-count segments. The reference program uses a sorted array and only updates the current segment (line[i]) while zeroing out the merged segment (line[j]), which is the correct approach.
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2;
                line[i].b2=line[j].b2;
                line[j].a1=line[i].a1;
                line[j].b1=line[i].b1;
                cnt[i]++;
                cnt[j]++; // @@ Error: Same issue as above; this incorrectly increments cnt[j] and the merging logic is flawed. Additionally, the program does not ensure that segments are processed in order of increasing x1, which is required for correct continuous line formation.
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