#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
typedef struct edge *link;
struct edge {
	int to;
	link next;
};
link from[MAXSIZE];
void addedge(int x,int y) {
	link temp,i;
	temp=(link)malloc(sizeof(struct edge));
	temp->next=NULL;
	temp->to=y;
	if(from[x]==NULL) {
		from[x]=temp;
	} else {
		i=from[x];
		if(from[x]->to>y) {
			temp->next=from[x];
			from[x]=temp;
		} else {
			while(i->next!=NULL) {
				if(i->next->to>=y)break;
				i=i->next;
			}
			if(i->next!=NULL) {
				temp->next=i->next;
				i->next=temp;
			} else {
				if(i->to<y)
					i->next=temp;
				else {
					temp->next=i;
					from[x]=temp;
				}
			}
		}

	}
}
void printedge(int x) {
	link i;
	printf("%d:",x);
	i=from[x];
	while(i!=NULL) {
		printf("%d ",i->to);
		i=i->next;
	}
	printf("\n");
}
int n,m,tag[MAXSIZE];
void dfs(int start) {
	link i;
	printf("%d ",start);
	tag[start]=1;
	i=from[start];
	while(i!=NULL) {
		if(tag[i->to]==0)
			dfs(i->to);
		i=i->next;
	}
}
void bfs(int start) {
	int queue[MAXSIZE],rear=0,front=1;
	queue[++rear]=start;
	while(rear>=front) {
		link i;
		printf("%d ",queue[front]);
		tag[queue[front]]=1;
		i=from[queue[front]];
		while(i!=NULL) {
			if(tag[i->to]!=1) {
				queue[++rear]=i->to;
				tag[i->to]=1;
			}
			i=i->next;
		}
		front++;
	}
}
int main() {
	//FILE *IN,*OUT;
	//IN=fopen("","r");
	//OUT=fopen("","w");
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,x,y,delt;
	scanf("%d %d",&n,&m);
	for(i=1; i<=m; i++) {
		scanf("%d %d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	scanf("%d",&delt);
	/*for(i=0; i<n; i++)
		printedge(i);*/
	dfs(0);
	printf("\n");
	for(i=0; i<n; i++)
		tag[i]=0;
	bfs(0);
	printf("\n");
	for(i=0; i<n; i++)
		tag[i]=0;
	tag[delt]=1;
	dfs(0);
	printf("\n");
	for(i=0; i<n; i++)
		tag[i]=0;
	tag[delt]=1;
	bfs(0);
	//fclose(IN);
	//fclose(OUT);
	return 0;
}


