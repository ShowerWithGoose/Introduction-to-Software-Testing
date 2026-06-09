#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Node {
    int data;
    struct _Node *next;
}
*List;
List GList[105];
int Nv,Ne;
int visited[105];
void Insert(List L,int x);
void CreateGraph(void);
void Destroy(List L);
void Delete(List L,int x);
void DeleteVertex(void);
void DFS(List GL);
void BFS(List GL);
int main()
{
    CreateGraph();
    memset(visited,0,sizeof(visited));
    DFS(GList[0]);
    puts("");
    memset(visited,0,sizeof(visited));
    BFS(GList[0]);
    puts("");
    DeleteVertex();
    memset(visited,0,sizeof(visited));
    DFS(GList[0]);
    puts("");
    memset(visited,0,sizeof(visited));
    BFS(GList[0]);
    puts("");
    return 0;
}
void Insert(List L,int x) {
    List p = L,q;
    while(p->next && p->next->data < x)
    p = p->next;
    q = (List)malloc(sizeof(struct _Node));
    q->data = x;
    q->next = p->next;
    p->next = q;
    return;
}
void CreateGraph(void) {
    scanf("%d",&Nv);
    for(int iv = 0;iv < Nv;iv++) {
        GList[iv] = (List)malloc(sizeof(struct _Node));
        GList[iv]->data = iv;
        GList[iv]->next = NULL;
    }
    scanf("%d",&Ne);
    if(Ne) {
        int v1,v2;
        for(int ie = 0;ie < Ne;ie++) {
            scanf("%d %d",&v1,&v2);
            Insert(GList[v1],v2);
            Insert(GList[v2],v1);
        }
    }
    return;
}
void Destroy(List L) {
    List p = L,q;
    while(p->next) {
        q = p;
        p = p->next;
        free(q);
    }
    free(p);
    return;
}
void Delete(List L,int x) {
    if(L->next) {
        List p = L;
        while(p->next && p->next->data != x)
        p = p->next;
        if(p->next) {
            List r = p->next;
            p->next = p->next->next;
            free(r);
        }
    }
    return;
}
void DeleteVertex(void) {
    int tar;
    scanf("%d",&tar);
    Destroy(GList[tar]);
    for(int iv = 0;iv < Nv;iv++)
    if(iv != tar)
    Delete(GList[iv],tar);
    return;
}
void DFS(List GL) {
    printf("%d ",GL->data);
    visited[GL->data] = 1;
    List p;
    for(p = GL;p;p = p->next)
    if(!visited[p->data])
    DFS(GList[p->data]);
}
void BFS(List GL) {
    List queue[105],v;
    int front = 0,rear = -1;
    if(GL) {
        List p;
        visited[GL->data] = 1;
        queue[++rear] = GL;
        while(rear - front != -1) {
            v = queue[front++];
            printf("%d ",v->data);
            for(p = v;p;p = p->next) {
                if(!visited[p->data]) {
                    queue[++rear] = GList[p->data];
                    visited[p->data] = 1;
                }
            }
        }
    }
}

