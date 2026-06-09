#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int visited[105];//确定是否已被访问  
int queue[105];//队列辅助dfs 
typedef struct graphnode{
	int vertex;
	struct graphnode *next;
}node;
node *graph[105];//顶点数组 
int first=0,last=0;
void clean()//清空访问情况 
{
	int i;
	for(i=0;i<105;i++)
	    visited[i]=0;
}
void dfs(int v)//深度优先遍历单个节点探测 
{
    node *p;
	visited[v]=1;
	printf("%d ",v);//输出
	for(p=graph[v];p!=NULL;p=p->next)
	    if(!visited[p->vertex])
		    dfs(p->vertex);	
}
void traveldfs(int point)//深度优先遍历 
{
	int i;
	clean();
	for(i=0;i<point;i++)
	    if(!visited[i]&&graph[i]!=NULL)
	        dfs(i);//探测该节点 
}
void bfs(int v)//广度优先遍历单个节点探测 
{
    node *p;
	visited[v]=1;//标识顶点入队
	queue[last++]=v;
	while(first<last)
	{
	    v=queue[first];
		queue[first++]=0;
	    printf("%d ",v);//输出
		for(p=graph[v];p!=NULL;p=p->next)
		    if(!visited[p->vertex])//输出所有连接节点 
			{
			    visited[p->vertex]=1;
				queue[last++]=p->vertex;	
			} 
	} 
} 
void travelbfs(int point)//广度优先遍历 
{
    int i;
	clean();
	for(i=0;i<point;i++)
	    if(!visited[i]&&graph[i]!=NULL)
		    bfs(i);//探测该节点	
} 
void deletepoint(int number,int point)
{
	node *p,*q=NULL;
	int i;
	for(p=graph[number];p!=NULL;q=p,p=p->next)
	   free(q);
	graph[number]=NULL;
	for(i=0;i<point;i++)
	{
		if(i==number)
		    continue;
	    if(graph[i]->vertex==number)
	        graph[i]=graph[i]->next;
	    else
	    {
		    for(q=p=graph[i];p!=NULL;q=p,p=p->next) 
		        if(p->vertex==number)
		        {
		            q->next=p->next;
		            free(p);
		            break;
		        }
		}
	}
}
int main()
{
	int point=0,line=0,a=0,b=0,deletepoint0=0,i;
	node *q1,*q2,*p,*r;
	scanf("%d%d",&point,&line);//读取顶点和边个数 
	for(i=0;i<line;i++)//储存图 
	{
		scanf("%d%d",&a,&b);
		q1=(node *)malloc(sizeof(node));//创建节点
		q1->vertex=b;
		q1->next=NULL; 
		if(graph[a]==NULL)
		    graph[a]=q1;
		else//确定插入位置 
		{
		    for(p=graph[a];p!=NULL&&p->vertex<b&&p!=NULL;)
		    {
		    	r=p;
		    	if(p!=NULL)
		    	    p=p->next;
			}
		    if(graph[a]->vertex>q1->vertex)
		    {
		    	q1->next=graph[a];
		    	graph[a]=q1;
			}//插入头部
			else
			{
				r->next=q1;
				q1->next=p;
			}//插入中间或尾部
		}
		q2=(node *)malloc(sizeof(node));//创建节点
		q2->vertex=a;
		q2->next=NULL; 
		if(graph[b]==NULL)
		    graph[b]=q2;
		else//确定插入位置 
		{
		    for(p=graph[b];p!=NULL&&p->vertex<a&&p!=NULL;)
		    {
		    	r=p;
		    	if(p!=NULL)
		    	    p=p->next;
			}
		    if(graph[b]->vertex>q2->vertex)
		    {
		    	q2->next=graph[b];
		    	graph[b]=q2;
			}//插入头部
			else
			{
				r->next=q2;
				q2->next=p;
			}//插入中间或尾部
		}
	}
	traveldfs(point);
	printf("\n");
	travelbfs(point);
	printf("\n");
	scanf("%d",&deletepoint0);
	deletepoint(deletepoint0,point);
	traveldfs(point);
	printf("\n");
	travelbfs(point);
	printf("\n");
	return 0;
}



