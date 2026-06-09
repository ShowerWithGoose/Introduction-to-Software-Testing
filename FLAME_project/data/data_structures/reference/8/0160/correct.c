#include <stdio.h>
#include <stdlib.h>
int ii=0;
struct list{
	int num;
	int time;
	struct list *lst;
};
typedef struct list Lst,*List;
struct vertex{
	int num;
	int time;
	struct list *lst;
}Ver[100];
int xin[100];
int front=0,rear=0;
int ilist[100]={0};
void push(int v);
int pop();
void initial(struct vertex p[],int n){
	int i=0;
	for(i=0;i<n;i++){
		p[i].lst=(List)malloc(sizeof(Lst));
		p[i].num=0;p[i].time=0;
		p[i].lst->num=i;
		p[i].lst->time=0;
		p[i].lst->lst=NULL;
	}
}
void insert(List p,int v){
	List p1;
	if(p->lst==NULL){
		p1=(List)malloc(sizeof(Lst));
		p1->num=v;
		p1->lst=NULL;
		p1->time=0;
		p->lst=p1;
	}
	else if(v<p->lst->num){
		p1=(List)malloc(sizeof(Lst));
		p1->num=v;
		p1->time=0;
		p1->lst=p->lst;
		p->lst=p1;
	}
	else insert(p->lst,v);
}
void DFS1(List p);
void DFS(int n);
void WFS1(List p);
void WFS(List p,int n);
void del(int v,int n);

int main(){
	int e,n,i=0,v1,v2,v;
	scanf("%d%d",&n,&e);
	initial(Ver,n);
	for(i=0;i<e;i++){
		scanf("%d%d",&v1,&v2);
		insert(Ver[v1].lst,v2);
		insert(Ver[v2].lst,v1);
	}
	DFS(n);
	for(i=0;i<n;i++){
    	ilist[i]=0;	
	}
	WFS(Ver[0].lst,n);
	for(i=0;i<n;i++){
    	ilist[i]=0;	
	}
	scanf("%d",&v);
	del(v,n);
	DFS(n);
	for(i=0;i<n;i++){
    	ilist[i]=0;	
	}
	WFS(Ver[0].lst,n);
	return 0;
} 
void del(int v,int n){
	int i=0;
	List q;
	for(i=0;i<n;i++){
		q=Ver[i].lst; 
		if(i==v){
			while(q!=NULL){
			    q->time=1;
			    q=q->lst;
		    }
		} 
		else
		while(q!=NULL){
			if(q->num==v){
				q->time=1;
			}
			q=q->lst;
		}
	}
}
void DFS1(List p){
	List q;
	q=p->lst;
	if(p->time==0&&ilist[p->num]==0){
		printf("%d ",p->num);
		ilist[p->num]=1;
		DFS1(Ver[p->num].lst);
	}
	else if(p->lst!=NULL){
		DFS1(p->lst);
	}
	while(q!=NULL){
		if(q->time==0&&ilist[q->num]==0){
			DFS1(Ver[q->num].lst);
		}
		q=q->lst;
	}
}
void DFS(int n){
	int i=0;
	for(i=0;i<n;i++){
		if(Ver[i].lst->time==0){
			DFS1(Ver[i].lst);
		}
	}
	printf("\n");
}
void WFS1(List p){
	List q=p; 
	while(q!=NULL){
	    if(q->time==0&&ilist[q->num]==0){
		    printf("%d ",q->num);
		    push(q->num);
		    ilist[q->num]=1;
	    }
	    q=q->lst;
	}
	while(rear!=front){
		WFS1(Ver[pop()].lst);
	}
}
void WFS(List p,int n){
    int i=0;
    for(i=0;i<n;i++){
    	if(ilist[i]==0)
    	WFS1(Ver[i].lst);
	}
	printf("\n");
} 
void push(int v){
	xin[rear++]=v;
}
int pop(){
	return xin[front++];
}

