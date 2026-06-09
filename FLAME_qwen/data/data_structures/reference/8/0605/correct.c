#include <stdio.h>
#include <stdlib.h>
int Nv,Ne;
int G[100][100];
int visted[100];
int queue[100];

void DFS(int v);
void BFS(int v);
void newVisted();

int main()
{
    int i,j;
    int v1,v2;
    int delete;
    scanf("%d %d",&Nv,&Ne);
    for(i=0;i<Nv;i++)
       for(j=0;j<Nv;j++){
           G[i][j] = 0;
           G[j][i] = 0;
       }
    for(i=0;i<Ne;i++){
        scanf("%d %d",&v1,&v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    scanf("%d",&delete);
    newVisted();
    DFS(0);
    printf("\n");
    newVisted();
    BFS(0);
    printf("\n");
    newVisted();
    visted[delete] = 1;
    DFS(0);
    printf("\n");
    newVisted();
    visted[delete] = 1;
    BFS(0);
    printf("\n");
    return 0;
}

void DFS(int v)
{   
   int i;
    if(visted[v]==0){
        printf("%d ",v);
        visted[v] = 1;
    }
  for(i=0;i<Nv;i++){
      if(G[v][i]==1&&visted[i]==0){
          DFS(i);
      }
  }
}

void BFS(int v)
{
    int i,j;
    int head = 0;
    int tail = 1;
    int temp;
    queue[head] = v;
    while(head<tail){
      temp = queue[head];
      head++;
      if(visted[temp]==1) continue;
      else{
          printf("%d ",temp);
          visted[temp] = 1;
          for(i=0;i<Nv;i++){
              if(G[temp][i]==1&&visted[i]==0){
                  queue[tail++] = i;
              }
          }
      }
    }
}

void newVisted()
{
    int i;
    for(i=0;i<100;i++) visted[i] = 0;
}





