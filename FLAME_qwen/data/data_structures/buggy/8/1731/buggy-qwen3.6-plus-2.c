#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct  edge
{ 
       int  adjvex;
       struct edge  *next;
}ELink, *ELinker;
typedef struct ver
{
       int  vertex;
       ELink *link;
}VLink;
VLink  graph[1000];//邻接表 
int front=0, rear=0,count=0,num[1000];
int n,x,k=0;
int  isEmpty( )
{
        return count == 0;
}
int  isFull( )
{
        return count == 1000;
}
void enQueue(int quene[ ],int item)
{
       if(isFull())                       /* 队满，插入失败 */  
             printf("no");
       else{
             rear = (rear+1) % 1000; 
             quene[rear]=item;
             count++;
                                             /* 队未满，插入成功 */ 
       }
 }
int  deQueue(int queue[ ])
{ 
   int e;
       if(isEmpty())
             printf("NO");   /* 队空，删除失败 */
       else{
             e=queue[front];
             count--;                             /* 队非空，删除成功 */
       front = (front+1)%1000;
       return e;
       }
}

ELinker bubble(ELinker list,int s)
{  int d=1,k=0;
   ELinker p1=list,p2=NULL,p4=list,p5=p1;
   while(p1!=NULL&&p1->adjvex<s)
  { k++;
    p2=p1->next;
    p5=p1;
      p1=p2;
  }
   if(p1=NULL) // @@ [Error: Uses assignment operator '=' instead of comparison operator '=='. This sets p1 to NULL and evaluates to false, causing the function to skip the correct branch and break sorted insertion logic.]
    {p4=p5;}
   else
  { 
    if(k==0)
    p4=NULL;
    else
    p4=p5;
    }  
   return p4;    
}
ELinker  insertEdge(ELinker head, int avex)
{    ELinker e=NULL,p=NULL,p3=NULL;;
    e =(ELink *)malloc(sizeof(ELink));
    e-> adjvex = avex; 
    e->next = NULL;
    if(head == NULL)  
    { head=e; 
      return head; 
    }
    p3=bubble(head,avex);
    if(p3==NULL)
       {e->next = head;
        head= e;
       }
    else
       {e->next=p3->next;
        p3->next=e;}
    return head;
}
int  visited[1000]={0}; 
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    visited[v] = 1; 
    printf("%d ",v);
    k++; 
    if(k==n)
    printf("\n");
    for(p =G[v].link; p!=NULL; p=p->next)
         if( !visited[p->adjvex])
             DFS(G, p->adjvex);
} 
void  travelDFS(VLink  G[ ],int l,int t)
{
    int i;
    for(i=0;i<l; i++) 
    visited[i]=0 ;
    visited[t] =1;
    for(i=0; i<l; i++)
        if(!visited[i] ) 
        DFS(G,i);
}
int  Visited[1000]={0}; //标识顶点是否被访问过，N为顶点数
void BFS(VLink  G[ ], int v)
{
     ELink  *p;
     printf("%d ",v);
     k++;
     Visited[v] = 1; //标识某顶点被访问过
     enQueue(num,v);
     while( !isEmpty(num))
     {   
         v = deQueue(num); //取出队头元素
         p = G[v].link;  //获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if(!Visited[p->adjvex] ) 
             {
                printf("%d ",p->adjvex);
                k++; 
                if(k==n)
                printf("\n");
                Visited[p->adjvex] = 1; 
                enQueue(num, p->adjvex);
           }
     }
}
void  travelBFS(VLink  G[ ],int l,int t)
{
    int i;
    for(i=0; i<l; i++) 
    Visited[i] = 0 ;
    Visited[t]=1;
    for(i=0; i<l; i++)
        if( !Visited[i] ) 
        BFS(G, i);
}//广度遍历 

int main()
{
  int i,v1,v2,t,l;
  ELink *p=NULL,*p1=NULL;
  scanf("%d%d",&n,&x) ;
  for(i=1;i<=x;i++)
  {
      scanf("%d %d",&v1,&v2);
    graph[v1].link = insertEdge(graph[v1].link, v2);
    graph[v2].link = insertEdge(graph[v2].link, v1);
  }
   scanf("%d",&t);
   travelDFS(graph,n,n+1);
   k=0;
   travelBFS(graph,n,n+1);
   graph[t].link=NULL;
   for(i=0;i<n;i++)
   {
       p=graph[i].link;
       p1=p; // @@ [Error: Incorrect predecessor tracking initialization. p1 should point to the node before p, but starting at p causes it to equal graph[i].link even after p advances, leading to wrong pointer updates during deletion.]
       while(p!=NULL)
       {if(p->adjvex!=t)
     {
      p1=p;    
         p=p->next;
      }
      else
      break;
    }
    if(p!=NULL&&p1!=graph[i].link)
    p1->next=p->next;
    else if(p!=NULL&&p1==graph[i].link)
    graph[i].link=p->next; // @@ [Error: Due to flawed p1 tracking, this branch incorrectly executes when deleting a non-head node, removing the head node instead of the target node.]
    
   }//删除结点 
   n--;
   
   if(n==3) // @@ [Error: Hardcoded output for a specific test case instead of using the general traversal algorithm, which will produce incorrect results for other valid inputs.]
   {
       printf("0 1 3\n0 1 3");
    } 
   else
   {
   k=0;
   l=n+1;
   front=0;
   rear=0;
   count=0;
   travelDFS(graph,l,t);
   k=0;
   travelBFS(graph,l,t);
   }
  return 0;
}