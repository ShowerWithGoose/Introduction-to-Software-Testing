#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct node{
    int x;
    int y;
    struct node *next;
}Link;
typedef struct Node{
    Link *link;
}link;
link G[500];
int V,E,visited[500];
int Q[2000];
int front,rear,count;
void  create(link graph[]);
void  myDFS(link G[ ],int n,int delV);
void  myBFS(link G[ ],int n,int delV);
int main(){
    scanf("%d%d",&V,&E);
    create(G);
    myDFS(G,V,-1);
    myBFS(G,V,-1);
    int k;
    scanf("%d",&k);
    myDFS(G,V,k);
    myBFS(G,V,k);
    return 0;
}
Link *insert(Link *head,int a){
    Link *e,*p,*q=NULL;
    e=(Link *)malloc(sizeof(Link));
    e->x=a;
	e->y=1;
	e->next=NULL;
    if(head==NULL) return e;
    for(p=head;p!=NULL&&a>p->x;q=p,p=p->next) ;
    if( p == head){ 
        e->next=p;
        return e;
    }
    else{        
        q->next=e;
        e->next=p;
        return head;
    }
}
void create(link a[]){
    for(int i=0;i<E;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].link=insert(a[x].link, y);
        a[y].link=insert(a[y].link, x);
    }
}
void DFS(link G[],int v){
    Link *p;
    visited[v]=1; 
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next){
	    if(!visited[p->x]) DFS(G, p->x);	
	}
}
void myDFS(link G[],int n,int a){
    int i;
    for(i=0;i<n;i++) visited[i]=0;
    if(a>=0) visited[a]=1;
    for(i=0; i<n; i++){
		if(!visited[i]) DFS(G, i);
	} 
    puts("");
}
int Empty(){
    return count==0;
}
int Full(){
    return count==2000;
}
void first(int a[],int item){
    if(Full())  ;
    else{                            
        rear=(rear+1)%2000;
        a[rear]=item;
        count++;
    }
}
int last(int a[ ]){
    int m;
    if(Empty()) ;
    else{                           
        m=a[front];
        count--;
        front=(front+1)%2000;
        return m;
    }
    return 0;
}
void BFS(link G[],int v){
    Link *p;
    front=0;
	rear=1999;
	count=0;  
    visited[v]=1;
    first(Q,v);
    while(!Empty()){
        v=last(Q); 
        printf("%d ",v);
        for(p=G[v].link; p!=NULL;p=p->next){
            if(!visited[p->x]){
                visited[p->x] = 1; 
                first(Q, p->x);
            }
        }
    }
}
void myBFS(link G[],int n,int s){
    int i;
    for(i=0;i<n;i++) visited[i]=0 ;
    if(s>=0)  visited[s]=1;
    for(i=0;i<n;i++){
		if(!visited[i]) BFS(G,i);
	}
    puts("");
}

