//
//  main.c
//  图的遍历
//
//  Created by  on 2022/6/8.
//

#include <stdio.h>
#define INF 300000
int n=0,m=0;
int visited[103]={0};
int queue[103]={0};
int a[103][103]={{0}};

void reset1(){
    for(int i=0;i<103;i++)
        visited[i]=0;
}
void reset2(){
    for(int i=0;i<103;i++)
        queue[i]=INF;
}
void dfs(int d){
    visited[d]=1;
    printf("%d ",d);
    for(int i=0;i<n;i++)
        if(a[d][i]==1 &&visited[i]==0){
            dfs(i);
        }
    return;
}
void bfs(int b){
    visited[b]=1;
    int top=1;
    int bot=0;
    queue[0]=b;
    printf("%d ",b);
    while(top!=bot){
        int d=queue[bot];
        bot++;
        for(int i=0;i<n;i++){
            if(a[d][i]==1 && visited[i]==0){
                visited[i]++;
                printf("%d ",i);
                queue[top++]=i;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int c1=0,c2=0;
        scanf("%d %d",&c1,&c2);
        a[c1][c2]=1;
        a[c2][c1]=1;
    }
    int delete=0;
    scanf("%d",&delete);
    dfs(0);
    printf("\n");
    reset1();
    bfs(0);
    printf("\n");
    reset1();
    reset2();
    for(int i=0;i<n;i++){
        a[delete][i]=0;
        a[i][delete]=0;
    }
    dfs(0);
    printf("\n");
    reset1();
    bfs(0);
    printf("\n");
    reset1();
    reset2();
    return 0;
}



