#include <stdio.h>
#include <string.h>
#define Maxline 105

struct lin
{
  int qix;
  int qiy;
  int zhongx;
  int zhongy;
};
  int count[Maxline];
int main()
{
  int n,i,j,m,imax,max;
  struct lin line[Maxline];
  //输入数据
  scanf("%d",&n); 
  for(i=0;i<n;i++){
    scanf("%d%d%d%d",&line[i].qix,&line[i].qiy,&line[i].zhongx,&line[i].zhongy);
  }
  //比较，找重合
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if((line[i].qix==line[j].zhongx&&line[i].qiy==line[j].zhongy)||(line[i].zhongx==line[j].qix&&line[i].zhongy==line[j].qiy)||(line[i].zhongx==line[j].zhongx&&line[i].zhongy==line[j].zhongy))
      {//没有qidian==qidian的情况，不然连成的线不是真正连接而成的，是一条新的线 
      if(line[i].qix==line[j].zhongx&&line[i].qiy==line[j].zhongy)
      {
        if(line[i].zhongx>line[j].qix)
        {//x小的做起点 
          line[i].qix=line[j].qix;
          line[i].qiy=line[j].qiy;
          line[i].zhongx=line[i].zhongx;
          line[i].zhongy=line[i].zhongy;
        } 
        else
        {
          line[i].qix=line[i].zhongx;
          line[i].qiy=line[i].zhongy;
          line[i].zhongx=line[j].qix;
          line[i].zhongy=line[j].qiy;
        }
        //覆盖,(板子)
       for(m=j;m<n;m++)
       {
         line[m]=line[m+1];
        }
      count[i]++; // @@ [Error: count[i] is incremented but count array is not initialized to 0, leading to undefined behavior. Also, the logic for counting segments is flawed; it should count the number of segments in the chain, not just the number of merges.]
      n--;
      i--;
      j--;
      }
      else if(line[i].zhongx==line[j].qix&&line[i].zhongy==line[j].qiy){
        if(line[i].qix>line[j].zhongx){
          line[i].qix=line[j].zhongx;
          line[i].qiy=line[j].zhongy;
          line[i].zhongx=line[i].qix;
          line[i].zhongy=line[i].qiy;
        }
        else{
          line[i].qix=line[i].qix;
          line[i].qiy=line[i].qiy;
          line[i].zhongx=line[j].zhongx;
          line[i].zhongy=line[j].zhongy;
        }
        //覆盖,(板子)
       for(m=j;m<n;m++){
         line[m]=line[m+1];
        }
       count[i]++; // @@ [Same error as above: count[i] not initialized and counting logic incorrect.]
       n--;
       i--;
       j--;
      }
    }
  }
}    
 //找到线段最多的 
 for(i=0;i<n;i++){
   if(count[i]>count[i+1]){ // @@ [Error: count[i+1] may access out-of-bounds when i = n-1, and count array is not properly initialized, leading to incorrect comparison.]
     imax=i;
     max=count[imax];
   } 
   else{
     imax=i+1;
     max=count[imax];
   }
 }
 printf("%d %d %d\n",max,line[imax].qix,line[imax].qiy);
    return 0;
}