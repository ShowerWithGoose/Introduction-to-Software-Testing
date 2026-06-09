#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_VER 1000
#define MAX_QUEUESIZE 500

typedef struct _SqQueue
{
    int ver[MAX_QUEUESIZE];
    int front;
    int rear;
    int count;
}SqQueue;

void InitialSqQueue(SqQueue* queue){
    (*queue).front = 0;
    (*queue).rear = -1;
    (*queue).count = 0;
}

int EmptySqQueue(SqQueue queue){
    return queue.count == 0;
}

void EnSqQueue(SqQueue* QueuePtr, int i){
    QueuePtr->count ++; 
    QueuePtr->ver[++QueuePtr->rear] = i;
    return;
}

int DeSqQueue(SqQueue* QueuePtr){
    if (QueuePtr->count == 0){
        return -1;
    }   
    int i = QueuePtr->ver[QueuePtr->front];
    QueuePtr->count --;
    QueuePtr->front ++;
    return i;
}

int de_note;
int flag = 0;
SqQueue queue;

typedef struct _Edge{
    int adj;
    struct _Edge* elink; 
}Edge;

typedef struct _Ver
{
    Edge* vlink;
}Ver;
Ver AdjList[MAX_VER];

void InitAdjList(Ver verlist[], int ver_num){
    for (int i = 0; i < ver_num; i++)
    {
        verlist[i].vlink = NULL;
    }
}

void InsertEdge(int ver1, int ver2){
    Edge* r = AdjList[ver1].vlink;
    Edge* p;
    p = (Edge*)malloc(sizeof(Edge));
    p->adj = ver2;
    if(r == NULL){
        AdjList[ver1].vlink = p;
        p->elink = NULL;
        return;
    }
    while (r->elink != NULL && r->elink->adj < ver2){
        r = r->elink;
    } 
    p->elink = r->elink;
    r->elink = p;
}

//名称：创建邻接表-按节点id顺序
void CreateGraph_Seq_id(Ver verlist[], int ver_num, int edge_num){
    int temp1, temp2, flag = 0;
    InitAdjList(verlist, ver_num);
    for (int i = 0; i < edge_num; i++){
        scanf("%d", &temp1);
        scanf("%d", &temp2);
        printf("%d %d\n", temp1, temp2); // @@ [Unnecessary debug print causing output mismatch]
        InsertEdge(temp1, temp2);
        InsertEdge(temp2, temp1);
    }
    scanf("%d", &temp1);
    de_note = temp1;
}

//名称：深度有限遍历图
//参数：点数组，点个数
int visited[MAX_VER];
void init_visited(int vernum){
    for (int i = 0; i < vernum; i++){
        visited[i] = 0;
    }
}
void VISIT(int i){
    if(flag == 0) printf("%d ", i);
    else if(i != de_note) printf("%d ", i);
}
void dfs(Ver verlist[], int i){
    visited[i] = 1;
    VISIT(i);
    for (Edge* r = verlist[i].vlink; r != NULL; r = r->elink){
        if(visited[r->adj] == 0){
            visited[r->adj] = 1; // @@ [Marking visited before recursive call is correct, but traversal order may be affected by insertion logic]
            dfs(verlist, r->adj);
        }
    }
}
void GraphDFS(Ver verlist[], int vernum){
    init_visited(vernum);
    for(int i = 0; i < vernum; i++){
        if(visited[i] == 0){
            dfs(verlist, i);
        }
    }
}

//名称：广度优先搜索
//参数：点数组，点个数
void BFS(Ver verlist[], int i){
    visited[i] = 1;
    VISIT(i);
    EnSqQueue(&queue, i);
    while (!EmptySqQueue(queue)){
        int k = DeSqQueue(&queue);
        for (Edge* r = verlist[k].vlink; r != NULL; r = r->elink){
            if(visited[r->adj] == 0){
                visited[r->adj] = 1;
                VISIT(r->adj);
                EnSqQueue(&queue, r->adj);
            }
        }
    }
}
void GraphBFS(Ver verlist[], int ver_num){
    init_visited(ver_num);
    for (int i = 0; i < ver_num; i++){
        if(visited[i] == 0){
            BFS(verlist, i);
        }
    }
}

void De_Graph(int ver, int ver_num){
    flag = 1;
    AdjList[ver].vlink = NULL;
    Edge* r, * p;
    for(int i; i < ver_num; i++){ // @@ [Variable 'i' is uninitialized, leading to undefined behavior]
        if(i == ver){
            i++;
            if(i == ver_num){
                break;
            }
        }
        p = AdjList[i].vlink;
        if(p == NULL) continue; // @@ [Missing null check before accessing p->elink]
        if(p->adj == ver){ // @@ [Missing handling when the first edge is the one to delete]
            AdjList[i].vlink = p->elink;
            free(p);
            continue;
        }
        r = p->elink;
        for (; r != NULL; r = r->elink, p = p->elink){
            if(r->adj == ver){
                p->elink = r->elink;
                free(r); // @@ [Memory leak: deleted node not freed]
                break;
            }
        }
    }
}

int main()
{
    int ver_num, edge_num;
    InitialSqQueue(&queue);

    scanf("%d%d", &ver_num, &edge_num);
    printf("%d %d\n", ver_num, edge_num); // @@ [Unnecessary debug print causing output mismatch]
    CreateGraph_Seq_id(AdjList, ver_num, edge_num);
    GraphDFS(AdjList, ver_num);
    printf("\n");
    GraphBFS(AdjList, ver_num);
    De_Graph(de_note, ver_num);
    printf("\n");
    GraphDFS(AdjList, ver_num);
    printf("\n");
    GraphBFS(AdjList, ver_num);
    return 0;
}