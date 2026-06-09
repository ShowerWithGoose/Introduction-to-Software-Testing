#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct edge{
    int adjvex;
    struct edge *next;
}*pelink,elink;
typedef struct ver{
    pelink link;
}vlink;
int visited[110]={0},quene[1100],head=0,rear=-1;
void insert(pelink head,int data){
    pelink e,p;
    e=(pelink)malloc(sizeof(elink));
    e->adjvex=data;;
    if(head->next==NULL){
        head->next=e;
        e->next=NULL;
        return ;
    }
    for(p=head;p->next!=NULL;p=p->next){
        if(p->adjvex<data&&p->next->adjvex>data){
            e->next=p->next;
            p->next=e;
            return ;
        }
    }
    p->next=e;
    e->next=NULL;        
}
void DFS(vlink *g,int v){
    pelink p;
    visited[v]=1; //标识某顶点被访问过
    printf("%d ",v); //访问某顶点
    for(p=g[v].link->next;p!=NULL;p=p->next){
        if(!visited[p->adjvex])
            DFS(g,p->adjvex);
    }
}
void BFS(vlink *g,int v){
    pelink p;
    printf("%d ",v); //访问当前顶点
    visited[v]=1; //标识某顶点被访问过
    quene[++rear]=v;
    while(head<=rear){
        v=quene[head++]; //取出队头元素
        for(p=g[v].link->next;p!=NULL;p=p->next){
            if(!visited[p->adjvex]){
                printf("%d ",p->adjvex); //访问当前顶点
                visited[p->adjvex]=1; //标识某顶点被访问过
                quene[++rear]=p->adjvex;
            }
        }
    }
}
int main(){
    int n,m,i,x,y,move;
    pelink p,q;
    vlink g[110];
    scanf("%d%d",&n,&m);
    for(i=0;i<=n-1;i++){
        g[i].link=(pelink)malloc(sizeof(elink));
        g[i].link->adjvex=-1;
        g[i].link->next=NULL;
    }      
    for(i=0;i<=m-1;i++){
        scanf("%d%d",&x,&y);
        insert(g[x].link,y);
        insert(g[y].link,x);
    }
    for(i=0;i<=n-1;i++){
        if(!visited[i])
            DFS(g,i);
    }   
    printf("\n");
    memset(visited,0,sizeof(visited));
    for(i=0;i<=n-1;i++){
        if(!visited[i])
            BFS(g,i);
    } 
    printf("\n");
    memset(visited,0,sizeof(visited));
    head=0;
    rear=-1;
    scanf("%d",&move);
    for(i=0;i<=n-1;i++){
        if(i!=move){
            for(p=g[i].link;p->next!=NULL;p=p->next){
                if(p->next->adjvex==move){
                    q=p->next;
                    p->next=q->next;
                    free(q);
                    break;
                }
            }
        }
    }
    for(i=0;i<=n-1;i++){
        if(i!=move&&!visited[i])
            DFS(g,i);
    } 
    printf("\n");
    memset(visited,0,sizeof(visited));
    for(i=0;i<=n-1;i++){
        if(i!=move&&!visited[i])
            BFS(g,i);
    } 
    return 0;
}
