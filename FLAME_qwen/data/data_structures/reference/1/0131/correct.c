#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void x(int *pers, int n)//保存 
{
 int i;
 for(i = 0;i<n; i++)
 {
  printf("%d ", pers[i]);
 }
 printf("\n");
}

int arrange(int *pers, int n, int cur)//递归函数实现 
{
 int i,j ;
 if(cur == n)
 {
  x(pers, n);
 }
 else
 {
  for(i = 1; i <= n; i++)   //每次都是1~n取数，已有数的排除通过内循环剔除
  {
   int ok = 1;
   for(j = 0; j < cur; j++)   //遍历已取数
   {
    if(pers[j] == i)
    {
     ok = 0;
     break;
    }
   }  
   if(ok)
   {
    pers[cur] = i;
    arrange(pers, n, cur + 1);
   } 
  }
 }
}
 
int main()
{
 int N;
 scanf("%d", &N);
 int *pers = (int *)malloc(N * sizeof(int)); //申请一个空间，强制转换一个指定类型的指针 
 arrange(pers, N, 0);
 return 0;
}



