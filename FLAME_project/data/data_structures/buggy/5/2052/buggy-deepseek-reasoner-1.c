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
  for(m=0;m<n3;m++) // @@ 当n3减小时，循环条件动态变化，可能导致漏合并或越界；建议改用while循环
  {
    for(j=m+1;j<n3;j++) // @@ 合并移位后未对j进行j--，导致新移到j位置的元素被跳过，可能漏合并
    {
     if(shi3[m].pow3==shi3[j].pow3)
     {
       shi3[m].coe3=shi3[m].coe3+shi3[j].coe3;
       //覆盖，后压前
       for(p=j;p<n3;p++){
         shi3[p]=shi3[p+1];
       } 
       n3--;
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
        shi3[j]=temp; // @@ 错误：应先将shi3[j]保存到temp，再交换；此处直接赋值未初始化temp，导致shi3[j]被覆盖为垃圾值
        shi3[j]=shi3[m]; // @@ 错误：上一行已覆盖shi3[j]，此行将shi3[m]赋给已损坏的shi3[j]，数据丢失
        shi3[m]=temp; // @@ 错误：将未初始化的temp赋给shi3[m]，导致shi3[m]变为未定义值
      }
    }
  } 
  for(m=0;m<n3;m++){
    printf("%d %d ",shi3[m].coe3,shi3[m].pow3);
  }
    return 0;
}