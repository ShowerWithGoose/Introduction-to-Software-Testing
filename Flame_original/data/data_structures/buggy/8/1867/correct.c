#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *link;
}node;
node *tu[100];
void insert(int a,int b);
void travelDFS(int visited[],int n,int d);
void travelBFS(int visited[],int n,int d);
void BFS(int visited[],int i);
void DFS(int visited[],int i);
int dfs[100];
int nd=0;
int bfs[100];
int nb=0;
int Q[100];
int front=0,rear=-1;
void enqueue(int i);
int dequeue();
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
    }
    scanf("%d",&d);
    for(int i=0;i<n;i++){
        tu[i]=(node *)malloc(sizeof(node));
        tu[i]->data=i;
        tu[i]->link=NULL;
    }
    for(int i=0;i<m;i++){
        insert(bian[i][0],bian[i][1]);
        insert(bian[i][1],bian[i][0]);
    }//链表构建完成
    travelDFS(visited,n,0);
    for(int i=0;i<nd;i++){
        printf("%d ",dfs[i]);
    }
    printf("\n");//输出深度遍历序列
    travelBFS(visited,n,0);
    for(int i=0;i<nb;i++){
        printf("%d ",bfs[i]);
    }
    printf("\n");//输出广度遍历序列
    nd=0;
    nb=0;
    rear=-1;
    front=0;//重置变量
    travelDFS(visited,n,d);
    for(int i=0;i<nd;i++){
        printf("%d ",dfs[i]);
    }
    printf("\n");//输出删除后深度遍历序列
    travelBFS(visited,n,d);
    for(int i=0;i<nb;i++){
        printf("%d ",bfs[i]);
    }
    printf("\n");//输出删除后广度遍历序列
    return 0;
}
void insert(int a,int b){
    node *p=NULL,*q=NULL;
    for(p=tu[a];p->link!=NULL;p=p->link){
        if(p->link->data>b){
            break;
        }
    }
    q=(node *)malloc(sizeof(node));
    q->data=b;
    if(p->link==NULL){
        q->link=NULL;
        p->link=q;
    }else{
        q->link=p->link;
        p->link=q;
    }
}//插入时应有序

void travelDFS(int visited[],int n,int d){
    int i;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    if(d>0){
        visited[d]=1;
    }
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            DFS(visited,i);
        }
    }
}
void DFS(int visited[],int i){
    visited[i]=1;
    dfs[nd]=i;
    nd++;
    node *p;
    for(p=tu[i]->link;p!=NULL;p=p->link){
        if(visited[p->data]!=1){
            DFS(visited,p->data);
        }
    }
}//深度遍历

void travelBFS(int visited[],int n,int d){
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    if(d>0){
        visited[d]=1;
    }
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            BFS(visited,i);
        }
    }
}
void BFS(int visited[],int i){
    visited[i]=1;
    node *p;
    enqueue(i);
    while(rear-front!=-1){
        i=dequeue();
        bfs[nb]=i;
        nb++;
        for(p=tu[i]->link;p!=NULL;p=p->link){
            if(visited[p->data]!=1){
                visited[p->data]=1;
                enqueue(p->data);
            }
        }
    }
}
void enqueue(int i){
    rear++;
    Q[rear]=i;
}
int dequeue(){
    int m;
    m=Q[front];
    front++;
    return m;
}//广度遍历
