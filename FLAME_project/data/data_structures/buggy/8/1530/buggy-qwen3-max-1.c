#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
#define M 500
#define tolower(c) ((c)>='A'&&(c)<='Z'?'a'-'A'+(c):(c))
#define isalpha(c) (((c)>='A'&&(c)<='Z')||((c)>='a'&&(c)<='z')?1:0)
#define isnum(c) (((c)>='0'&&(c)<='9')?1:0)
typedef struct edge{
    int index;
    struct edge *next;    
}Elink;
typedef struct top{
//    int index;
    Elink *link;
}Tlink,*pt;
Tlink G[M];
Elink* Q[M];
Elink* qtop=NULL,*qtail=NULL;
int visited[M];
Elink* insert(Elink *head,int v){
    Elink *p,*node=(Elink*)malloc(sizeof(Elink));
    node->next=NULL;
    node->index=v;
    if(head==NULL){
        head=node;
        return head;
    }
    Elink* tmp=NULL;
    for(p=head,tmp=head;p!=NULL;tmp=p,p=p->next){
        if(p->index>node->index){
            if(p==head){
                Elink* tmp1=NULL,*tmp2=NULL;
                tmp1=head;
                tmp2=p->next;
                head=node;
                head->next=tmp1;
                tmp1->next=tmp2;
                return head;
            }
            else{
                Elink* tmp1=NULL,*tmp2=NULL;
                tmp1=p;
                tmp2=p->next;
                p=node;
                p->next=tmp1;
                tmp1->next=tmp2;
                tmp->next=p;
                return head;
            }
        }
    }
    tmp->next=node;
    return head;
}
void dfs(int i){
    Elink *p;
    visited[i]=1;
    printf("%d",i); // @@ [Missing space after each vertex number in output; should be "printf(\"%d \", i);"]
    for(p=G[i].link;p!=NULL;p=p->next){
        if(!visited[p->index])
            dfs(p->index);
    }
}
void DFS(int n,int e){
    for(int i=0;i<n;i++){
        if(i==e)
        visited[i]=1;
        else
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}
void enQueue(int v){
    if(qtop==NULL){
        qtop=(Elink*)malloc(sizeof(Elink));
        qtop->index=v;
        qtail=qtop;
        qtail->next=NULL;
    }
    else{
        qtail->next=(Elink*)malloc(sizeof(Elink));
        qtail->next->index=v;
        qtail=qtail->next;
        qtail->next=NULL;
    }    
}
int deque(){
    int a=qtop->index;
    qtop=qtop->next;
//    free(qtop);
    return a;
}
int empty(){
    return qtop==NULL;
}
void bfs(int i){
    Elink *p;
    visited[i]=1;
    enQueue(i);
    while(!empty()){
        i=deque();
        printf("%d",i); // @@ [Missing space after each vertex number in output; should be "printf(\"%d \", i);"]
        for(p=G[i].link;p!=NULL;p=p->next){
            if(!visited[p->index]){
                visited[p->index]=1;
                enQueue(p->index);
            }
        }
    }

}
void BFS(int n,int e){
    for(int i=0;i<n;i++){
        if(i==e)
        visited[i]=1;
        else
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(i);
        }
    }
}
int main(void)
{
    int dotn,edgen,est;
    scanf("%d%d",&dotn,&edgen);
//    printf("%d %d\n",dotn,edgen);
    for(int i=0;i<edgen;i++){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
//        printf("%d%d\n",v1,v2);
        G[v1].link=insert(G[v1].link,v2);
        G[v2].link=insert(G[v2].link,v1);
    }
    scanf("%d",&est);
//    printf("%d\n",est);
    DFS(dotn,-1);
    printf("\n");
    BFS(dotn,-1);
    printf("\n");
    DFS(dotn,est);
    printf("\n");
    BFS(dotn,est);
return 0;
}