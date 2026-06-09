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
    p->next=e; // @@ The insertion logic is flawed. If the loop finishes without breaking (meaning avex is larger than all existing nodes), it appends correctly. However, if it breaks inside the loop, it executes this line again, creating a cycle or incorrect link. Also, it fails to handle the case where avex should be inserted before the head or between head and head->next if the loop condition `p->next!=NULL` prevents checking the last position properly relative to sorted order. Specifically, if the list is `1->3` and we insert `2`, `p` is `1`, `p->next` is `3`. `1<2` and `3>2` is true. It inserts `2` after `1`. Then `break`. Then `p->next=e` executes again? No, `break` exits loop. But wait, if it doesn't break, it appends. The main issue is that if the element is smaller than head, it is not handled. And if it breaks, `p->next=e` is executed AFTER the loop? No, the code structure is: loop { if... break; } p->next=e; This means regardless of whether it broke or not, it sets p->next to e. If it broke inside, p->next was already set to e. So it sets it again. But if it didn't break, p is the last node, and it appends. The critical error is that if the new node is smaller than the first node, the loop runs, p stays at head. If head->next is NULL, loop doesn't run. p->next=e appends. But if head->adj > avex, it should be inserted at head. This function does not handle insertion at the beginning correctly if head is not NULL.
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
        if(visited[p->adj]!=1 && g[p->adj].flag != -1){ // @@ Must check if the adjacent vertex is deleted (flag == -1) before visiting. Without this, DFS might try to visit a deleted node if it's still reachable in the adjacency list (though the list is modified, consistency is key) or simply to ensure logical correctness matching the BFS behavior which implicitly skips deleted nodes by checking flag or by removal. Actually, the deletion code removes edges TO del, but does it remove edges FROM del? Yes, it sets g[del].link=NULL. But other nodes pointing to del have those edges removed. However, relying on flag check is safer and standard for "logical" deletion if physical removal is incomplete or buggy. Given the physical removal code is complex and potentially buggy, adding the flag check ensures deleted nodes are skipped.
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
            if(visited[p->adj]!=1 && g[p->adj].flag != -1){ // @@ Must check if the adjacent vertex is deleted (flag == -1). Similar to DFS, this ensures that deleted vertices are not enqueued or visited.
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
            for(p=g[i].link;p->next!=NULL;p=p->next){ // @@ This loop condition `p->next!=NULL` skips checking the last node in the linked list for deletion. If the node to be deleted (`del`) is the last neighbor in the adjacency list, it will not be removed. Also, if the list has only one node, the loop doesn't run at all.
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
            g[i].link->adj=-1; // @@ Potential crash if g[i].link is NULL. Should check for NULL.
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