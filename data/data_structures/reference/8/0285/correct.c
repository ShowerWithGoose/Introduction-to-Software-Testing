#include<stdio.h>
#include<string.h>


int vertex, edge;
int front, rear;


int graph[105][105];
int visit[105];
int queue[105];


void init_visit()
{
  memset(visit, 0, sizeof(visit));
}


void dfs(int curr)
{
  printf("%d ", curr);
  visit[curr] = 1;
  for(int i = 0; i < vertex; i++)
  {
    if(visit[i] == 0 && graph[curr][i] == 1)
    {
      dfs(i);
    }
  }
}


void init_queue()
{
  front = rear = 0;
  memset(queue, 0, sizeof(queue));
}


void enqueue(int curr)
{
  visit[curr] = 1;
  queue[rear++] = curr;
}


void bfs(int curr)
{
  enqueue(curr);
  while(front < rear)
  {
    int temp = queue[front++];
    printf("%d ", temp);
    for(int i = 0; i < vertex; i++)
    {
      if(visit[i] == 0 && graph[i][temp] == 1)
      {
        enqueue(i);
      }
    }
  }
}


int main()
{
  vertex = 0, edge = 0;  //边的个数，顶点的个数
  int temp1, temp2;

  scanf("%d%d", &vertex, &edge);
  for(int i = 0; i < edge; i++)
  {
    scanf("%d%d", &temp1, &temp2);
    graph[temp1][temp2] = 1;
    graph[temp2][temp1] = 1;
  }

  int del_vertex; //需要删除的顶点
  scanf("%d", &del_vertex);

  dfs(0);
  printf("\n");

  init_visit();
  bfs(0);
  printf("\n");

  for(int i = 0; i < vertex; i++) //删除的顶点所涉及的边
  {
    graph[i][del_vertex] = 0;
    graph[del_vertex][i] = 0;
  }

  init_visit();
  dfs(0);
  printf("\n");

  init_visit();
  init_queue();
  bfs(0);
  printf("\n");

  return 0;
}
