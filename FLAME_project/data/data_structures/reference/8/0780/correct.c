#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

typedef struct EdgeNode
{
	int vertex;
	struct EdgeNode *pNext;
}ENODE,*PENODE;
typedef struct VertexNode
{
	int vertex;
	PENODE pLink;
}VNODE;

VNODE List[MAXN];
int map[MAXN][MAXN],m,n;

void createList(void)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		List[i].pLink=NULL;
		PENODE *p;
		p=&List[i].pLink;
		List[i].vertex=i;
		for(j=0;j<n;j++)
			if(map[i][j])
			{
				*p=(PENODE)malloc(sizeof(ENODE));
				(*p)->pNext=NULL;
				(*p)->vertex=j;
				p=&(*p)->pNext;
			}
	}
}
void DFSvisit(int i,int ifVisit[])
{
	printf("%d ",i);
	ifVisit[i]=1;
	PENODE p=List[i].pLink;
	while(p!=NULL)
	{
		if(!ifVisit[p->vertex])
			DFSvisit(p->vertex,ifVisit);
		p=p->pNext;
	}
}
void DFS(int x)
{
	int ifVisit[MAXN]={0};
	ifVisit[x]=1;
	int i;
	for(i=0;i<n;i++)
		if(!ifVisit[i])
			DFSvisit(i,ifVisit);
	printf("\n");
}
void BFS(int x)
{
	int ifVisit[MAXN]={0};
	ifVisit[x]=1;
	int queue[MAXN];
	int head=0,tail=1;
	ifVisit[0]=1;
	queue[0]=0;
	printf("0 ");
	while(head!=tail)
	{
		int i=queue[head++];
		PENODE p=List[i].pLink;
		while(p!=NULL)
		{
			if(!ifVisit[p->vertex])
			{
				printf("%d ",p->vertex);
				ifVisit[p->vertex]=1;
				queue[tail++]=p->vertex;
			}
			p=p->pNext;
		}
	}
	printf("\n");
}
void clear(int i)
{
	PENODE p=List[i].pLink;
	while(p!=NULL)
	{
		PENODE q=p->pNext;
		free(p);
		p=q;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
	}
	createList();
	DFS(MAXN-1);
	BFS(MAXN-1);
	int x;
	scanf("%d",&x);
	clear(x);
	DFS(x);
	BFS(x);
//	for(i=0;i<n;i++)
//		clear(i);
	return 0;
}


