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
                cnt[j]++; // @@ [This double-counting causes incorrect segment counts; when merging segments, both segments' counts are incremented, leading to overcounting. Also, modifying both line[i] and line[j] corrupts the data structure for future iterations.]
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2;
                line[i].b2=line[j].b2;
                line[j].a1=line[i].a1;
                line[j].b1=line[i].b1;
                cnt[i]++;
                cnt[j]++; // @@ [Same issue as above: double increment and bidirectional modification of segments leads to incorrect counting and corrupted segment data.]
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