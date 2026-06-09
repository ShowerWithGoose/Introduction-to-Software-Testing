//邻接矩阵实现
#include <stdio.h>
#include <string.h>
int n_point;        //顶点个数
int n_side;         //边的个数
int edge[120][120]; //存边的关系  //例如edge[1][2]为从顶点1到顶点2
int Visited[120];   //标记某顶点是否被访问过
int delete;         //待删除的顶点编号
int q[120];
int head = 0, tail = 1;
void DFS(int v); //从v开始进行深度搜索
void BFS(int v);

int main()
{
  int i = 0, j = 0;
  int t1, t2;
  scanf("%d%d", &n_point, &n_side);
  for (i = 0; i < n_side; i++)
  {
    scanf("%d%d", &t1, &t2);
    edge[t1][t2] = 1;
    edge[t2][t1] = 1;
  }

  DFS(0); //从0开始
  printf("\n");

  memset(Visited, 0, sizeof(Visited));//初始化不要忘了 
  BFS(0);
  printf("\n");

  scanf("%d", &delete);
  //深度优先搜索
  memset(Visited, 0, sizeof(Visited));
  Visited[delete] = 1; //已访问过 
  DFS(0);
  printf("\n");
  
  memset(Visited, 0, sizeof(Visited));
  Visited[delete] = 1; //已访问过
  BFS(0);
  printf("\n");
  return 0;
}

void DFS(int v)
{
  int j = 0;
  printf("%d ", v);
  Visited[v] = 1;               //标记为已访问
  for (j = 0; j < n_point; j++) //从j=0开始
  {
    if (Visited[j] == 0 && edge[v][j] == 1)//未访问且周围有边
      DFS(j);
  }
}

void BFS(int v)
{
  int i = 0, tmp;
  head=0;
  tail=1;	//队头，队尾，出列的元素 
  q[head] = v;         //入队
  while (head <= tail) //队列访问完毕
  {
    tmp = q[head]; //出队
    head++;        //出队

    if (Visited[tmp]==0)
    {
      printf("%d ", tmp); //打印出队元素
      Visited[tmp] = 1;   //已访问
      for (i = 0; i < n_point; i++)
        if (edge[tmp][i] && !Visited[i])
        {
          q[tail] = i; //入队
          tail++;
        }
    }
  }
}
