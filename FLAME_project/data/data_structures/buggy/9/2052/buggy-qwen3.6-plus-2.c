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
      count[i]++;
      n--;
      i--;
      j--;
      }
      else if(line[i].zhongx==line[j].qix&&line[i].zhongy==line[j].qiy){
        if(line[i].qix>line[j].zhongx){
          line[i].qix=line[j].zhongx;
          line[i].qiy=line[j].zhongy;
          line[i].zhongx=line[i].qix; // @@ Logic error: assigns start x to end x, losing the original end coordinate. Should be line[i].zhongx = line[i].zhongx (no change) or handled differently to extend the segment correctly. Specifically, if merging A->B and B->C, new segment is A->C. Here it sets end to start, creating a point or invalid segment.
          line[i].zhongy=line[i].qiy; // @@ Logic error: assigns start y to end y. Should preserve original end or update to new end depending on logic. In this branch (A->B matches B->C), we want A->C. So start remains A, end becomes C. The code incorrectly overwrites end with start.
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
       count[i]++;
       n--;
       i--;
       j--;
      }
    }
  }
}    
 //找到线段最多的 
 for(i=0;i<n;i++){ // @@ Syntax/Logic error: This loop is outside main() due to the closing brace '}' above. It will cause a compilation error or undefined behavior. The closing brace for the previous for-loop block or main is misplaced.
   if(count[i]>count[i+1]){ // @@ Logic error: Accessing count[i+1] when i can be n-1 leads to out-of-bounds access. Also, the logic for finding max is flawed; it doesn't initialize imax/max properly before the loop.
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