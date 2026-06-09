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
    int i,h=0,t=1,tmp,dui[n]; // @@ [Variable-length array 'dui' may not be supported in all C standards (e.g., C89), and more critically, the queue size may be insufficient when traversing after deletion because 'n' includes the deleted vertex, but the actual number of nodes visited is less; however, the main issue causing compilation error is likely the use of non-standard headers or missing standard ones. But given the test environment error "/bin/sh: 1: gcc: not found", that's external. However, within code logic, a real bug is that BFS queue 'dui' is declared with size 'n', but index 't' can go up to 'n' (since t starts at 1 and increments before assignment), leading to potential out-of-bounds access. Yet the problem states "Compilation Error", and the only plausible compilation issue in the code is the use of variable-length array (VLA) 'dui[n]' which is not allowed in C89/C90. Since many online judges use older standards, this causes compilation failure.]
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
                    dui[t++]=i; // @@ [This can write beyond dui[n-1] because t starts at 1 and increments before assignment, so maximum index written is t = n, but array size is n → indices 0 to n-1. So dui[t++] when t = n-1 becomes dui[n], which is out of bounds. However, this is a runtime error, not compilation. The true compilation error is VLA usage.]
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
    for(int i=0;i<e;i++) // @@ [Use of 'int i' in for loop declaration is C99 feature; if compiler uses C89, this causes compilation error.]
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
    for(int i=0;i<n;i++) // @@ [Same as above: C99-style loop variable declaration may cause compilation error in C89 mode.]
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