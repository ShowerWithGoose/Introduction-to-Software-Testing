#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h> // @@ [Compilation Error: Non-standard header <malloc.h> may not exist on all systems (e.g., Linux). Use <stdlib.h> instead.]
int visit[100]={0},map[100][100];
void sdbl(int n,int p)
{
    int i;
    printf("%d ",p);
    visit[p]=1;
    for(i=0;i<n;i++)
    {
        if(map[p][i]==1&&visit[i]==0){
            sdbl(n,i);
        }
    }
}
void gdbl(int n,int p)
{
    int i,h=0,t=1,tmp,dui[n];
    // @@ [Potential Runtime Error: Queue size 'n' may cause out-of-bounds access when 't' becomes 'n' (indices 0..n-1). Should be 'dui[n+1]' or check bounds.]
    dui[h]=p;
    while(h<=t){
        tmp=dui[h++];
        if(visit[tmp]==1){
            continue;
        }
        else{
            printf("%d ",tmp);
            visit[tmp]=1;
            for(i=0;i<n;i++)
            {
                if(map[tmp][i]==1&&visit[i]==0){
                    dui[t++]=i;
                }
            }
        }
    }
}

int main()
{
    int n,e,a,b,d;
    scanf("%d %d",&n,&e);
    memset(visit,0,sizeof(visit));
    for(int i=0;i<e;i++)
    {
        scanf("%d %d",&a,&b);
        map[a][b]=map[b][a]=1;
    }
    sdbl(n,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    gdbl(n,0);
    printf("\n");
    scanf("%d",&d);
    for(int i=0;i<n;i++)
    {
        map[d][i]=map[i][d]=0;
    }
    memset(visit,0,sizeof(visit));
    sdbl(n,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    gdbl(n,0);
    printf("\n");

    return 0;
}