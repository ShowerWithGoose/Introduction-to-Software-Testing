//
//  main.c
//  DS7-1
//
//  Created by  on 2022/6/11.
//
// 邻接表
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visited[103]={0};

struct edge{ //边表结点
    int adjvex;
    struct edge *next;
};
struct ver{  //顶点
    int vertex;
    struct edge *link;
};
struct ver G[103];  //顶点数组

int Q[103];
int front=0,rear=-1;
void enQueue(struct ver G[],int v){  //进队
    rear++;
    Q[rear]=G[v].vertex;
}
int JudgeQueue(int Q[]){  //判断队是否为空
    if(front <= rear)
        return 1;
    else
        return 0;
}
int deQueue(int Q[]){  //出队
    int x=0;
    if(JudgeQueue(Q)==1){
        x=Q[front];
        Q[front]=0;
        front++;
    }
    return x;
}

void VI(struct ver G[],int v){  //打印经过的结点
    printf("%d ",G[v].vertex);
}

void Delete(int c){
    if(c>=0){
        visited[c]=1;
    }
}

void DFS(struct ver G[], int v){   //深度遍历递归
    struct edge *p;
    visited[v]=1;
    VI(G,v);
    for(p=G[v].link;p!=NULL;p=p->next){
        if(!visited[p->adjvex]){
            DFS(G,p->adjvex);
        }
    }
}
void travelDFS(struct ver G[], int n ,int c){   //深度遍历函数
    int i=0;
    for(i=0;i<n;i++)
        visited[i]=0; //置0
    Delete(c);
    for(i=0;i<n;i++){
        if(!visited[i])
            DFS(G,i);
    }
}

void BFS(struct ver G[], int v){  //广度优先遍历递归
    struct edge *p;
    VI(G,v);
    visited[v]=1;
    enQueue(G,v);
    while(JudgeQueue(Q)==1){
        v=deQueue(Q);
        //p=G[v].link;
        for(p=G[v].link;p!=NULL;p=p->next){
            if(!visited[p->adjvex]){
                VI(G,p->adjvex);
                visited[p->adjvex]=1;
                enQueue(G,p->adjvex);
            }
        }
    }
}
void travelBFS(struct ver G[], int n ,int c){   //广度优先遍历函数
    int i=0;
    for(i=0;i<n;i++){
        visited[i]=0;  //置0
    }
    Delete(c);
    for(i=0;i<n;i++){
        if(!visited[i])
            BFS(G,i);
        
    }
}

void BubbleSort(struct ver *H){
    int i=0,j=0;
    int n=0;
    struct edge *sort[103];
    struct edge *e;
    struct edge hold;
    e=H->link;
    while(e!=NULL){
        sort[i]=e;
        e=e->next;
        i++;
    }
    n=i;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(sort[j]->adjvex > sort[j+1]->adjvex){ //[bug] 和j+1比较
                hold.adjvex = sort[j]->adjvex;
                sort[j]->adjvex= sort[j+1]->adjvex;
                sort[j+1]->adjvex = hold.adjvex;
            }
        }
    }
    H->link=sort[0];
    e=H->link;
    for(i=1;i<n;i++){
        e->next=sort[i];
        e=e->next;
        e->next=NULL;
    }
}

int main() {
    int num_vertex=0,num_edge=0;
    int i=0;
    int a,b;
    int c;
    struct edge *e; //[careful] e是指针哦，记得加*
    
    scanf("%d%d",&num_vertex,&num_edge);
    for(i=0;i<num_vertex;i++){
        G[i].vertex=i;
        G[i].link=NULL;  //[carefully]
    }
    for(i=0;i<num_edge;i++){
        scanf("%d%d",&a,&b);
        e=(struct edge*)malloc(sizeof(struct edge));
        e->adjvex=b;
        e->next=G[a].link;  //头插法
        G[a].link=e;
        e=(struct edge*)malloc(sizeof(struct edge));
        e->adjvex=a;
        e->next=G[b].link;
        G[b].link=e;
    }
    scanf("%d",&c);
    for(i=0;i<num_vertex;i++){
        BubbleSort(&G[i]);
    }
//    for(i=0;i<num_vertex;i++){  //检查图的构造是否正确
//        printf("%d:",G[i].vertex);
//        e=G[i].link;
//        printf("%d ",e->adjvex);
//        while(e->next!=NULL){
//            e=e->next;
//            printf("%d ",e->adjvex);
//        }
//        printf("\n");
//    }
    
    travelDFS(G, num_vertex,-1);
    printf("\n");
    travelBFS(G, num_vertex,-1);
    printf("\n");
    travelDFS(G, num_vertex,c);
    printf("\n");
    travelBFS(G, num_vertex,c);
    printf("\n");
    
    return 0;
}

//删除给定顶点 /前/后 按深度优先遍历 及 广度优先遍历方式 遍历的图顶点序列
//输入时顶点编号用整数0～n-1表示
//无论何种遍历，都是从编号为0的顶点开始遍历
//访问相邻顶点时按照编号从小到大的顺序访问


