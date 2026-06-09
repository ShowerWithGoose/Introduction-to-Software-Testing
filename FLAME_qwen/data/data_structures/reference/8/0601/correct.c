#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int graph[1000][1000];
int n;
int temp[1000];

void DFS(int a){
    temp[0] = 1;
    for(int i = 0;i < n;i ++){
        if(graph[a][i] == 1 && temp[i] == 0){
            printf("%d ",i);
            temp[i] = 1;
            DFS(i);
        }
    }
}
void BFS(int a){
    temp[0] = 1;
    int temp2[1000];
    memset(temp2,0,sizeof(temp2));
    int tempFore = 0;
    int tempBack = 0;
    while(1){
        for(int i = 0;i < n;i ++){
            if(graph[a][i] == 1 && temp[i] == 0){
                printf("%d ",i);
                temp[i] = 1;
                temp2[tempBack ++] = i;
            }
        }
        if(tempFore == tempBack){
            break;
        }
        a = temp2[tempFore ++];
    }
}
void delete(int x){
    for(int i = 0;i < n;i ++){
        if(graph[x][i] == 1){
            graph[x][i] = graph[i][x] = 0;
        }
    }
}

int main(){

    int a,x,a1,a2;
    scanf("%d%d",&n,&a);
    for(int q = 0;q < a;q ++){
        scanf("%d%d",&a1,&a2);
        graph[a1][a2] = graph[a2][a1] = 1;
    }
    printf("0 ");
    memset(temp,0,sizeof(temp));
    DFS(0);
    puts("");
    printf("0 ");
    memset(temp,0,sizeof(temp));
    BFS(0);
    puts("");
    scanf("%d",&x);
    delete(x);
    printf("0 ");
    memset(temp,0,sizeof(temp));
    DFS(0);
    puts("");
    printf("0 ");
    memset(temp,0,sizeof(temp));
    BFS(0);
    puts("");
}
