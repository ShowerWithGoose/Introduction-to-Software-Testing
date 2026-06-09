#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define MaxV 256
int del = -1;
void swap(int *p,int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void quick(int k[],int left,int right){
	int i,j;
	int pivot;
	if(left<right){
		i = left;
		j = right+1;
		pivot = k[left];
		while(1){
			while(k[++i]<pivot&&i!=right){
			}
			while(k[--j]>pivot&&j!=left){
			}
			if(i<j){
				swap(&k[i],&k[j]);
			}
			else{
				break;
			}
		}
	swap(&k[left],&k[j]);
	quick(k,left,j-1);
	quick(k,j+1,right);
	}
	
}
void bubbleSort(int k[],int n){
	int i,j,flag = 1;
	int temp;
	for(i = n-1;i>0&&flag==1;i--){
		flag = 0;//若flag==0证明已排序完毕 
		for(j = 0;j<i;j++){
			if(k[j]>k[j+1]){
				temp = k[j];
				k[j] = k[j+1];
				k[j+1] = temp;
				flag = 1;
			}
		}
	}
}
typedef struct edge{
	int adj;
	int wei;
	struct edge *next;
}Elink;
typedef struct ver{
	Elink *link;
}Vlink;
Vlink G[MaxV];

void bubbleSort2(Elink *k[],int n){
	int i,j,flag = 1;
	Elink *temp;
	for(i = n-1;i>0&&flag==1;i--){
		flag = 0;//若flag==0证明已排序完毕 
		for(j = 0;j<i;j++){
			if(k[j]->adj>k[j+1]->adj){
				temp = k[j];
				k[j] = k[j+1];
				k[j+1] = temp;
				flag = 1;
			}
		}
	}
}

Elink *insertEdge(Elink *head,int avex){
	Elink *e,*p;
	e = (Elink *)malloc(sizeof(Elink));
	e->adj = avex;
	e->wei = 1;
	e->next = NULL;
	if(head == NULL){
		head = e;
		return head;
	}
	else{
		for(p = head;p->next!=NULL;p = p->next){
			
		}
		p->next = e;
		return head;
	}
	
}
int Visited[100] = {0};
void travelBFS(Vlink G[],int n){
	int i;
	for(i = 0;i<n;i++){
		Visited[i] = 0;
	}
	for(i = 0;i<n;i++){
		//printf("%d\n",del);
		if(i==del){
			continue;
		}
		if(!Visited[i]&&i!=del){
			BFS(G,i);
		}
	}
}
void BFS(Vlink G[],int v){
	Elink *p;
	int head = 0, tail = 0;
	int head2 = 0, tail2 = 0;
	int que[100];
	int que2[100];
//	printf("%d ",v);
//	Visited[v] = 1;
	p = G[v].link;
	que[tail++] = v;
	while(head<tail){
		v = que[head++];
		if(!Visited[v]&&v!=del){
			printf("%d ",v);
			Visited[v] = 1;
		}
		p = G[v].link;
		tail2 = tail;
		for(;p!=NULL;p = p->next){
//		printf("%d ",p->adj);
			if(!Visited[p->adj]){
			que[tail++] = p->adj;
			}
		}
	
		quick(que,tail2,tail-1);
//		tail2=tail;
//		for(;head<tail2;head++){
//		if(que[head]!=del){
//			
//			if(!Visited[que[head]]){
//				printf("%d ",que[head]);
//				//que[tail++] = G[que[head]].link->adj;
//			}
//			
//		}
//		
//		Visited[que[head]] = 1;
//	}
	}
	
//	for(int i = 0;i<tail;i++){
//		printf("%d ",que[i]);
//	}
//	printf("\n");
	
	
//	while(head<tail){
//		v = que[head++];
//		p = G[v].link;
//		for(;p!=NULL;p = p->next){
//			if(!Visited[p->adj]){
//				que[tail2++]= p->adj;
//				Visited[p->adj] = 1;
//			}
//		}
//		bubbleSort(que2,tail2);	
//		for(int i = 0;i<tail2;i++){
//			if(que2[i]!=del){
//				printf("%d ",que2[i]);
//			}
//		
//		}
//		tail2 = 0;
 //}

}
int Visited2[100] = {0};
void DFS(Vlink G[],int v){
	int que2[100];
	Elink *que[100];
	int head = 0, tail = 0;
	Elink *p;
	if(v!=del){
			printf("%d ",v);
	}

	Visited2[v] = 1;
	for(p = G[v].link;p!=NULL;p = p->next){
		if(!Visited2[p->adj]){
			//printf("here");
			que2[tail++]= p->adj;
			Visited2[p->adj]=0;
		}
	}
//	bubbleSort2(que,tail);
	bubbleSort(que2,tail);
	for(int i = 0;i<tail;i++){
		if(!Visited2[que2[i]]){
				DFS(G,que2[i]);
		}
	
	}
}
void travelDFS(Vlink G[],int n){
	int i;
	for(i = 0;i<n;i++)
	{
		Visited2[i] = 0;
	}
	for(i = 0;i<n;i++){
		if(i==del){
			continue;
		}
		if(!Visited2[i]&&i!=del){
			DFS(G,i);
		}
	}
}

int main()
{
	Vlink graph[100];
	int n1,n2,v1,v2;
	
	scanf("%d %d",&n1,&n2);
	//printf("%d %d\n",n1,n2);
	for(int i = 0;i<n1;i++){
		graph[i].link = NULL;
	}
	for(int i = 0;i<n2;i++){
		scanf("%d %d",&v1,&v2);
		graph[v1].link = insertEdge(graph[v1].link,v2);
		graph[v2].link = insertEdge(graph[v2].link,v1);
	}
//	Elink *p;
//	p = graph[0].link;
//	for(;p!=NULL;p = p->next){
//		printf("%d ",p->adj);
//		}
	travelDFS(graph,n1);
	printf("\n");
	travelBFS(graph,n1);
	printf("\n");
	scanf("%d",&del);
	
	for(int i = 0;i<n1;i++){
		Elink *p;
		if(i == del){
			graph[i].link=NULL;
		}
		else{
			p = graph[i].link;
			for(;p!=NULL;p = p->next){
				if(p->adj==del){
					p = p->next;
					break;
				}
			}
		}
	}
	//printf("%d",del);
	travelDFS(graph,n1);
	printf("\n");
	travelBFS(graph,n1);
	return 0;
}



