//给定一个无向图和一个图顶点，编程输出该图删除给定顶点前后按深度优先遍历及广度优先遍历方式遍历的图顶点序列。
//给定的无向图和图顶点满足以下要求：
//1、无向图的顶点个数n大于等于3，小于等于100，输入时顶点编号用整数0～n-1表示；
//2、无向图在删除给定顶点前后都是连通的；
//3、无论何种遍历，都是从编号为0的顶点开始遍历，访问相邻顶点时按照编号从小到大的顺序访问；
//4、删除的顶点编号不为0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1010
int graph[maxn][maxn];//存储
int visit[maxn];//标记结点是否被访问过

void init_visit();//初始化visit数组
void init_graph();//初始化邻接矩阵
void add_edge(int s,int t);//加边
void dfs(int start);//深度优先
void bfs(int start);//广度优先
//采用队列实现广度优先遍历
int queue[maxn];
int front,rear,count;
void init_queue();
int is_empty();
void enqueue(int temp);
int dequeue();

int n,m;//n:顶点个数 m:边数

int main()
{
    scanf("%d %d",&n,&m);//输入顶点个数 边数
    int s,t;//s:起始点 t:终点
    init_graph();//初始化邻接矩阵
    for(int i=0;i<m;i++){
        scanf("%d%d",&s,&t);
        add_edge(s,t);//加边
    }
    int will_del_node;//要删除的结点
    scanf("%d",&will_del_node);
    init_visit();//初始化visit数组
    dfs(0);//从0开始进行dfs
    printf("\n");//换行
    bfs(0);//这里对visit数组的初始化包含在bfs函数中
    printf("\n");//换行
    for(int i=0;i<n;i++){//将要删除结点的临边标记为0即将边删掉
        graph[will_del_node][i]=0;
        graph[i][will_del_node]=0;
    }
    init_visit();
    dfs(0);
    printf("\n");
    bfs(0);
    return 0;
}

void init_graph()
{
    memset(graph,0,sizeof(graph));
}

void add_edge(int s,int t)//无向图加边
{
    graph[s][t]=1;
    graph[t][s]=1;
}

void init_visit()
{
    memset(visit,0,sizeof(visit));
}

void dfs(int start)//递归
{
    printf("%d ",start);
    visit[start]=1;//标记已经访问过
    for(int i=0;i<n;i++){
        if(graph[start][i]&&!visit[i]){//如果有边且没有访问过
            dfs(i);//dfs
        }
    }
}

void bfs(int start)//迭代
{
//特别说明：这里笔者将标记访问的操作写在了入队函数中
    init_visit();//初始化visit数组
    init_queue();//初始化队列
    enqueue(start);//将第一个结点加入队列
    while(!is_empty()){//只要队列不空
        int temp=dequeue();//出队
        printf("%d ",temp);//打印
        for(int i=0;i<n;i++){//将与此结点相连且未访问的结点加入队列
            if(!visit[i]&&graph[i][temp]==1){
                enqueue(i);
            }
        }
    }
}

void init_queue()
{
    for(int i=0;i<maxn;i++){
        queue[i]=-1;
    }
    front=0;
    rear=maxn-1;
    count=0;
}

int is_empty()
{
    return count==0;
}

void enqueue(int temp)
{
    visit[temp]=1;
    rear=(rear+1)%maxn;
    queue[rear]=temp;
    count++;
}

int dequeue()
{
    int temp;
    temp=queue[front];
    count--;
    front=(front+1)%maxn;
    return temp;
}




