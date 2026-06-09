#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int w[200][200],ved[200]={0},q[200],dot,s;
void DFS(int a){
    int x=0;
    printf("%d ",a);
    ved[a]++;
    x=0;
    while(x<dot)
    {
        if(w[a][x]&&!ved[x])
        DFS(x);
        x++;
    }
}
void BFS(int a){
    int x=0;
    int head=0,tail=1,t;
    q[head]=a;
    while(head<=tail){
        t=q[head];
        head++;
        if(ved[t]) continue;
        else{
            printf("%d ",t);
            ved[t]++;
            x=0;
            while(x<dot)
            {
                if(w[t][x]&&!ved[x])
                q[tail++]=x;
                x++;
            }
        }
    }
}
int main()
{
    scanf("%d %d",&dot,&s);
    int a,b,i=0,l;
    while(i<s)
    {
        scanf("%d %d",&a,&b);
        w[a][b]=1;w[b][a]=1;
        i++;
    }
    DFS(0);putchar('\n');
    memset(ved,0,sizeof(ved));
    BFS(0);putchar('\n');
    scanf("%d",&l);
    memset(ved,0,sizeof(ved));
    ved[l]=1;
    DFS(0);putchar('\n');
    memset(ved,0,sizeof(ved));memset(q,0,sizeof(q));
    ved[l]=1;
    BFS(0);putchar('\n');
return 0;
}
