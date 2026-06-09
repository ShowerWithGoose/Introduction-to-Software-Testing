#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct link{
	int point;
	struct link *next;
}; 

struct link g[105];
struct link g_del[105];
int record_v1[200];
int record_v2[200];
int visit_dfs[105];
int ans_dfs[105];
int visit_bfs[105];
int ans_bfs[105];
int visit_dfs_del[105];
int ans_dfs_del[105];
int visit_bfs_del[105];
int ans_bfs_del[105];

void dfs(struct link g[],int tot,int visit[],int ans[])
{
	for(int i=0;i<tot;i++){
		if(visit[i]==0)
		go_dfs(g,i,visit,ans);
	}
}

void go_dfs(struct link g[],int v,int visit[],int ans[])
{
	ans[0]++;
	ans[ans[0]]=v;
	visit[v]=1;
	struct link *p=NULL;
	for(p=g[v].next;p!=NULL;p=p->next){
		if(visit[p->point]==0)
		go_dfs(g,p->point,visit,ans);
	}
}

void bfs(struct link g[],int tot,int visit[],int ans[])
{
	for(int i=0;i<tot;i++){
		if(visit[i]==0)
		go_bfs(g,i,visit,ans);
	}
}

void go_bfs(struct link g[],int v,int visit[],int ans[])
{
	ans[0]++;
	ans[ans[0]]=v;
	visit[v]=1;
	int q[105];
	memset(q,0,sizeof(q));
	int l=1;int r=0;
	q[++r]=v;
	while(l<=r){
		v=q[l++];
		struct link *p=NULL;
		for(p=g[v].next;p!=NULL;p=p->next){
			if(visit[p->point]==0){
				ans[0]++;
				ans[ans[0]]=p->point;
				visit[p->point]=1;
				q[++r]=p->point;
			}
		}
	}
}

void myprint(int x[])
{
	int len=x[0];
	for(int i=1;i<=len;i++)
	printf("%d ",x[i]);
	printf("\n");
}

struct link insert(struct link g,int num)
{
	struct link *p=NULL;
	struct link *newp=NULL;
	newp=(struct link*)malloc(sizeof(struct link));
	newp->point=num;
	newp->next=NULL;
	for(p=&g;p->next!=NULL&&p->next->point<num;p=p->next)
	;
	if(p->next==NULL)
	p->next=newp;
	else{
		newp->next=p->next;
		p->next=newp;
	}
	return g;
}

int main()
{
	int num_v,num_e;
	scanf("%d%d",&num_v,&num_e);
	for(int i=0;i<num_v;i++){
		g[i].point=i;
		g[i].next=NULL;
	}
	for(int i=1;i<=num_e;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		record_v1[i]=v1;
		record_v2[i]=v2;
	}
	int del_v;
	scanf("%d",&del_v);
	visit_dfs_del[del_v]=1;
	visit_bfs_del[del_v]=1;
	for(int i=1;i<=num_e;i++){
		g[record_v1[i]]=insert(g[record_v1[i]],record_v2[i]);
		g[record_v2[i]]=insert(g[record_v2[i]],record_v1[i]);
	}
	for(int i=1;i<=num_e;i++){
		if(record_v1[i]!=del_v&&record_v2[i]!=del_v){
			g_del[record_v1[i]]=insert(g[record_v1[i]],record_v2[i]);
			g_del[record_v2[i]]=insert(g[record_v2[i]],record_v1[i]);
		}
	}
	dfs(g,num_v,visit_dfs,ans_dfs);
	bfs(g,num_v,visit_bfs,ans_bfs);
	dfs(g_del,num_v-1,visit_dfs_del,ans_dfs_del);
	bfs(g_del,num_v-1,visit_bfs_del,ans_bfs_del);
	myprint(ans_dfs);
	myprint(ans_bfs);
	myprint(ans_dfs_del);
	myprint(ans_bfs_del);
	return 0;
}



