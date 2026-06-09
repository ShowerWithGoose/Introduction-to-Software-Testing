#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAXV 109
//#define MAXN 120
//define mst(s) memset(s,0,sizeof(s))
typedef struct ver
{
    int no;
    struct ver *next;
} vlink;
vlink adjacencyList[MAXV];
int visited[MAXV];
void DFS(int v);
void BFS(int v);
int main(void)
{
    //freopen("in.txt","r",stdin);
    int i,j,k,n,m,p1,p2,sumV,sumE;
    vlink *current,*last,*ptr1,*ptr2;
    scanf("%d %d",&sumV,&sumE);
    for(i=0;i<sumV;i++){
        adjacencyList[i].no=i;
    }
    for(i=1;i<=sumE;i++){
        scanf("%d %d",&p1,&p2);
        ptr1=(vlink *)malloc(sizeof(vlink));
        ptr2=(vlink *)malloc(sizeof(vlink));
        ptr1->no=p1;
        ptr2->no=p2;
        ptr1->next=ptr2->next=0;
        for(current=adjacencyList[p1].next,last=&adjacencyList[p1];current!=NULL&&p2>=current->no;last=current,current=current->next);
        last->next=ptr2;
        ptr2->next=current;
        for(current=adjacencyList[p2].next,last=&adjacencyList[p2];current!=NULL&&p1>=current->no;last=current,current=current->next);
        last->next=ptr1;
        ptr1->next=current;  
    }
    DFS(0);
    memset(visited,0,sizeof(visited));
    printf("\n");
    BFS(0);
    memset(visited,0,sizeof(visited));
    printf("\n");
    scanf("%d",&p1);
    adjacencyList[p1].no=-1;
    for(i=0;i<sumE;i++){
        if(adjacencyList[i].no==-1) continue;
        for(current=&adjacencyList[i];current;last=current,current=current->next){
            if(current->no==p1){
                last->next=current->next;
                free(current);
                break;
            }
        }
    }
    DFS(0);
    memset(visited,0,sizeof(visited));
    printf("\n");
    BFS(0);
    return 0;
}

void DFS(int v){
    vlink *current=&adjacencyList[v];
    visited[v]=1;
    printf("%d ",v);
    for(current=current->next;current;current=current->next){
        if(visited[current->no]==0){
            DFS(current->no);
        }
    }
    return;
}
void BFS(int v){
    int quene[MAXV],head=0,tail=0;
    vlink *current;
    quene[tail++]=v;
    visited[v]=1;
    while(tail-head!=0){
        printf("%d ",quene[head]);
        for(current=adjacencyList[quene[head]].next;current;current=current->next){
            if(visited[current->no]==0){
                visited[current->no]++;
                quene[tail++]=current->no;
            }
        }
        head++;
    }
    return ;
}
