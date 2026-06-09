#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct  edge{ 
       int  adj;
       int  wei;
       struct edge *next;
}ELink;
typedef struct ver{
       int  vertex;
       ELink  *link;
}VLink;
VLink  G[100];//邻接表数组 
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
   for(p=head; p->next != NULL; p=p->next);    
   p->next = e;
   return head;
}
int juzhen[101][101]={{0}};
int Visited[100]={0};
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1;//访问过 
    printf("%d ", v);
    //VISIT(G, v); //?????
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}

void  travelDFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  //????
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    printf("\n");
}
int  Q[1000];
int  Front, Rear,Count;
void  initQueue(void)
{
    Front = 0;
    Rear =999;
    Count = 0;
}
int  isEmpty(void)
{
    return Count == 0;
}
int  isFull(void)
{
    return Count == 1000;
}
void enQueue(int queue[ ], int item)
{
    if(isFull())                       /* ??,???? */
        printf("Full queue!");
    else{                              /* ???,???? */
        Rear = (Rear+1) % 1000;
        queue[Rear]=item;
        Count++;
    }
}
int  deQueue(int queue[ ])
{
    int e;
    if(isEmpty())                    /* ??,???? */
        printf("Empty queue!");
    else{                            /* ???,???? */
        e=queue[Front];
        Count--;
        Front = (Front+1) % 1000;
        return e;
    }
    return 0;
}


void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    initQueue();  //????
    Visited[v] = 1; //????????
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);  //??????
        printf("%d ",v);
        //VISIT(G, v); //??????
        for(p=G[v].link; p!=NULL; p=p->next ) //????????????
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; //???????
                enQueue(Q, p->adj);
            }
    }
}

void  travelBFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  //????
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");
}
int main() {
  int v_count;
  int e_count; 
  scanf("%d %d",&v_count,&e_count);
  int i=0;
  for(i=0;i<e_count;i++)
  {
  	int v1;
  	int v2;
  	scanf("%d %d",&v1,&v2);
  	juzhen[v1][v2]=1;
  	juzhen[v2][v1]=1; 
   }
   int j=0;
  for(i=0;i<e_count;i++)
  {
  	for(j=0;j<e_count;j++)
  	{
  		if(juzhen[i][j]==1)
  		{
  			G[i].link=insertEdge(G[i].link,j);
		  }
	  }
  } 
  //图插入完毕 
    travelDFS(G,v_count,-1);//不删除 
    travelBFS(G,v_count,-1);//不删除 
    
    int data;
    scanf("%d",&data);//
    travelDFS(G,v_count,data);//深度搜索 
    travelBFS(G,v_count,data);
    
    return 0;
}

