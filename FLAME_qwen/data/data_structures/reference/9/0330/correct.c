#include <stdio.h>
#include <string.h>
struct L
{           //线段
 int x1; //起点
 int y1;
 int x2; //终点
 int y2;
 int num; //线段个数
};

int main()
{
 int i = 0, j = 0, n , k = 1, isl = 0, max = 0, res = 0; 
 int Ps[105][5];
 struct L arr[105];
  scanf("%d", &n);
 for (i = 1; i <= n; i++)
 {
   scanf("%d%d%d%d", &Ps[i][1], &Ps[i][2], &Ps[i][3], &Ps[i][4]);
 }
 //找起点
 for (i = 1; i <= n; i++)
 {
  for (j = 1; j <= n; j++)
  {
   if (Ps[i][1] == Ps[j][3] && Ps[i][2] == Ps[j][4])
   {
    isl = 1;
    break;
   }
  }
  if (isl == 0)
  {
   arr[k].x1 = Ps[i][1];
   arr[k].y1 = Ps[i][2];
   arr[k].x2 = Ps[i][3];
   arr[k].y2 = Ps[i][4];
   k++;
  }
  isl = 0;
 }
 //找终点
 for (i = 1; i <= k; i++)
 {
  arr[i].num = 1;
  for (j = 1; j <= n; j++)
  {
   if (arr[i].x2 == Ps[j][1] && arr[i].y2 == Ps[j][2])
   {
    arr[i].x2 = Ps[j][3];
    arr[i].y2 = Ps[j][4];
    arr[i].num++;
    j=0;
   }
  }
 }
 //找最长
 for (i = 1; i <=k; i++)
 {
  if (max < arr[i].num)
  {
   max = arr[i].num;
   res = i;
  }
 }
 printf("%d %d %d\n", arr[res].num, arr[res].x1, arr[res].y1);
 return 0;
}

