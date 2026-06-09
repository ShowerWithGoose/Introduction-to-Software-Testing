#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int vertex[109][109], Isvertex[109], Queue[109];

void f1(int m, int t)
{
 Isvertex[t] = -1;
 printf("%d ", t);
 int i;
 for (i = 0; i < m; i++)
 {
  if (vertex[t][i] == 1)
  {
   if (Isvertex[i] != -1)
   {
    f1(m, i);
   }
  }
 }
}

void f11(int m)
{
 int i, j;
 for (i = 0; i < m; i++)
  for (j = 0; j < m; j++)
   if (vertex[i][j] == 1)
    if (Isvertex[i] != -1)
    {
     f1(m, i);
     break;
    }
 printf("\n");
 return;
}

void f2(int m, int t)
{
 int i, start = 0, end = -1;
 printf("%d ", t);
 Isvertex[t] = -1;
 Queue[++end] = t;
 while (start <= end)
 {
  t = Queue[start++];
  for (i = 0; i < m; i++)
  {
   if (vertex[t][i])
    if (Isvertex[i] != -1)
    {
     printf("%d ", i);
     Isvertex[i] = -1;
     Queue[++end] = i;
    }
  }
 }
 return;
}
void f22(int m)
{
 int i, j;
 for (i = 0; i < m; i++)
 {
  for (j = 0; j < m; j++)
   if (vertex[i][j] == 1)
    if (Isvertex[i] != -1)
    {
     f2(m, i);
     break;
    }
 }
 printf("\n");
 return;
}

int main(void)
{
 int i, j, k, ver, side;
 scanf("%d%d", &ver, &side);
 for (k = 0; k < side; k++)
 {
  scanf("%d %d", &i, &j);
  vertex[i][j] = vertex[j][i] = 1;
 }
 f11(ver);
 memset(Isvertex, 0, sizeof(Isvertex));
 f22(ver);
 int d;
 scanf("%d", &d);
 for (i = 0; i < ver; i++)
 {
  vertex[i][d] = vertex[d][i] = 0;
 }
 memset(Isvertex, 0, sizeof(Isvertex));
 f11(ver);
 memset(Queue, -1, sizeof(Queue));
 memset(Isvertex, 0, sizeof(Isvertex));
 f22(ver);
}

