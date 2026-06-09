#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1010
int op[maxn][maxn];//存储
int v[maxn];//标记结点是否被访问过

void init_graph();//初始化邻接矩阵
void add_edge(int a,int b);//加边
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
    int a,b;//s:起始点 t:终点
    int i; 
    memset(op,0,sizeof(op));//初始化邻接矩阵
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        add_edge(a,b);//加边
    }
    int d;//要删除的结点
    scanf("%d",&d);
    memset(v,0,sizeof(v));//初始化visit数组
    dfs(0);//从0开始进行dfs
    printf("\n");//换行
    bfs(0);//这里对visit数组的初始化包含在bfs函数中
    printf("\n");//换行
    for(i=0;i<n;i++){//将要删除结点的临边标记为0即将边删掉
        op[d][i]=0;
        op[i][d]=0;
    }
   memset(v,0,sizeof(v));
    dfs(0);
    printf("\n");
    bfs(0);
    return 0;
}

void add_edge(int a,int b)//无向图加边
{
    op[a][b]=1;
    op[b][a]=1;
}

void dfs(int start)//递归
{
    printf("%d ",start);
    int i;
    v[start]=1;//标记已经访问过
    for(i=0;i<n;i++){
        if(op[start][i]&&!v[i]){//如果有边且没有访问过
            dfs(i);//dfs
        }
    }
}

void bfs(int start)//迭代
{
 int i;
 int tmp;
   memset(v,0,sizeof(v));
  for(i=0;i<maxn;i++){
        queue[i]=-1;
    }
    front=0;
    rear=maxn-1;
    count=0;
   
    			tmp=start;
               v[tmp]=1;
   	 			rear=(rear+1)%maxn;
   				 queue[rear]=tmp;
   				 count++;
    while(count!=0){//只要队列不空
        int temp=queue[front];
    count--;
    front=(front+1)%maxn;
        printf("%d ",temp);//打印
        
        for(i=0;i<n;i++){//将与此结点相连且未访问的结点加入队列
            if(!v[i]&&op[i][temp]==1){
            	tmp=i;
               v[tmp]=1;
   	 			rear=(rear+1)%maxn;
   				 queue[rear]=tmp;
   				 count++;
            }
        }
    }
}




