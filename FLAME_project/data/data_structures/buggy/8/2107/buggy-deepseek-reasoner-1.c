#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int Graph[105][105]={0};
int Visitedd[105]={0};
int Visited[105]={0};
int queue[200]={0};int front=0;int count=0;int fear=-1;int n;
void DFS(int Graph[][105],int v);
void BFS(int Graph[][105],int v);
int main(){
    int i,j,m,a,b,x;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        Graph[a][b]=Graph[b][a]=1;
    }
    scanf("%d",&x); // @@ vertex x is read but not used to perform deletion and output after-deletion sequences
    for(i=0;i<n;i++){
        if(!Visited[i])DFS(Graph,i);
    }
    printf("\n");
    
    for(i=0;i<n;i++){
        if(!Visitedd[i])BFS(Graph,i);
    }
    printf("\n");
    return 0; // @@ missing code to handle deletion (mark vertex x as visited and repeat DFS/BFS)
}
void DFS(int Graph[][105],int v){
    Visited[v]=1;
    printf("%d ",&v); // @@ prints address of v instead of its value
    int k;
    for(k=0;k<n;k++){
        if((!Visited[k])&&Graph[v][k]==1){
        
            DFS(Graph,k);
        }
    }
}
void BFS(int Graph[][105],int v){
    Visitedd[v]=1;
    fear=(fear+1)%200;
    queue[fear]=v;count++;
    while(count!=0){
        v=queue[front];
        count--;front=(front+1)%200;
        printf("%d ",&v); // @@ prints address of v instead of its value
        int k;
        for(k=0;k<n;k++){
            if((!Visitedd[k])&&Graph[v][k]==1){
                Visitedd[k]=1;
                fear=(fear+1)%200;
                queue[fear]=k;count++;
            }
        }
    }
}