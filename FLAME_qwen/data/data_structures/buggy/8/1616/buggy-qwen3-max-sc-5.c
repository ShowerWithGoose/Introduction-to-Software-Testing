#include<stdio.h>
#include<stdlib.h>
#define MAXVER 100

typedef struct edge {
    int adjvex;
    struct edge *link;
} Elink;
typedef struct ver {
    Elink *link;
} Vlink;


Vlink graph[MAXVER];
int ver_num, edge_num;//顶点数，边数
int visited[MAXVER] = {0};


//构造图
void Build_Graph(int vertex, int adjvex) {    
    Elink *p, *q;
    p = (Elink *)malloc(sizeof(Elink));
    p->adjvex = adjvex;
    p->link = NULL;
    if (graph[vertex].link == NULL) {
        graph[vertex].link = p;
    } else {
        Elink *head = graph[vertex].link;
        //相邻顶点按从小到大顺序排列
        //这里找到合适位置把p插在q后
        if (head->adjvex > adjvex) {
            p->link = head; // @@ [Incorrect insertion: should set p->link = head, and update graph[vertex].link = p]
            graph[vertex].link = p;
        } else {
            for (q = head; q->link != NULL && q->link->adjvex < adjvex; q = q->link);
            p->link = q->link;
            q->link = p;
        }
    }
}

//对数组初始化
void visitedInit() {
    for (int i = 0; i < ver_num; i++) {
        visited[i] = 0;
    }
}
//访问某个顶点
void visit(int t) {
    printf("%d ", t);
}

//深度优先遍历
void DFS(int vertex) {
    visit(vertex);
    visited[vertex] = 1;
    Elink *p = graph[vertex].link;
    for (; p != NULL; p = p->link) {
        if (visited[p->adjvex] == 0) {
            DFS(p->adjvex);
        }
    }
}
void Deepfirst() {
    for (int i = 0; i < ver_num; i++) {
        if (visited[i] == 0) {
            DFS(i);
        }
    }
    printf("\n");
}

//广度优先遍历
void BFS(int vertex) {
    int queue[MAXVER];
    int front = -1;
    int rear = 0;
    queue[0] = vertex;
    visit(vertex);
    visited[vertex] = 1;
    while (front < rear) {
        Elink *p = graph[queue[++front]].link;
        for (; p != NULL; p = p->link) {
            if (visited[p->adjvex] == 0) {
                visit(p->adjvex);
                visited[p->adjvex] = 1;
                queue[++rear] = p->adjvex;
            }
        }
    }
}
void Breathfirst() {
    for (int i = 0; i < ver_num; i++) {
        if (visited[i] == 0) {
            BFS(i);
        }
    }
    printf("\n");
}


int main() {
    int v1, v2;
    int target;
    scanf("%d%d", &ver_num, &edge_num);
    for (int i = 0; i < ver_num; i++) {
        graph[i].link = NULL;
    }
    for (int i = 0; i < edge_num; i++) {
        scanf("%d%d", &v1, &v2);
        printf("%d%d\n",v1,v2); // @@ [Unnecessary debug print causing wrong output format]
        Build_Graph(v1, v2);
        Build_Graph(v2, v1);
    }
    scanf("%d", &target);

    visitedInit();
    Deepfirst();
    visitedInit();
    Breathfirst();

    //只需把要删除的结点标记为visited即可
    visitedInit();
    visited[target] = 1;
    Deepfirst();
    visitedInit();
    visited[target] = 1;
    Breathfirst();

    return 0;
}