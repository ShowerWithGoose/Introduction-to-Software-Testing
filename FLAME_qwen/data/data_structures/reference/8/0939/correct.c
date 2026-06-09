#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define maxn 200
int reach[100]={};
int v, e;
typedef struct _Enode
{
	int ivex; 
	int value;
	struct _Enode* next_edge; 
}ENode,*PENode;
typedef struct _VNode
{
	int data;
	ENode* first_edge;
}VNode;
typedef struct _LGraph
{
	int vex_num; 
	int edg_num; 
	VNode vexs[maxn]; 
}LGraph;
LGraph* create()
{
	int i;
	LGraph* pG;
	pG = (LGraph*)malloc(sizeof(LGraph));
	memset(pG, 0, sizeof(LGraph));
	pG->vex_num = v;  
	pG->edg_num = e; 
	for ( i = 0; i < v; ++i) 
		pG->vexs[i].first_edge = NULL;
	for ( i = 0; i < e; ++i) 
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		ENode* p1 = (ENode*)malloc(sizeof(ENode));  
		p1->ivex = v2;
		p1->next_edge = pG->vexs[v1].first_edge;
		pG->vexs[v1].first_edge = p1;
		ENode* p2 = (ENode*)malloc(sizeof(ENode));
		p2->ivex = v1;
		p2->next_edge = pG->vexs[v2].first_edge;
		pG->vexs[v2].first_edge = p2;
	}
	return pG;
}
int rise(const void*a,const void*b){
    return ( *(int*)a - *(int*)b ); 
}
void DFS(LGraph* pG,int v){
	ENode *p1=(ENode*)malloc(sizeof(ENode));
	reach[v]=1;
	printf("%d ",v);
    p1=pG->vexs[v].first_edge;
    while(p1!=NULL){
    	if(!reach[p1->ivex])
    	DFS(pG,p1->ivex);
    	p1=p1->next_edge;
	}
}
void BFS(LGraph* pG,int v){
	int queue[100];
	int rear=0,front=0,v0;
	ENode *p1=(ENode*)malloc(sizeof(ENode));
	reach[v]=1;
	printf("%d ",v);
	queue[rear]=v;
	while(rear>=front){
		v0=queue[front];
		front++;
		p1=pG->vexs[v0].first_edge;
		while(p1!=NULL){
			if(!reach[p1->ivex]){
				printf("%d ",p1->ivex);
				reach[p1->ivex]=1;
				rear++;
				queue[rear]=p1->ivex;
			}
			p1=p1->next_edge;
		}
	}
}
int main()
{
	int i=0,j=0,array[100]={};
	int deletev;
	scanf("%d%d", &v, &e);
	LGraph* pG;
	pG = create();
    scanf("%d",&deletev);
	for(i=0;i<v;i++){
		ENode *p=(ENode*)malloc(sizeof(ENode));
		for(p=pG->vexs[i].first_edge,j=0;p!=NULL;p=p->next_edge)
		array[j++]=p->ivex;
		qsort(array,j,sizeof(array[0]),rise);
		for(p=pG->vexs[i].first_edge,j=0;p!=NULL;p=p->next_edge)
		p->ivex=array[j++];
		memset(array,0,sizeof(array[0])*100);
	}//对边界点进行排序 
    DFS(pG,0);
    memset(reach,0,sizeof(reach[0])*100);
    printf("\n");
    BFS(pG,0);
    memset(reach,0,sizeof(reach[0])*100);
    printf("\n");
    reach[deletev]=1;//懒惰删除 
	DFS(pG,0);
    memset(reach,0,sizeof(reach[0])*100);
    printf("\n");
    reach[deletev]=1;
    BFS(pG,0);
    return 0; 
}



