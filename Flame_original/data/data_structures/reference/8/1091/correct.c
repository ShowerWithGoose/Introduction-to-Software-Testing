#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <ctype.h>
#define MaxV  256
#define N 200
#define MAXSIZE 100
int  Visited[N]={0}; //标识顶点是否被访问过，N为顶点数
typedef struct  edge{ 
       int  adj;
}Elink;
 int Front = 0,Rear = MAXSIZE-1, Count = 0;
int queue[100];
int graph[200][200];
void  travelDFS(int n);
void  travelBFS(int n);
int deQueue(int queue[ ]);
 void enQueue(int queue[ ],int item);
int  emptyQ(int queue[]);
int dot,line,i=0,j=0,k=0,d=0;
int que[100];
int main()
{
    int a1,a2;
    Elink *p;
    scanf("%d%d",&dot,&line);
    for(i=0;i<line;i++)
    {
        scanf("%d%d",&a1,&a2);
        graph[a1][a2]=1;
        graph[a2][a1]=1;
    }
    travelDFS(0);
    printf("\n");
    for(i=0; i<line; i++) 
        Visited[i] = 0 ;
    travelBFS(0);
    printf("\n");
    scanf("%d",&d);
     for(i=0; i<line; i++) 
        Visited[i] = 0 ;
        Visited[d]=1;
    travelDFS(0);
    printf("\n");
     for(i=0; i<line; i++) 
        Visited[i] = 0 ;
         Visited[d]=1;
    travelBFS(0);
    return 0;
}

void  travelDFS( int n)
{
    int i;
     printf("%d ",n);
      Visited[n]=1;
    for(i=0; i<line; i++)
        if( Visited[i]==0&& graph[n][i]==1)
        {
            travelDFS(i);
        }
}
void  travelBFS(int n)
{
    int i;
    
     enQueue(queue,n);
      while( !emptyQ(queue)){
         n = deQueue(queue);  //取出队头元素
         if(Visited[n]==1)
         continue;
         else
         {
            printf("%d ",n); //访问当前顶点
             Visited[n] = 1; //标识某顶点已入队
              for(i=0; i<line; i++)
                if( Visited[i]==0&& graph[n][i]==1)
                {
                     enQueue(queue,i);
                }
         }
   
      }
}

 void enQueue(int queue[ ],int item)
{

             Rear = (Rear+1) % MAXSIZE; 
             queue[Rear]=item;
             Count++;          /* 队未满，插入成功 */ 
 }
int deQueue(int queue[ ])
{ 
   int e;
             e=queue[Front];
             Count--;                             /* 队非空，删除成功 */
       Front = (Front+1)%MAXSIZE;
       return e;
}
int  emptyQ(int queue[])
{
        return Count == 0;
}

