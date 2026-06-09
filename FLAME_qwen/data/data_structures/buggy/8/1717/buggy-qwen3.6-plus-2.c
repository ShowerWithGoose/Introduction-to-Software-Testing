#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
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
    int i,h=0,t=1,tmp,dui[n]; // @@ Variable Length Array (VLA) is not supported in C89/C90 standard, which causes compilation error. Use a fixed size like dui[100].
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
    for(int i=0;i<e;i++) // @@ Declaring loop variable inside for loop is a C99 feature, which may cause compilation error in strict C89 environments. Declare 'i' before the loop.
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
    for(int i=0;i<n;i++) // @@ Same as above, declaring loop variable inside for loop may cause compilation error in C89 standard.
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