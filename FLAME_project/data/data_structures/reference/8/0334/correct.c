#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1010
int graph[maxn][maxn];//存储
int visit[maxn];//标记结点是否被访问过

void init_graph();//初始化邻接矩阵
void add_edge(int s,int t);//加边
void dfs(int start);//深度优先
void bfs(int start);//广度优先
//采用队列实现广度优先遍历
int queue[maxn];
int front,rear,count;
void init_queue();


int n,m;//n:顶点个数 m:边数

int main()
{
    scanf("%d %d",&n,&m);//输入顶点个数 边数
    int s,t;//s:起始点 t:终点
    int i; 
    memset(graph,0,sizeof(graph));//初始化邻接矩阵
    for(i=0;i<m;i++){
        scanf("%d%d",&s,&t);
        add_edge(s,t);//加边
    }
    int will_del_node;//要删除的结点
    scanf("%d",&will_del_node);
    memset(visit,0,sizeof(visit));//初始化visit数组
    dfs(0);//从0开始进行dfs
    printf("\n");//换行
    bfs(0);//这里对visit数组的初始化包含在bfs函数中
    printf("\n");//换行
    for(i=0;i<n;i++){//将要删除结点的临边标记为0即将边删掉
        graph[will_del_node][i]=0;
        graph[i][will_del_node]=0;
    }
   memset(visit,0,sizeof(visit));
    dfs(0);
    printf("\n");
    bfs(0);
    return 0;
}

void add_edge(int s,int t)//无向图加边
{
    graph[s][t]=1;
    graph[t][s]=1;
}

void dfs(int start)//递归
{
    printf("%d ",start);
    int i;
    visit[start]=1;//标记已经访问过
    for(i=0;i<n;i++){
        if(graph[start][i]&&!visit[i]){//如果有边且没有访问过
            dfs(i);//dfs
        }
    }
}

void bfs(int start)//迭代
{
 int i;
 int tmp;
   memset(visit,0,sizeof(visit));
  for(i=0;i<maxn;i++){
        queue[i]=-1;
    }
    front=0;
    rear=maxn-1;
    count=0;
   
    			tmp=start;
               visit[tmp]=1;
   	 			rear=(rear+1)%maxn;
   				 queue[rear]=tmp;
   				 count++;
    while(count!=0){//只要队列不空
        int temp=queue[front];
    count--;
    front=(front+1)%maxn;
        printf("%d ",temp);//打印
        
        for(i=0;i<n;i++){//将与此结点相连且未访问的结点加入队列
            if(!visit[i]&&graph[i][temp]==1){
            	tmp=i;
               visit[tmp]=1;
   	 			rear=(rear+1)%maxn;
   				 queue[rear]=tmp;
   				 count++;
            }
        }
    }
}




