#include <stdio.h>
#include <stdlib.h>
typedef struct edge{
    int adjvex;
    struct edge *link;
}Elink;
typedef struct{
    struct edge *link;
}Vlink;
Vlink head[1000];
int visit[1000];
int queue[1000];
int front,rear;
Elink * INSERTLINK5(Elink * list,int  item);
Elink *DELETELINK2(Elink * list, int q);
void dfs(int n);
void bfs();
int main(void){
    int n,e,x,y;
    rear=-1;front=-1;
    scanf("%d%d",&n,&e);
    for(int i=0;i<n;i++){
        head[i].link=NULL;
    }
    for(int i=0;i<e;i++){
        scanf("%d%d",&x,&y);
        head[x].link=INSERTLINK5(head[x].link,y);
        head[y].link=INSERTLINK5(head[y].link,x);
    }
    dfs(0);
    printf("\n");
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    bfs();
    printf("\n");
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    int m;
    scanf("%d",&m);
    head[m].link=NULL;
    visit[m]=1;
    for(int i=0;i<n;i++){
        if(i==m){
            continue;
        }
        DELETELINK2(head[i].link,m);
    }
    dfs(0);
    printf("\n");
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    visit[m]=1;
    rear=front=-1;
    bfs();
    printf("\n");
}
Elink * INSERTLINK5(Elink * list,int  item){
    Elink * p,*q,*r;
    p=(Elink *)malloc(sizeof(Elink));
    p->adjvex=item;
    p->link=NULL;
    if(list==NULL||item<list->adjvex){   //若为降序，则换为item>list->data
        p->link=list;
        list=p;
    }else{
        q=list;
        while(q!=NULL && item>=q->adjvex){     //若为降序，则换为item<=q->data
            r=q;
            q=q->link;
        }
        p->link=q;
        r->link=p;
    }
    return list;
}
Elink *DELETELINK2(Elink * list, int q){
    Elink * r;
    if(q==list->adjvex){
        list=list->link;
    }else{
        r=list;
        while((r->link!=NULL)&&((r->link)->adjvex)!=q)
            r=r->link;
        if(r->link!=NULL){
            r->link=r->link->link;
        }
    }
    return list;
}
void dfs(int n){
    if(visit[n]==1){
        return;
    }else{
        printf("%d ",n);
        visit[n]=1;
    }
    Elink *p=head[n].link;
    while(p!=NULL){
        dfs(p->adjvex);
        p=p->link;
    }
    return;
}
void bfs(){
    queue[++rear]=0;
    while(front!=rear){
        if(visit[queue[front+1]]==0){
            printf("%d ",queue[front+1]);
            visit[queue[front+1]]=1;
        }
        Elink *p=head[queue[front+1]].link;
        while(p!=NULL){
            if(visit[p->adjvex]==0){
                queue[++rear]=p->adjvex;
            }
            p=p->link;
        }
        front++;
    }
    return;
}


