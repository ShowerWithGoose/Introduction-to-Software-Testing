#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int Vertex[100][100];
int visited[100];
int deletedVet;
int VertexNum, EdgeNum;

int queue[100];
int fron = 0, rear = 99, cnt = 0;

int isEmpty(){
    return cnt == 0;
}

void enqueu(int id){
    rear = (rear + 1) % 100;
    queue[rear] = id;
    cnt++;
}

int dequeu(){
    int ret = queue[fron];
    cnt--;
    fron = (fron + 1) % 100;
    return ret;
}

void DFS(int v){
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i<VertexNum;  i++)
        if( Vertex[v][i] && !visited[i] )
            DFS(i);

    return;
}

void BFS(int v){
    visited[v] = 1;
    printf("%d ", v);
    enqueu(v);
    while(!isEmpty()){
        v = dequeu();
        for(int i = 0; i<VertexNum; i++){
            if( Vertex[v][i] && !visited[i] ){
                printf("%d ", i);
                enqueu(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    memset(visited, 0, 100);
    return;
}

int main(){
    scanf("%d%d", &VertexNum, &EdgeNum);

    for(int i = 0; i<EdgeNum; i++){
        int ver1, ver2;
        scanf("%d%d", &ver1, &ver2);
        Vertex[ver1][ver2] = Vertex[ver2][ver1] = 1;
    }
    scanf("%d", &deletedVet);
    DFS(0);
    printf("\n");
    memset(visited, 0, 100);
    BFS(0);

    for(int i = 0; i<VertexNum; i++){
        for(int j = 0; j<VertexNum; j++){
            if(i == deletedVet || j == deletedVet)
                Vertex[i][j] = 0;
        }
    }
    DFS(0);
    printf("\n");
    memset(visited, 0, 100);
    BFS(0);

    return 0;
}
