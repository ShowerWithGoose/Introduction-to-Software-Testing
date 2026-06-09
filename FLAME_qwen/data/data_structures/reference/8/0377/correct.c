#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct edge{//保存边 
	int adjvex;//保存边的另一端在头节点数组中的位置
	struct edge *next;
}Elink; 

typedef struct ver{//保存顶点 
	struct edge *link; 
}Vlink;

Vlink Dot[200];//头节点数组,其数字就是编号 
int dot,side;//顶点和边 
int flag[200]={0};//标记该编号的顶点是否被访问过 

void createGragh();
Elink* insertEdge(Elink *p,int num);//插入 
void DFS(Vlink an[],int num);//num是要访问的顶点编号 ，深度优先 
void BFS(Vlink an[]);//广度优先 

void EnQueue(int q[],int item);
int DeQueue(int q[]);

int main()
{
	scanf("%d %d",&dot,&side);
	createGragh();
	int delect_one;
	scanf("%d",&delect_one);
	DFS(Dot,0);
	printf("\n");
	memset(flag,0,200*sizeof(int));
	BFS(Dot);
	printf("\n");
	memset(flag,0,200*sizeof(int));
	flag[delect_one] = 1;
	DFS(Dot,0);
	printf("\n");
	memset(flag,0,200*sizeof(int));
	flag[delect_one] = 1;
	BFS(Dot);
	printf("\n");
	return 0; 
} 
void createGragh(){	
	int i;
	for(i = 0;i<side;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		Dot[a].link = insertEdge(Dot[a].link,b);
		Dot[b].link = insertEdge(Dot[b].link,a); 
	}
}
Elink* insertEdge(Elink *p,int num){//把元素插入到链表上 
	Elink *list = (Elink *)malloc(sizeof(Elink));//list是保存num的结点//
	list->adjvex = num;
	list->next = NULL; 
	if(p == NULL){//空链表 则list是头 
		return list;
	} 
	Elink *q,*t; 
	for(q = p;q != NULL;t = q,q = q->next){
		if(q->adjvex > num){//升序查找num的位置 
			break;
		}
	}
	if(q == p){//说明就查了第一个  num<头节点 
		list->next = p;
		return list;
	}
	else{
		t->next = list;
		list->next = q;
		return p;//注意返回的Elink都是链表头 
	}
}

void DFS(Vlink an[],int num){
	Elink *p;
	flag[num] = 1;
	printf("%d ",num);
	for(p = an[num].link;p != NULL;p = p->next){ 
		if(flag[p->adjvex] == 0){//该节点没有访问过 
			DFS(an,p->adjvex);//访问该点内容 
		}
	} 
}

int Q[200]={0};
int Front = 0,Rear = 0,Cont = 0;
void BFS(Vlink an[]){
	int i;
	for(i = 0;i<dot;i++){
		if(flag[i] == 0){
			Elink *p;
			flag[i] = 1;
			EnQueue(Q,i);//入队 
			int j=0;
			while(Rear != Front){
				j = DeQueue(Q);//非空就出队 
				printf("%d ",j);
				for(p = an[j].link;p!=NULL;p = p->next){//找到这个队头元素的相邻结点 
				 	if(flag[p->adjvex] == 0){
				 		flag[p->adjvex] = 1;
				 		EnQueue(Q,p->adjvex);
					 } 
				}
			}
		}
	}	
}
void EnQueue(int q[],int item){
	if(Cont == 200){
		printf("队满，插入失败"); 
	}
	else{
		q[Rear] = item;
		Rear = (Rear+1)%200;
		Cont++;
	} 
}
int DeQueue(int q[]){//出队所以要返回值 
	if(Rear == Front){
		printf("队空，删除失败");
		return -1; 
	}
	else{
		int m = q[Front];
		q[Front] = 0;
		Front =(Front+1)%200;
		Cont--;
		return m;
	}
}



