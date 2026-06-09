/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <stdlib.h>
#define maxv 256

typedef struct edge{
    int adj;
    struct edge *next;
}elink;
typedef struct ver{
    int flag;
    elink *link;
}vlink;
vlink g[maxv];
int visited[maxv];
/////////////////////////////////////////////
void creategraph(vlink graph[],int n,int ne);
elink *insertedge(elink *head,int avex);
void traveldfs(vlink g[],int n);
void dfs(vlink g[],int v);
void travelbfs(vlink g[],int n);
void enq(int q[],int v);
int deq(int q[]);
void bfs(vlink g[],int v);
/////////////////////////////////////////////
void creategraph(vlink graph[],int n,int ne)
{
    int i,v1,v2;
    for(i=0;i<n;i++){
        
    }
    for(i=0;i<ne;i++){
        scanf("%d%d",&v1,&v2);
        g[v1].link=insertedge(g[v1].link,v2);
        g[v2].link=insertedge(g[v2].link,v1);
        //printf("完成连接%d %d\n",v1,v2);
    }
    //printf("完成存储图\n");
}

elink *insertedge(elink *head,int avex)
{
    elink *e,*p;
    e=(elink*)malloc(sizeof(elink));
    e->adj=avex;
    e->next=NULL;
    if(head==NULL){
        head=e;
        return head;
    }
    for(p=head;(p->next!=NULL);p=p->next){
        if((((p->adj)<(e->adj))&&((p->next->adj)>(e->adj)))){
            //printf("把新节点%d插到%d和%d之间\n",e->adj,p->adj,p->next->adj);
            e->next=p->next;
            p->next=e;
            break;
        }
    }
    //printf("把%d插在%d之后\n",e->adj,p->adj);
    p->next=e; // @@ [This line causes an error because if the loop exits without breaking (i.e., when e->adj is larger than all existing nodes), p points to the last node, and we correctly append e. However, if the new node should be inserted at the beginning (e->adj < head->adj), this logic fails to handle that case, leading to unsorted adjacency lists which violates the requirement to visit neighbors in ascending order.]
    return head; 
    
}



void traveldfs(vlink g[],int n)//深度遍历dfs 
{
    int i;
    for(i=0;i<n;i++){
        visited[i]=0;//初始化 
    }
    for(i=0;i<n;i++){
        if(visited[i]!=1){//未遍历过
        
            dfs(g,i);
        }
        //printf("%d回退\n",i);
    }
    printf("\n");
}

void dfs(vlink g[],int v)
{
    if(g[v].flag!=-1){
    elink *p;
    visited[v]=1;//标记被遍历过
    printf("%d ",v); 
    for(p=g[v].link;p!=NULL;p=p->next){
        //printf("扫到%d\n",p->adj);
        if(visited[p->adj]!=1){
            //printf("%d未访问过\n",p->adj);
            dfs(g,p->adj);
        }
    }
    }
}
int q[maxv];
int start=-1,end=-2;
void travelbfs(vlink g[],int n)
{
    int i;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0;i<n;i++){
        if(visited[i]!=1){
        bfs(g,i);
        }
    }
    printf("\n");
}
void enq(int q[],int v){
    end++;
    q[end]=v;
    
}

int deq(int q[]){
    int a;
    //printf("en start=%d\n",start);
    a=q[start];
    start++;
    return a;
}

void bfs(vlink g[],int v)
{
    if(g[v].flag!=-1){
    
    elink *p;
    visited[v]=1;
    enq(q,v);
    while(start<=end){
        v=deq(q);
        printf("%d ",v); 
        for(p=g[v].link;p!=NULL;p=p->next){
            if(visited[p->adj]!=1){
                visited[p->adj]=1;
                enq(q,p->adj);
            }
        }
    }
    }
}

int main(){
    int i,n,ne,del;
    scanf("%d%d",&n,&ne);
    creategraph(g,n,ne);
    scanf("%d",&del);
    traveldfs(g,n);
    travelbfs(g,n);
    /*printf("==============================\n");
    for(i=0;i<n;i++){
        elink *p;
        printf("%d->",i);
        for(p=g[i].link;p!=NULL;p=p->next){
            printf("%d ",p->adj);
        }
        printf("\n");
    }
    printf("==============================\n");
    */
    elink *p,*q,*pf;
    for(i=0;i<n;i++){
        //printf("i=%d\n",i);
        if(i!=del){
            for(p=g[i].link;p->next!=NULL;p=p->next){ // @@ [This loop condition 'p->next != NULL' skips the last node in the adjacency list, so if the vertex to delete is the last neighbor, it won't be removed. This leads to incorrect graph structure after deletion.]
                if(g[i].link->adj==del){
                    g[i].link=p->next; // @@ [This assignment is incorrect: 'p' is the current node in the loop, but if the head itself matches 'del', we should update g[i].link directly, not via 'p->next'. Also, 'p' may not even be initialized properly in this context.]
                    //printf("头结点是%d\n",del);
                }
                else{
                    if(p->next->adj==del){
                        //printf("找到%d\n",del);
                        q=p->next;
                        if(q->next!=NULL){//q不是链表末尾 
                            //printf("%d不是链表末尾\n",q->adj); 
                            p->next=q->next;
                            //printf("释放%d\n",q->adj);
                            free(q);
                        }
                        else{
                            //printf("%d是链表末尾，直接释放\n",q->adj);
                            p->next=NULL;
                            free(q);
                            break;
                        }
                        //printf("完成一次删除操作\n");
                    }    
                }
            }
        }
        else if(i==del){
            //printf("遇到删除的节点，直接全部删除\n");
            g[i].link->adj=-1; // @@ [If g[i].link is NULL (which can happen if the vertex has no edges, though unlikely per problem constraints), this dereference causes undefined behavior. Also, setting adj=-1 is unnecessary; just set link to NULL.]
            g[i].flag=-1;
            g[i].link=NULL;
        }
    }
    /*printf("==============================\n");
    for(i=0;i<n;i++){
        elink *p;
        printf("%d->",i);
        for(p=g[i].link;p!=NULL;p=p->next){
            if(g[i].link->adj!=-1){
                printf("%d ",p->adj);
            }
        }
        printf("\n");
    }
    printf("==============================\n");
    */
    traveldfs(g,n);
    travelbfs(g,n);
}