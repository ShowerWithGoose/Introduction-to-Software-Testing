#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
    int adjvex;
    struct edge *next;
}Elink,*Elinkptr;
typedef struct ver{
    int vertex;
    Elinkptr link;
}Vlink,*Vlinkptr;
Vlink graph[101];

int visited[101],visitNum=0;
int queue[101],rear=-1,fron=0;
int target=-1;
void enQueue(int i){
    queue[++rear] = i;
    return ;
}
int deQueue(){
    return queue[fron++];
}
int isemptyQueue(){
    if(rear-fron<=-1) return 1;
    return 0;
}
void initGraph(int ver_num){
    for(int i=0;i<ver_num;i++){
        graph[i].link=NULL;
        graph[i].vertex = i;
    }
    return ;
}
Vlink insertEdge(Vlink source,Elinkptr p){
    if(source.link==NULL){
        source.link = p;
    }else{
        Elinkptr q,before;
        q = before = source.link;
        for(;q!=NULL;before=q,q=q->next){
            if(q->adjvex>p->adjvex){
                if(q==source.link){
                    p->next = source.link;
                    source.link = p;
                }else{
                    p->next = before->next;
                    before->next = p;
                }
                break;
            }
        }
        if(q==NULL) before->next = p;
    }
    return source;
}
Elinkptr createEdge(int adjvex){
    Elinkptr p;
    p = (Elinkptr)malloc(sizeof(Elink));
    p->adjvex = adjvex;
    p->next = NULL;
    return p;
}
void createGraph(int edge_num){
    int x,y;
    while(edge_num--){
        scanf("%d %d",&x,&y);
        Elinkptr p;
        p = createEdge(y);
        graph[x] = insertEdge(graph[x],p);
        p = createEdge(x);
        graph[y] = insertEdge(graph[y],p);
    }
}
void initVisitVer(int ver_num){
    visitNum = 0;
    for(int i=0;i<ver_num;i++){
        visited[i] = 0;
    }
    if(target!=-1) visited[target] = 1;
    return ;
}
Vlink deleteEdge(Vlink source,int target){
    if(source.link==NULL) return source;
    Elinkptr p,before;
    for(p=before=source.link;p!=NULL;before=p,p=p->next){
        if(target==p->adjvex){
            if(p==source.link){
                source.link = p->next;
                free(p);
                return source;
            }else{
                before->next = p->next;
                free(p);
                return source;
            }
        }
    }
    if(before->adjvex==target){
        for(p=source.link;p->next!=before;before=p,p=p->next){}
        p->next=NULL;
        free(before);
        return source;
    }
}
void removeFunc(int target,int ver_num){
    for(int i=0,j=0;i<ver_num;i++){
        if(j==target){
            continue;
        }
        graph[j] = graph[i];
        graph[j] = deleteEdge(graph[j],target);
        j++;
    }
    return ;
}
void visit(int i,int ver_num){
    visitNum++;
    if(visitNum!=1){
        printf(" ");
    }
    printf("%d",i);
    if(target!=-1) ver_num--;
    if(visitNum == ver_num){
        printf("\n");
    }
    return ;
}
void DFS(int i,int ver_num){
    visited[i] = 1;
    visit(i,ver_num);
    Elinkptr p;
    for(p=graph[i].link;p!=NULL;p=p->next){
        if(!visited[p->adjvex]){
            DFS(p->adjvex,ver_num);
        }
    }
    return ;
}
void BFS(int i,int ver_num){
    visited[i] = 1;
    enQueue(i);
    while(!isemptyQueue()){
        int tpm = deQueue();
        visit(tpm,ver_num);
        Elinkptr p ;
        for(p=graph[tpm].link;p!=NULL;p=p->next){
            if(!visited[p->adjvex]){
                visited[p->adjvex]=1;
                enQueue(p->adjvex);
            }
        }
    }
    return ;
}
void travelDFS(int ver_num){
    initVisitVer(ver_num);
    for(int i=0;i<ver_num;i++){
        if(i==target) continue;
        if(!visited[i]) DFS(i,ver_num);
    }
    return ;
}
void travelBFS(int ver_num){
    initVisitVer(ver_num);
    for(int i=0;i<ver_num;i++){
        if(i==target) continue;
        if(!visited[i]) BFS(i,ver_num);
    }
    return ;
}
int main(){
    int ver_num=0,edge_num=0;
    scanf("%d %d",&ver_num,&edge_num);
    initGraph(ver_num);
    createGraph(edge_num);
    travelDFS(ver_num);
    travelBFS(ver_num);
    scanf("%d",&target);
    travelDFS(ver_num);
    travelBFS(ver_num);
    return 0;
}


