#include <stdio.h>
#include <string.h>

#define MAX 100005
int map[MAX][MAX];//邻接矩阵
int visited[MAX];//标记是否访问过
int deleted[MAX];//标记是否删除
int n,m,x,y,d;//n个顶点，m条边

void set0(){
    memset(visited,0,sizeof(visited));
}
void dfs(int x){
    printf("%d ",x);
    visited[x]=1;
    int i;
    for( i = 0;i<n;i++){
        if(visited[i]==1||map[x][i]==0||deleted[i]==1)
          continue;  //检查是否访问过、不是邻接点或者删除过
        dfs(i);
    }
}
int q[MAX],head,tail;
void clear(){
    head=1;
    tail=0;
}//清空队列
void pop(){
    ++head;//（队首）出队
}
void push(int x){
    q[++tail]=x;//（队尾）入队
}
int length(){
    return tail-head+1;
}
void bfs(int x){
    clear();
    push(x);
    printf("%d ",x);
    visited[x]=1;
    int i;
    while(length()){
        int x = q[head];
        pop();
        for( i = 0;i<n;i++){
            if(visited[i]==1||map[x][i]==0||deleted[i]==1)
                continue;  //检查是否访问过、不是邻接点或者删除过
        
            visited[i]=1;
            printf("%d ",i);
            push(i);//新节点入队
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        map[x][y]=map[y][x]=1;
    }
    dfs(0);
    puts("");
    set0(); // @@ [set0() is called after dfs(0), but visited array was already modified by dfs(0); however, the real issue is that set0() is defined to reset 'visited', but it's called AFTER the first dfs output and BEFORE bfs — this is correct logically. The actual error is elsewhere.]
    bfs(0);
    puts("");
    scanf("%d",&d);//要删除的节点
    deleted[d]=1;
    set0();
    dfs(0);
    puts("");
    set0();
    bfs(0);
    puts("");
}