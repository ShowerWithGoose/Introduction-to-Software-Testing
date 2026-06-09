//
//  main.c
//  积极
//
//  Created by  on 2021/10/7.
//
#include <stdio.h>
#include <string.h>
int main()
{
    int x1[100],y1[100],x2[100],y2[100];
    int num[100];
 int i = 0, j = 0, n = 0, k = 0, isl = 0, max = 0, res = 0;
 int Ps[100][4];
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
   scanf("%d%d%d%d", &Ps[i][0], &Ps[i][1], &Ps[i][2], &Ps[i][3]);
 }
 for (i = 0; i < n; i++)
 {
  for (j = 0; j < i; j++)
  {
   if (Ps[i][0] == Ps[j][2] && Ps[i][1] == Ps[j][3])
   {
    isl = 1;
    break;
   }
  }
  if (isl == 0)
  {
   x1[k] = Ps[i][0];
   y1[k] = Ps[i][1];
   x2[k] = Ps[i][2];
   y2[k] = Ps[i][3];
   k++;
  }
  isl = 0;
 }
 for (i = 0; i < k; i++)
 {
  num[i] = 1;
  for (j = 0; j < n; j++)
  {
   if (x2[i] == Ps[j][0] && y2[i] == Ps[j][1])
   {
    x2[i] = Ps[j][2];
    y2[i] = Ps[j][3];
    num[i]++;
    j = -1;
   }
  }
 }
 for (i = 0; i < k; i++)
 {
  if (max < num[i])
  {
   max = num[i];
   res = i;
  }
 }
 printf("%d %d %d", num[res], x1[res], y1[res]);
 return 0;
}

