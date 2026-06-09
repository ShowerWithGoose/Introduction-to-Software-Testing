#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int ling[999][999],que[999];
int visited[999];
int shanchu[999];
int n,m;//n dian m bian
struct edge{//bian jiedian
    int  data;
    struct edge  *next;
}*p,*q,*list;
struct ver{//ding dian jiedian
    struct edge *link;
    int dian;
}*ding[999],*ding1[999],*r;

void guangdu(int v){
	int i,head=0,tail=1,tmp;
 que[head]=v;
 while(head<=tail) 
 {
  tmp=que[head];
  head++;  
  if(visited[tmp]) continue;
  else
  {
   printf("%d ",tmp); 
   visited[tmp]=1;  
   for(i=0;i<n;i++)
    if (ling[tmp][i] && !visited[i]) 
     que[tail++]=i; 
  }
 }
}

void shendu(struct ver * a){
	struct edge *a1;
	if(visited[a->dian]==0){
		printf("%d ",a->dian);
	    visited[a->dian]=1;
	}
	a1=a->link;
	while(a1->next!=NULL&&visited[a1->data]==1){
		a1=a1->next;
	}
	if(a1->next==NULL&&visited[a1->data]==0){
		shendu(ding[a1->data]);
	}
	
	while(a1->next!=NULL){
		shendu(ding[a1->data]);
		while(a1->next!=NULL&&visited[a1->data]==1){
	        a1=a1->next;
	    }
	    if(a1->next==NULL&&visited[a1->data]==0){
		    shendu(ding[a1->data]);
	    }
	}
}
void shendu1(struct ver * a){
	struct edge *a1;
	if(visited[a->dian]==0){
		printf("%d ",a->dian);
	    visited[a->dian]=1;
	}
	a1=a->link;
	while(a1->next!=NULL&&visited[a1->data]==1){
		a1=a1->next;
	}
	if(a1->next==NULL&&visited[a1->data]==0){
		shendu(ding1[a1->data]);
	}
	
	while(a1->next!=NULL){
		shendu(ding1[a1->data]);
		while(a1->next!=NULL&&visited[a1->data]==1){
	        a1=a1->next;
	    }
	    if(a1->next==NULL&&visited[a1->data]==0){
		    shendu(ding1[a1->data]);
	    }
	}
}



int main(){
	int i,j,u,v,shan;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		ling[u][v]=ling[v][u]=1;
	}
	for(i=0;i<n;i++){//jianli bian jiedian
		ding[i]=(struct ver *)malloc(sizeof(struct ver));
		ding[i]->link=NULL;
		ding[i]->dian=i;
		ding1[i]=(struct ver *)malloc(sizeof(struct ver));
		ding1[i]->link=NULL;
		ding1[i]->dian=i;
	}
	scanf("%d",&shan);
	for(i=0;i<n;i++){//jianli lingjie biao
		for(j=0;j<n;j++){
			if(ling[i][j]&&i!=j){
				p=(struct edge *)malloc(sizeof(struct edge));
		        p->next=NULL;
		        p->data=j;
		        if(ding[i]->link!=NULL){
		        	q=ding[i]->link;
		        	while(q->next!=NULL){
		        		q=q->next;
					}
					q->next=p;
				}
				else if(ding[i]->link==NULL){
					ding[i]->link=p;
				}
			}
		}
	}
	shendu(ding[0]);
	printf("\n");
	
	
	
	for(i=0;i<=n;i++){
		visited[i]=0;
	}
	guangdu(0);
	printf("\n");
	
	
	
	
	for(i=0;i<n;i++){
		ling[shan][i]=0;
		ling[i][shan]=0;
	}
	
	for(i=0;i<n;i++){//jianli lingjie biao
		for(j=0;j<n;j++){
			if(ling[i][j]&&i!=j){
				p=(struct edge *)malloc(sizeof(struct edge));
		        p->next=NULL;
		        p->data=j;
		        if(ding1[i]->link!=NULL){
		        	q=ding1[i]->link;
		        	while(q->next!=NULL){
		        		q=q->next;
					}
					q->next=p;
				}
				else if(ding1[i]->link==NULL){
					ding1[i]->link=p;
				}
			}
		}
	}
	
	
	for(i=0;i<=n;i++){
		visited[i]=0;
	}
	visited[shan]=1;
	shendu1(ding1[0]);
	printf("\n");
	
	for(i=0;i<=n;i++){
		visited[i]=0;
	}
	visited[shan]=1;
	guangdu(0);
	
}



