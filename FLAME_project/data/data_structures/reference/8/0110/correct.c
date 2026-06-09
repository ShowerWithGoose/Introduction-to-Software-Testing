#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SCALE 125
#define INFINITE 150

typedef struct GraphVertex{
    int vertex;
    struct GraphVertex *link;
}Vnode,*ver;

void DFS(ver vertex[][2],int visited[],int v);
void BFS(ver vertex[][2],int visited[],int v);
int Search_NextNode(ver vertex[][2],int visited[],int v);
void Delete_GraphNode(ver vertex[][2],int v,int n);

int main(){
    int v,e,node;
    int visited[SCALE] = {0};
    ver vertex[SCALE][2]; //邻接表保存无向图，对于每个vertex[i]链表，保存头结点和尾结点
    
    scanf("%d%d",&v,&e);

    for (int i = 0 ; i < v ; i++) //邻接表的初始化
    {
        vertex[i][0] = (ver)malloc(sizeof(Vnode));
        vertex[i][0]->vertex = i;
        vertex[i][0]->link = NULL;
        vertex[i][1] = vertex[i][0];
    }

    for (int i = 0 ; i < e ; i++) //建立无向图邻接表
    {
        int begin,end;
        scanf("%d%d",&begin,&end);
        ver p = (ver)malloc(sizeof(Vnode));
        p->vertex = end;
        p->link = NULL;
        vertex[begin][1]->link = p;
        vertex[begin][1] = p;
        p = (ver)malloc(sizeof(Vnode));
        p->vertex = begin;
        p->link = NULL;
        vertex[end][1]->link = p;
        vertex[end][1] = p;
    }

    DFS(vertex,visited,0);
    printf("\n");
    for (int i = 0 ; i < v ; i++)
        visited[i] = 0;
    BFS(vertex,visited,0);
    printf("\n");

    scanf("%d",&node);
    for (int i = 0 ; i < v ; i++)
        visited[i] = 0;
    Delete_GraphNode(vertex,node,v);
    DFS(vertex,visited,0);
    printf("\n");
    for (int i = 0 ; i < v ; i++)
        visited[i] = 0;
    BFS(vertex,visited,0);

    return 0;
}

int Search_NextNode(ver vertex[][2],int visited[],int v){
    int min = INFINITE;
    ver p = vertex[v][0];
    while (p->link != NULL)
    {
        p = p->link;
        int w = p->vertex;
        if (visited[w] == 0 && w < min) min = w;
    }
    return min;
}

void DFS(ver vertex[][2],int visited[],int v){
    printf("%d ",v);
    visited[v] = 1;
    int w = Search_NextNode(vertex,visited,v);
    while (w != INFINITE){
        DFS(vertex,visited,w);
        w = Search_NextNode(vertex,visited,v);
    }
    return;
}

void BFS(ver vertex[][2],int visited[],int v){
    int queue[SCALE],head = 0,rear = 0;
    queue[rear++] = v;
    while (head < rear)
    {
        int w = queue[head++];
        printf("%d ",w);
        visited[w] = 1;
        while (1)
        {
            int p = Search_NextNode(vertex,visited,w);
            if (p == INFINITE) break;
            visited[p] = 1;
            queue[rear++] = p;
        }
    }
    return;
}

void Delete_GraphNode(ver vertex[][2],int v,int n){
    ver temp = vertex[v][0];
    while (temp != NULL)
    {
        ver p = temp;
        temp = temp->link;
        free(p);
    }
    for (int i = 0 ; i < n ; i++)
    {
        if (i == v) continue;
        temp = vertex[i][0];
        while (temp->link != NULL)
        {
            ver p = temp;
            temp = temp->link;
            if (temp->vertex == v)
            {
                p->link = temp->link;
                ver r = temp;
                temp = p;
                free(r);
            }
        }
    }
    return;
}


