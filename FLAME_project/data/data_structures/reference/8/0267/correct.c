#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int vert;
	struct edge *next;
} Elink;
typedef struct ver{
	Elink *link;
} Vlink;
Vlink V[105];
Elink* insertGraph(Elink *head,int ver){
	Elink *e,*p;
	e=(Elink*)malloc(sizeof(Elink));
	e->vert=ver;
	e->next=NULL;
	if(head==NULL)
		head=e;
	else{
		for(p=head;p->next!=NULL;p=p->next);
		p->next=e;
	}
	return head;
}
void createGraph(int n){
	int i,v1,v2;
	for(i=0;i<n;i++){
		scanf(" %d %d",&v1,&v2);
		V[v1].link=insertGraph(V[v1].link,v2);
		V[v2].link=insertGraph(V[v2].link,v1);
	}
}
void sortGraph(int n){
	int i,j,k,m=0,s[105],t;
	Elink *p;
	for(i=0;i<n;i++){
		for(p=V[i].link;p!=NULL;p=p->next)
			s[m++]=p->vert;
		for(j=0;j<m-1;j++){
			for(k=j+1;k<m;k++){
				if(s[k]<s[j]){
					t=s[k];
					s[k]=s[j];
					s[j]=t;
				}
			}
		}
		j=0;
		for(p=V[i].link;j<m;p=p->next)
			p->vert=s[j++];
		m=0;
	}
}
int Visit1[105]={0};
void DFS(int v){
	Elink *p;
	Visit1[v]=1;
	printf("%d ",v);
	for(p=V[v].link;p!=NULL;p=p->next){
		if(Visit1[p->vert]==0)
			DFS(p->vert);
	}
}
void travelDFS(int n){
	int i;
	for(i=0;i<n;i++)
		Visit1[i]=0;
	for(i=0;i<n;i++)
		if(Visit1[i]==0)
			DFS(i);
}
void travelDFS0(int n,int d){
	int i;
	for(i=0;i<n;i++)
		Visit1[i]=0;
		Visit1[d]=1;
	for(i=0;i<n;i++)
		if(Visit1[i]==0)
			DFS(i);
}

int Visit2[105]={0};
void BFS(int v){
	Elink *p;
	int Queue[105],head;
	int rear=-1,front=0;
	printf("%d ",v);
	Visit2[v]=1;
	Queue[++rear]=v;
	while(front<=rear){
		head=Queue[front++];
		for(p=V[head].link;p!=NULL;p=p->next){
			if(Visit2[p->vert]==0){
				printf("%d ",p->vert);
				Visit2[p->vert]=1;
				Queue[++rear]=p->vert;
			}
		}
	}
}
void travelBFS(int n){
	int i;
	for(i=0;i<n;i++)
		Visit2[i]=0;
	for(i=0;i<n;i++)
		if(Visit2[i]==0)
			BFS(i);
}
void travelBFS0(int n,int d){
	int i;
	for(i=0;i<n;i++)
		Visit2[i]=0;
		Visit2[d]=1;
	for(i=0;i<n;i++)
		if(Visit2[i]==0)
			BFS(i);
}
int main()
{
	int m,n,dp;
	scanf("%d%d",&m,&n);//m¸ö¶¥µãnÌõ±ß 
	createGraph(n);
	sortGraph(n);
	
	travelDFS(m);
	printf("\n");
	travelBFS(m);
	printf("\n");
	
	scanf("%d",&dp);
	travelDFS0(m,dp);
	printf("\n");
	travelBFS0(m,dp);
	return 0;
}

