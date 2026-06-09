#include<stdio.h>
#include<stdlib.h>

#define MaxV    256
int del_num=2147483647;
typedef struct edge {
    int  adj;
    struct edge *next;
} Elink;

typedef struct ver {
    int node;
    Elink *link;
} Vlink;

Vlink  G[MaxV];
Vlink  G_after[MaxV];
//DFS
int  Visited[110]= {0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(Vlink  G[ ], int n) {
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(Vlink  G[ ], int v) {
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    int t=G[v].node;
    printf("%d ",t);//输出序列 // @@ 删除顶点后输出的是原编号，应输出新编号 v
    for(p = G[v].link; p !=NULL;  p=p->next) {
        int s;
        if(p->adj>del_num)
            s=p->adj-1;
        else
            s=p->adj;
        if( !Visited[s] ) {
            DFS(G, s);
        }
    }
}
//BFS
int  Visited_B[110]= {0}; //标识顶点是否被访问，N为顶点数
struct queue {
    Vlink element;
};
struct queue Q[110];
int head;
int tail;
int cnt;
int emptyQ() {
    if(cnt<=0)
        return 1;
    return 0;
}
void enQueue(Vlink G[],int v) {
    cnt++;
    tail++;
    Q[tail].element.node=G[v].node; // @@ 应存储新编号 v，而不是 G[v].node（原编号）
}
int deQueue(struct queue Q[]) {
    int k=Q[head].element.node;
    head++;
    cnt--;
    return k;
}
void  travelBFS(Vlink  G[ ], int n) {
    int i;
    head=0;
    tail=-1;
    cnt=0;
    for(i=0; i<n; i++) Visited_B[i] = 0 ;//初始化
    for(i=0; i<n; i++)
        if( !Visited_B[i] ) BFS(G, i);
    //    printf("BFS\n");
}
void BFS(Vlink  G[ ], int v) {
    Elink  *p;
    Visited_B[v] = 1; //标识某顶点已入队
    enQueue(G, v);
    while(!emptyQ()) {
        v = deQueue(Q);  //取出队头元素
        printf("%d ",v); //访问当前顶点
        for(p=G[v].link; p!=NULL; p=p->next ) {
            int l=p->adj;
            if(p->adj>del_num)
            l=p->adj-1;
            else
            l=p->adj;
            //访问该顶点的每个邻接顶点
            if( !Visited_B[l] ) {
                Visited_B[l] = 1; //标识某顶点入队
                enQueue(G, l);
            }
        }
    }
}


int main() {
    int num_node, num_edge;
    scanf("%d%d", &num_node, &num_edge);
    int i, v1, v2;
    for(int m=0; m<num_node; m++) {
        G[m].node=m;
    }//一定要记得啊！给G[m].node结点赋初值
    for(i = 0; i < num_edge; i++) {
        scanf("%d %d", &v1, &v2);
        // 为新的边申请内存
        Elink* p = (Elink*)malloc(sizeof(Elink));
        Elink* q = (Elink*)malloc(sizeof(Elink));
        p->adj = v2;
        p->next = NULL;
        q->adj = v1;
        q->next = NULL;
        // 把p插入v1
        if(G[v1].link == NULL) {
            G[v1].link = p;
        } else {
            Elink* t;
            t = G[v1].link;
            if(t->adj > v2) {
                p->next = t;
                G[v1].link = p;
            } else {
                while(t->next != NULL && t->next->adj < v2) {
                    t = t->next;
                }
                p->next = t->next;
                t->next = p;
            }
        }
        if(G[v2].link == NULL) {
            G[v2].link = q;
        } else {
            Elink* t;
            t = G[v2].link;
            if(t->adj > v1) {
                q->next = t;
                G[v2].link = q;
            } else {
                while(t->next != NULL && t->next->adj < v1) {
                    t = t->next;
                }
                q->next = t->next;
                t->next = q;
            }
        }
    }
    //输出深度和广度
    travelDFS(G,num_node);
    printf("\n");
    travelBFS(G,num_node);
        printf("\n");
//输入要删除的顶点：
    scanf("%d",&del_num);
    num_node--;
    for(int m=del_num; m<num_node; m++) {
        G[m]=G[m+1]; // @@ 移动顶点后，未更新 G[m].node = m，导致后续输出仍为原编号
    }

    Elink* now = (Elink*)malloc(sizeof(Elink));
    Elink* pre = (Elink*)malloc(sizeof(Elink));
    for(int m=0; m<num_node; m++) {
        now=G[m].link;
        pre=NULL;
        while(now!=NULL) {
            if(now->adj==del_num) {
                if(pre==NULL) {
                    G[m].link=now->next;
                } else {
                    pre->next=now->next;
                }
                free(now);
                break;
            }
            pre=now;
            now=now->next;
        }
    }
//    for(int m=0; m<num_node; m++) {
//        printf("%d %d\n",m,G[m].node);
//        Elink* cur = (Elink*)malloc(sizeof(Elink));
//        cur=G[m].link;
//        while(cur!=NULL) {
//            printf("vnode%d:%d\n",m,cur->adj);
//            cur=cur->next;
//        }
//    }
    //输出深度和广度
    travelDFS(G,num_node);
    printf("\n");
    travelBFS(G,num_node);
        printf("\n");
    return 0;
}