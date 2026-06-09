#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int G[500][500];
int visited[500]={0};
int a, b, del;
int quene[1000];

void DFS(int m){
    int j;
    visited[m] = 1;
    printf("%d ", m);
    for (j = 0; j < a; j++){
        if(visited[j]==0&&G[m][j]==1){
            DFS(j);
        }
    }
}
void BFS(int m2){
    int front=0, back=0;
    int w,k;
    quene[back++] = m2;
    while(front<=back){
         w = quene[front++];  
         if(!visited[w]){
            printf("%d ", w);
            visited[w] = 1;
            for (k = 0; k < a; k++){
                if (G[w][k]==1&&visited[k]==0){
                    quene[back++] = k;
                }
                
            }
        }    
    }    
}
int main(){
    int i;
    int start, end;
    scanf("%d%d", &a, &b);
    for (i = 0; i < b; i++){
        scanf("%d%d", &start, &end);
        G[start][end] = 1;
        G[end][start] = 1;
    }
    scanf("%d", &del);


    for(i=0; i<a; i++) 
        visited[i] = 0;
    for(i=0; i<a; i++){
        if(!visited[i])
            DFS(i);
    }
    printf("\n");
    for(i=0; i<a; i++) 
        visited[i] = 0;
    for(i=0; i<a; i++){
        if(!visited[i])
            BFS(i);
    }
    printf("\n");


    for (i = 0; i < a; i++){
        G[del][i] = 0;
        G[i][del] = 0;
    }

    for(i=0; i<a; i++) 
        visited[i] = 0;
    for(i=0; i<a&&i!=del; i++){
        if(!visited[i])
            DFS(i);
    }
    printf("\n");
    for(i=0; i<a; i++) 
        visited[i] = 0;
    for (i = 0; i < 500; i++){
        quene[i] = 0;
    }
    for (i = 0; i < a && i != del; i++){
        if (!visited[i])
            BFS(i);
    }
    printf("\n");

    return 0;
}
