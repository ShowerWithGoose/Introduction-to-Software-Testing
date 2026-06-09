#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,v[100],e[100][100];
void dfs(int p){
    printf("%d ",p);
    int i;
    v[p]=1;
    for(i=0;i<n;i++){
        if(!v[i]&&e[p][i]==1){
            dfs(i);
        }
    }
}
void bfs(int p){
    int i,head=0,rear=0,queue[100]={p};
    v[p]=1;
    while(head<=rear){
        for(i=0;i<n;i++){
            if(v[i]==0&&e[i][queue[head]]==1){
                queue[++rear]=i;
                v[i]=1;
            }
        }
        printf("%d ",queue[head++]);
    }
}
int main(){
    int i,n1,v1,v2;
    scanf("%d%d",&n,&n1);
    for(i=0;i<n1;i++){
        scanf("%d%d",&v1,&v2);
        e[v1][v2]=e[v2][v1]=1;
    }
    scanf("%d",&v1);

    dfs(0);
    printf("\n");

    for(i=0;i<n;i++)
        v[i]=0;
    bfs(0);
    printf("\n");

    for(i=0;i<n;i++){
        e[v1][i]=0;
        e[i][v1]=0;
    }

    for(i=0;i<n;i++)
        v[i]=0;
    dfs(0);
    printf("\n");

    for(i=0;i<n;i++)
        v[i]=0;
    bfs(0);

    system("pause");
    return 0;
}


