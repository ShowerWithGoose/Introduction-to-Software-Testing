#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000000
#define ll long long

// 定义元素的类型
typedef int ElementType; 

int n,e;

int graph[300][300],visited[300]={0},que[300];

void travelDFS(int k){
    printf("%d ",k);
    visited[k]=1;
    int i;
    for(i=0;i<n;i++){
        if(graph[k][i]&&!visited[i]){
            travelDFS(i);
        }
    }
}

void travelBFS(int k){
    
    int i,front=0,rear=0,temp;
    que[rear++]=k;
    while(front<=rear){
        temp=que[front++];
        if(!visited[temp]){
            printf("%d ",temp);
            visited[temp]=1;
            for(i=0;i<n;i++){
                if(graph[temp][i]&&!visited[i])
                    que[rear++]=i;
            }
        }
    }


}

int main() {
    
    int v1,v2,i,j,k;
    scanf("%d %d",&n,&e);
    for(i=0;i<e;i++){
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=graph[v2][v1]=1;
    }
    scanf("%d",&e);

    travelDFS(0);
    printf("\n");

    for(i=0;i<n;i++){
        visited[i]=0;
    }
    travelBFS(0);
    printf("\n");

    for(i=0;i<n;i++){
        visited[i]=0;
    }
    visited[e]=1;
    travelDFS(0);
    printf("\n");

    for(i=0;i<300;i++){
        que[i]=0;
    }
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    visited[e]=1;
    travelBFS(0);
    


    
    
	return 0;
}

