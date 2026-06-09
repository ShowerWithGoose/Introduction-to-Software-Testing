#include <stdio.h>
#define Maxline 1005

struct duociangshi1
{
  int coe1;
  int pow1;
};

struct duociangshi2
{
  int coe2;
  int pow2;
};

struct duociangshi3
{
  int coe3;
  int pow3;
};
int main()
{
  char c;
  int i=0,j=0,n1=0,n2=0,m=0,n3=0,p=0;
  struct duociangshi1 shi1[Maxline];//结构体调用 
  struct duociangshi2 shi2[Maxline];
  struct duociangshi3 shi3[Maxline];
  struct duociangshi3 temp;
//读入
    scanf("%d%d%c",&shi1[i].coe1,&shi1[i].pow1,&c);
    i++;
    n1++; 
    while(c!='\n'){
       scanf("%d%d%c",&shi1[i].coe1,&shi1[i].pow1,&c);
       i++;
       n1++;
    } 
    i=0;
    scanf("%d%d%c",&shi2[i].coe2,&shi2[i].pow2,&c);
    i++;
    n2++; 
    while(c!='\n'){
       scanf("%d%d%c",&shi2[i].coe2,&shi2[i].pow2,&c);
       i++;
       n2++;
    }
  //相乘
  for(i=0;i<n1;i++) 
  {
    for(j=0;j<n2;j++)
    {
      shi3[m].coe3=shi1[i].coe1*shi2[j].coe2;
      shi3[m].pow3=shi1[i].pow1+shi2[j].pow2;
      m++;
      n3++;
    } 
  }
  //合并相同指数的
  for(m=0;m<n3;m++)
  {
    for(j=m+1;j<n3;j++)
    {
     if(shi3[m].pow3==shi3[j].pow3)
     {
       shi3[m].coe3=shi3[m].coe3+shi3[j].coe3;
       //覆盖，后压前
       for(p=j;p<n3;p++){
         shi3[p]=shi3[p+1]; // @@ 数组越界：当p=n3-1时，shi3[p+1]访问超出有效范围（索引n3），且覆盖操作后未调整j计数器，导致可能漏合并后续相同指数项。
       } 
       n3--; // @@ 减少项数后未执行j--，使得内循环跳过下一个元素，合并不完整。
     } 
    }
  } 
  //排列
  for(m=0;m<n3;m++)
  {
    for(j=m+1;j<n3;j++)
    {
      if(shi3[j].pow3>shi3[m].pow3)
      {
        shi3[j]=temp; // @@ 错误的交换：第一句将未初始化的temp赋值给shi3[j]，导致原数据丢失。
        shi3[j]=shi3[m]; // @@ 错误的交换：第二句覆盖了第一句的结果，仍然不是正确交换。
        shi3[m]=temp; // @@ 错误的交换：第三句将未初始化的temp赋值给shi3[m]，导致数据损坏。正确交换应为使用临时变量保存，然后交换两值。
      }
    }
  } 
  for(m=0;m<n3;m++){
    printf("%d %d ",shi3[m].coe3,shi3[m].pow3); // @@ 未跳过系数为0的项。根据多项式乘法规范，合并后系数为0的项不应输出。
  }
    return 0;
}