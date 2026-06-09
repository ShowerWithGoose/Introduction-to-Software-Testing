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
                line[i].a1=line[j].a1; // @@ [Incorrect update: overwrites i's start with j's start, corrupting data.]
                line[i].b1=line[j].b1; // @@ [Likewise incorrect.]
                line[j].a2=line[i].a2; // @@ [Incorrect: sets j's end to i's end, causing duplicate information.]
                line[j].b2=line[i].b2; // @@ [Likewise incorrect.]
                cnt[i]++; // @@ [Incorrect count update: should add cnt[j] and set cnt[j]=0.]
                cnt[j]++; // @@ [Incorrect count update: double counting and not resetting.]
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2; // @@ [Incorrect update: overwrites i's end with j's end.]
                line[i].b2=line[j].b2; // @@ [Likewise incorrect.]
                line[j].a1=line[i].a1; // @@ [Incorrect: sets j's start to i's start.]
                line[j].b1=line[i].b1; // @@ [Likewise incorrect.]
                cnt[i]++; // @@ [Incorrect: same count issue.]
                cnt[j]++; // @@ [Incorrect: same count issue.]
            }
             
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(cnt[i]>flag) // @@ [Missing handling for max count = 1; should be >= or initialize minx,miny.]
        {
            flag=cnt[i];
            minx=line[i].a1;
            miny=line[i].b1;
        }
    }
    printf("%d %d %d\n",flag,minx,miny);
    return 0;
}