#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isvisit[105];
int n1,n2;//点，边的个数
int d;//删除的顶点
int k1,k2;//输入的两个顶点号
int que[105],rq,fq; 

struct vv{
	int adj;
	struct vv *next;
};
typedef struct vv v,*vptr;
vptr vp[300],vp1,vp2,vp3;

void insertv(int x,int y)
{
	vp1=(vptr)malloc(sizeof(v));
	vp1->next=NULL;
	vp1->adj=y;
	if(vp[x]==NULL)
	{
		vp[x]=vp1;
//		printf("!%d:%d\n\n",x,vp[x]->adj);
		return;
	}
	vp2=vp[x];
	while(vp2!=NULL&&vp2->adj<y)
	{
		vp3=vp2;
		vp2=vp2->next;
	}
	if(vp2==NULL)
	{
		vp3->next=vp1;
//		vptr vpp=vp[x];
/*		printf("!!%d:",x);
		while(vpp!=NULL)
		{
			printf("%d ",vpp->adj);
			vpp=vpp->next;
		}
		printf("\n\n");*/
		return;
	}
	if(vp2->adj==vp[x]->adj)
	{
		vp1->next=vp2;
		vp[x]=vp1;
/*		vptr vpp=vp[x];
		printf("!!!%d:",x);
		while(vpp!=NULL)
		{
			printf("%d ",vpp->adj);
			vpp=vpp->next;
		}
		printf("\n\n");*/
		return;
	}
	vp1->next=vp2;
	vp3->next=vp1;
/*	vptr vpp=vp[x];
		printf("!!!!%d:",x);
		while(vpp!=NULL)
		{
			printf("%d ",vpp->adj);
			vpp=vpp->next;
		}
		printf("\n\n");*/
	return;
}

void dfs(int x)
{
	isvisit[x]=1;
	vptr vpp;
	vpp=vp[x];
	printf("%d ",x);
	while(vpp!=NULL)
	{
		if(isvisit[vpp->adj]==0) dfs(vpp->adj);
		vpp=vpp->next;
	}
//	printf("%d,yes\n",x);
	return;
}

void visitdfs()
{
	for(int i=0;i<n1;i++)
	{
//		printf("%d:\n",i); 
		if(isvisit[i]==0) dfs(i); 
	}
	printf("\n");
	return;
}

void enque(int x)
{
	que[++rq]=x;
	return;
}

int isempty()
{
//	printf("%d\n",rq<fq);
	return rq<fq;
}

int deque()
{
	fq++;
	return que[fq-1];
}

void bfs(int x)
{
	isvisit[x]=1;
	enque(x);
	while(isempty()==0)
	{
		int k=deque();
		printf("%d ",k);
		vptr vpp=vp[k];
		while(vpp!=NULL)
		{
			if(isvisit[vpp->adj]==0)
			{
				isvisit[vpp->adj]=1;
				enque(vpp->adj);
			}
			vpp=vpp->next;
		}
	}
	
}

void visitbfs()
{
	for(int i=0;i<n1;i++)
	{
//		printf("%d:\n",i); 
		if(isvisit[i]==0) bfs(i); 
	}
	printf("\n");
	return;
}

int main()
{
	scanf("%d%d",&n1,&n2);
	for(int i=0;i<n1;i++)
		vp[i]=NULL;
	rq=-1;
	fq=0;
	for(int i=0;i<n2;i++)
	{
		scanf("%d%d",&k1,&k2);
		insertv(k1,k2);
		insertv(k2,k1);
	}
/*	vptr vvp;
	for(int i=0;i<n1;i++)
	{
		printf("%d: ",i);
		vvp=vp[i];
		while(vvp!=NULL)
		{
			printf("%d ",vvp->adj);
			vvp=vvp->next;
		}
		printf("\n");
	}*/
	scanf("%d",&d);
	visitdfs();
	memset(isvisit,0,sizeof(isvisit));
	visitbfs();
	memset(isvisit,0,sizeof(isvisit));
	isvisit[d]=1;
	visitdfs();
	memset(isvisit,0,sizeof(isvisit));
	isvisit[d]=1;
	visitbfs();
	return 0;
} 

