#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
int n,m,form[105][105],footprint[105],team[105];
void dfs(int b);
void bfs();
int main(){
    int a,b,i,d;//n点 m边
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        form[a][b]=1,form[b][a]=1;
    }//form实际上是n*n的
    scanf("%d",&d);
    dfs(0),printf("\n");
    for(i=0;i<n;i++) footprint[i]=0;
    bfs(),printf("\n");
    for(i=0;i<n;i++){
        form[d][i]=0,form[i][d]=0;//删除
    }
    for(i=0;i<n;i++) footprint[i]=0;
    footprint[d]=1; 
    dfs(0),printf("\n");
    for(i=0;i<n;i++) footprint[i]=0;
    footprint[d]=1; 
    bfs(),printf("\n");
    return 0;
}
void dfs(int b){//b为开始节点
    int i,flag=0;
    if(footprint[b]==0)printf("%d ",b),footprint[b]=1;
    for(i=0;i<n;i++){
        if(form[b][i]==1&&footprint[i]==0){
            flag=1;
            dfs(i);
        }
    }
}
void bfs(){
    int head=0,tail=-1,i;
    tail++,team[tail]=0;
    while(tail>=head){
        if(footprint[team[head]]==0){
            printf("%d ",team[head]);
            footprint[team[head]]=1;
        }
        for(i=0;i<n;i++){
            if(form[head][i]==1){ // @@ [In BFS, 'head' is an index into the queue 'team', not the vertex itself. It should be 'form[team[head]][i]' to check adjacency of the current vertex.]
                tail++;
                team[tail]=i;
            }
        }
        head++;
    }
}