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
    for(p=head;(p->next!=NULL);p=p->next){ // @@ 循环条件错误：当p->next为NULL时循环结束，导致无法在链表末尾插入节点，且插入逻辑不完整
        if((((p->adj)<(e->adj))&&((p->next->adj)>(e->adj)))){
            //printf("把新节点%d插到%d和%d之间\n",e->adj,p->adj,p->next->adj);
            e->next=p->next;
            p->next=e;
            break;
        }
    }
    //printf("把%d插在%d之后\n",e->adj,p->adj);
    p->next=e; // @@ 错误：无论是否找到插入位置，都会将e连接到p之后，导致重复连接或错误连接
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
            for(p=g[i].link;p->next!=NULL;p=p->next){ // @@ 错误：当链表只有一个节点时，p->next为NULL，循环不执行，无法删除头节点
                if(g[i].link->adj==del){
                    g[i].link=p->next;
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
            g[i].link->adj=-1; // @@ 错误：访问空指针，因为g[i].link可能为NULL
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