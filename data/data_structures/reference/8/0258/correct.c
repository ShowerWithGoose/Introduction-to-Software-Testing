/*#include<stdio.h>
#include<stdlib.h>
typedef struct _graph{
	int pos;
	int ischeaked;
	struct _graph *link;
}graph[100],*Pgraph;

typedef struct _point{
	int p1,p2;
}point,*Point;

Pgraph gra[100]={NULL};
point total[100];
Pgraph root=NULL;
int DFS_undeleted[100];
int BFS_undeleted[100];
int DFS_deleted[100];
int BFS_deleted[100];
int DFS=0,BFS=0;

int comp(const void *a,const void *b);
Pgraph creat_DFS_tree(Pgraph p, int a);
Pgraph search(Pgraph a);


int main(){
	int vterx,edge;
	scanf("%d %d",&vterx,&edge);
	for(int i=0;i<edge;i++) scanf("%d %d",&total[i].p1,&total[i].p2);
	for(int i=edge;i<2*edge;i++){
		total[i].p1=total[i-edge].p2;
		total[i].p2=total[i-edge].p1;
	}
	qsort(total,2*edge,sizeof(point),comp);
	for(int i=0;i<100;i++) {
		if(gra[i]==NULL){
			gra[i]=(Pgraph)malloc(sizeof(graph));
			gra[i]->pos=i;
			gra[i]->ischeaked=-1;
			gra[i]->link=NULL;		
		}
	}
	for(int i=0;i<2*edge;i++) gra[total[i].p1]=creat_DFS_tree(gra[total[i].p1],total[i].p2);
	root=(Pgraph)malloc(sizeof(graph));
	root=search(gra[0]);
	for(int i=0;i<DFS;i++) printf("%d",DFS_undeleted[i]);
}
int comp(const void *a,const void *b){
	Point x,y;
	x=(Point)a; y=(Point)b;
	int ans;
	ans=x->p1-y->p1;
	if(ans==0) return x->p2 - y->p2;
	else return ans;
}
Pgraph creat_DFS_tree(Pgraph p,int a){
	if(p==NULL){
		p=(Pgraph)malloc(sizeof(graph));
		p->pos=a;
		p->ischeaked=-1;
		p->link=NULL;
	}
	else p->link=creat_DFS_tree(p->link,a);
	return p;
}
Pgraph search(Pgraph a){
	while(a!=NULL){
		if(a->ischeaked!=1){
			printf("%d",a->pos);
			a->ischeaked=1;
			a->link=search(gra[a->link->pos]);
			a=a->link;			
		}
		else do{
			if(a->link!=NULL) a=a->link;
			else return a;
		}while(a->link->ischeaked!=1);
	}
	return a;
}*/
#include<stdio.h>
#include<stdlib.h>

int gra[102][102];
int isread[102]={0};
int vterx,edge;
int del;
int BFS_num=0;
int num=0;
int BFS_order[102]={0};
int BFS_gra[102][102],DFS_gra[102][102];


void DFS(int a);
void BFS(int a);
int main(){
	int x,y;
	scanf("%d %d",&vterx,&edge);
	for(int i=0;i<edge;i++) for(int j=0;j<edge;j++) gra[i][j]=0;
	for(int i=0;i<edge;i++){
		scanf("%d %d",&x,&y);
		gra[x][y]=gra[y][x]=1;
	}
	for(int i=0;i<edge;i++) for(int j=0;j<edge;j++) DFS_gra[i][j]=gra[i][j];
	for(int i=0;i<edge;i++) for(int j=0;j<edge;j++) BFS_gra[i][j]=gra[i][j];
	scanf("%d",&del);
	DFS(0);printf("\n");
	for(int i=0;i<edge;i++) isread[i]=0;
	BFS(0);printf("\n");
	for(int i=0;i<edge;i++) gra[del][i]=gra[i][del]=0;
	for(int i=0;i<edge;i++) for(int j=0;j<edge;j++) DFS_gra[i][j]=gra[i][j];
	for(int i=0;i<edge;i++) for(int j=0;j<edge;j++) BFS_gra[i][j]=gra[i][j];
	for(int i=0;i<edge;i++) isread[i]=BFS_order[i]=0;
	BFS_num=num=0;
	DFS(0);printf("\n");
	for(int i=0;i<edge;i++) isread[i]=0;
	BFS(0);printf("\n");
}
void DFS(int a){
	int i=0;
	if(isread[a]==0){
		printf("%d ",a);
		isread[i]=1;
	}
	for(i=0;i<edge;i++){
		if(DFS_gra[a][i]==1&&isread[i]==0){
			printf("%d ",i);
			DFS_gra[a][i]=0;
			isread[i]=1;
			DFS(i);
		}
	}
}
void BFS(int a){
	int i=0;
	if(isread[a]==0){
		printf("%d ",a);
		isread[i]=1;
		BFS_order[BFS_num]=a;
		BFS_num++;
	}
	for(i=0;i<edge;i++){
		if(BFS_gra[a][i]==1&&isread[i]==0){
			printf("%d ",i);
			BFS_gra[a][i]=0;
			isread[i]=1;
			BFS_order[BFS_num++]=i;
		}
	}
	while(num<edge)
		BFS(BFS_order[++num]);
}



