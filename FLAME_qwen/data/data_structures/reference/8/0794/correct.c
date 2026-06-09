#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<ctype.h>
#include <string.h>
int n, m, a[200][200];
int vis[200],q[200];
int y;
void bfs(int x);
void dfs(int x);
int main()
{
 scanf("%d%d", &n, &m);
 int i;
 for (i = 1; i <= m; i++)
 {
  int x, y;
  scanf("%d%d", &x, &y);
  a[x][y]=1;
  a[y][x]=1;
 }
 y= 0;
 dfs(0);
 printf("\n");
 memset(vis, 0, sizeof(vis));
 y= 0;
 bfs(0);
 printf("\n");
 scanf("%d", &i);
 vis[i] = 1;
 y= 0;
 dfs(0);
 printf("\n");
 memset(vis, 0, sizeof(vis));
 vis[i] = 1;
 y= 0;
 bfs(0);
 printf("\n");
 return 0;
}
void bfs(int x){
 q[1]=x;

 int l = 1, r = 1, i;
 while (l <= r)
 {
  int x = q[l];
  l++;
  if (vis[x])
   continue;
  if (!y){
   printf("%d", x),
   y = 1;}
  else
   printf(" %d", x);

  vis[x] = 1;
  for (i = 1; i <= n; i++)
   if (a[x][i])
   {
    if (!vis[i])
     q[++r] = i;
   }
 }
 memset(vis, 0, sizeof(vis));
}
void dfs(int x){
 if (!y)
  printf("%d", x), y= 1;
 else
  printf(" %d", x);
 vis[x] = 1;
 int i;
 for (i = 1; i <= n; i++)
  if (a[x][i])
  {
   if (!vis[i])
     dfs(i);

  }
}

