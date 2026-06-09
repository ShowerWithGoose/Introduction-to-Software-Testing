#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MaxV 256

typedef struct edge{
    int dot;
    struct edge *next;
}Elink;

typedef struct ver{
     Elink *link;
}Vlink;
Vlink G[MaxV];

int Visited[MaxV]={0}; 
int Queue[MaxV]={0};
int tail=-1;int top=0;int count=0;
Elink *insertEdge(Elink *head,int avex){
    Elink *e,*p,*pre;
    
    e=(Elink*)malloc(sizeof(Elink));
    e->dot=avex;
    e->next=NULL;
    
    if(head==NULL){
        head=e; return head;
    } 
    else{
        for(p=head;p!=NULL;p=p->next){
            if(p->dot>avex){
                if(p==head){
                    e->next=head;
                    head=e;
                    return head;
                }
                else{
                    e->next=pre->next;
                    pre->next=e;
                    return head;
                }
            }
            pre=p;
        }
        pre->next=e;
        return head;
    }
}
void cutlink(int v,int cut){
    Elink *p=G[v].link,*pre=p;
    while(p!=NULL){
        if(p->dot==cut){
            if(p==G[v].link){
                G[v].link=p->next;
                   free(p);
                
            }
            else{
                pre->next=p->next;
                free(p);
            }
            return;
        }
        pre=p;
        p=p->next;
    }
    return;
}



void enQueue(int v){
    if(tail>=MaxV) return;
    else{
        Queue[++tail]=v;
        count++;
    }
}
void DFS(Vlink G[],int v);
void BFS(Vlink G[],int v);


int main()
{
   int i,v1,v2;
   int cut;
   int Vnum;//顶点个数
   int Bnum;//边个数
   
   scanf("%d %d",&Vnum,&Bnum);
   for(i=0;i<Bnum;i++){
         scanf("%d %d",&v1,&v2);
         G[v1].link=insertEdge(G[v1].link,v2);
         G[v2].link=insertEdge(G[v2].link,v1);
   }//建立图
   scanf("%d",&cut);
   
   //删前
    DFS(G,0);printf("\n");
    memset(Visited,0,MaxV); 
    
    
    BFS(G,0);printf("\n");
    memset(Visited,0,MaxV);
    memset(Queue,0,MaxV);
    top=0;count=0;tail=-1;
    
    //删除 
    Elink *p=G[cut].link;
    for(;p!=NULL;p=p->next){
        cutlink(p->dot,cut);
    }
    
       
    
    //删后 
    DFS(G,0);printf("\n");
    memset(Visited,0,MaxV); 
    
    BFS(G,0);printf("\n");
    
   return 0;
}


void DFS(Vlink G[],int v){
    Elink *p;
    Visited[v]=1;
    printf("%d",v); // @@ Missing space after %d; should be "%d " to match expected output format.
    for(p=G[v].link;p!=NULL;p=p->next){
        if(!Visited[p->dot])
            DFS(G,p->dot);
    }
}

void BFS(Vlink G[],int v){
    Elink *p;
    Visited[v]=1;
    enQueue(v);
    while(count!=0){
        v=Queue[top++];count--;
        printf("%d",v); // @@ Missing space after %d; should be "%d " to match expected output format.
        for(p=G[v].link;p!=NULL;p=p->next){
            if(!Visited[p->dot]){
                Visited[p->dot]=1;
                enQueue(p->dot);
            }
        }
    }
}