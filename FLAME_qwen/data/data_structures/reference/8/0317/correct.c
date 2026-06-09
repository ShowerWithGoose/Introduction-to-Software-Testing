#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
typedef struct edge{
       int  adjvex;
       struct edge  *next;
}ELink;
int Visited[110]={0};
void DFS(ELink *G[],int v)
{
    ELink *p;
    Visited[v] = 1; 	//标识某顶点被访问过
    printf("%d ",v);	//访问某顶点
    for(p=G[v];p!=NULL;p=p->next)
         if(Visited[p->adjvex]!=1)
            DFS(G,p->adjvex);
}
void BFS(ELink *G[],int v)
{
    ELink *p;
    int rear=0,end=1,t;
    int que[110];
    int record[110]={0};
    que[0]=v;
	record[v]=1;      
    while(rear<end){  
         t=que[rear++];
		 printf("%d ",t);
         p=G[t];        
         while(p!=NULL){
         	if(record[p->adjvex]==0){
         		que[end++]=p->adjvex;
         		record[p->adjvex]=1;
         	}
         	p=p->next;
		 }
     }
}
int main()
{
	ELink *G[110];
	int vernum,edgnum,delet;
	int i,v1,v2;
	ELink *p,*r,*q;
	
	scanf("%d %d",&vernum,&edgnum);
	
	for(i=0;i<=109;i++){
		G[i]=NULL;
	}
	for(i=1;i<=edgnum;i++){
		scanf("%d %d",&v1,&v2);
		q=(ELink*)malloc(sizeof(ELink));
		q->adjvex=v2;
		q->next=NULL;
		if(G[v1]==NULL){
			G[v1]=q;
		}
		else{
			for(p=G[v1];p!=NULL && p->adjvex<=v2;r=p,p=p->next);
			if(p==G[v1]){
				q->next=p;
				G[v1]=q;
			}
			else if(p==NULL){
				r->next=q;
			}
			else if(p!=NULL && p!=G[v1]){
				r->next=q;
				q->next=p;
			}
		}
		
		q=(ELink*)malloc(sizeof(ELink));
		q->adjvex=v1;
		q->next=NULL;
		if(G[v2]==NULL){
			G[v2]=q;
		}
		else{
			for(p=G[v2];p!=NULL && p->adjvex<=v1;r=p,p=p->next);
			if(p==G[v2]){
				q->next=p;
				G[v2]=q;
			}
			else if(p==NULL){
				r->next=q;
			}
			else if(p!=NULL && p!=G[v2]){
				r->next=q;
				q->next=p;
			}
		}
	}
	
	
	DFS(G,0);
	printf("\n");
	for(i=0;i<110;i++)
		Visited[i]=0;
	BFS(G,0);
	printf("\n");
	for(i=0;i<110;i++)
		Visited[i]=0;
	
	scanf("%d",&delet);
	G[delet]=NULL;
	
	for(i=0;i<110;i++){
		if(G[i]!=NULL){
			for(p=G[i];p!=NULL;r=p,p=p->next){
				if(p->adjvex==delet){
					if(p==G[i]){
						G[i]=p->next;
					}
					else{
						r->next=p->next;
					}
				}
			}
		}
	}
	
	DFS(G,0);
	printf("\n");
	for(i=0;i<110;i++)
		Visited[i]=0;
	BFS(G,0);
	printf("\n");
	for(i=0;i<110;i++)
		Visited[i]=0;
		

	return 0;
}









