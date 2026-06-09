#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int  link;
    int  len;
    struct node  *next;
}Node;
typedef struct amp{
    Node  *link;
}tag;
tag  G[256];
int Map[256]={0};
int V,E;
int  Q[1000];
int  F,R,C;
void mapmade(tag graph[]);
void  dfs(tag G[],int n,int temp);
void  bfs(tag G[],int n,int temp);
Node *add(Node *head, int avex);
int main(){
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        G[v1].link=add(G[v1].link,v2);
        G[v2].link=add(G[v2].link,v1);
    }
    dfs(G,V,-1);
    bfs(G,V,-1);
    int k;
    scanf("%d",&k);
    dfs(G,V,k);
    bfs(G,V,k);
    return 0;
}
Node *add(Node *head,int avex){
    Node *e,*p,*q=NULL;
    e=(Node *)malloc(sizeof(Node));
    e->link=avex;
	e->len=1;
	e->next=NULL;
    if(head==NULL)
        return e;
    for(p=head;p!=NULL&&avex>p->link;q=p,p=p->next)
        ;
    if(p==head){
        e->next=p;
        return e;
    }
    else{
        q->next=e;
        e->next=p;
        return head;
    }
}
void dfsadd(tag G[],int v){
    Node  *p;
    Map[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
        if(!Map[p->link])
            dfsadd(G,p->link);
}
void dfs(tag G[],int n,int temp){
    int i;
    for(i=0; i<n; i++)
        Map[i]=0;
    if(temp>=0)
        Map[temp]=1;
    for(i=0;i<n;i++)
        if(!Map[i]) 
			dfsadd(G,i);
    printf("\n");
}
void que(int queue[],int item){
    if(C==1000)
        printf("Full queue!");
    else{
        R=(R+1) % 1000;
        queue[R]=item;
        C++;
    }
}
int reque(int queue[]){
    int e;
    if(C==0)
        printf("Empty queue!");
    else{
        e=queue[F];
        C--;
        F=(F+1)%1000;
        return e;
    }
    return 0;
}
void BFS(tag G[],int v){
    Node *p;
    F=0;
    R=1000-1;
    C=0;
    Map[v]=1;
    que(Q,v);
    while(!(C==0)){
        v=reque(Q);
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
            if(!Map[p->link]) {
                Map[p->link]=1;
                que(Q,p->link);
            }
    }
}
void  bfs(tag G[],int n,int temp){
    for(int i=0;i<n;i++)
        Map[i] = 0 ;
    if(temp>=0)
        Map[temp]=1;
    for(int i=0;i<n;i++)
        if(!Map[i])
            BFS(G,i);
    printf("\n");
}


