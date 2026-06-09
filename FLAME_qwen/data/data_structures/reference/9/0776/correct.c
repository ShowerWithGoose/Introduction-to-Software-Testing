#include<stdio.h>

#define MAXN 200

int HAT[MAXN][4]; //单线段坐标
int line[MAXN][5];//0:包含线段数，1、2：头坐标x、y，3，4：尾坐标x、y
int nof; //单线段数 
int num; //连续线段数 
//num[MAXN],int 
int temp[10];
int n,flag1,flag2,mx;
 
int main()
{
 scanf("%d",&n);
 /*输入所有线段坐标*/ 
 for(int i=0;i<n;i++)
 {
  scanf("%d%d%d%d",&HAT[i][0],&HAT[i][1],&HAT[i][2],&HAT[i][3]);
 }
 
 line[0][0]=1;
 line[0][1]=HAT[0][0];
 line[0][2]=HAT[0][1];
 line[0][3]=HAT[0][2];
 line[0][4]=HAT[0][3];
 num = 1;
 
 for(int i = 1;i<n;i++)
 {
  int x1= HAT[i][0]; 
  int y1= HAT[i][1]; 
  int x2= HAT[i][2]; 
  int y2= HAT[i][3]; 

  flag1=0;//头部不连
  flag2=0;//尾部不连 

     int head,tail;
  
  for(int j = 0;j<num;j++)
  {

   if(line[j][0]<0) continue;  //此线段已连接到其它线段 
   if((x1==line[j][3])&&(y1==line[j][4]))  //线段的头和某连续线段的尾相接 
   {
    
    flag1 = 1;      //头部连上 
    head = j;
    if(flag2 == 1)  break; // 如果尾部也连上，则不用再循环了 
   }
   else if((x2==line[j][1])&&(y2==line[j][2]))  //线段的尾和某连续线段的头相接
   {
    flag2 = 1;    //尾部连上 
    tail = j;
    if(flag1 == 1) break; // 如果头部也连上，则不用再循环了 
   }
  }
  
  if(flag1 && flag2) //头和尾分别与已有连续线段相连，需要将两个连续线段通过第i线段连起来，存放到头所在的连续线段 
  {
    line[head][0]=line[head][0]+1+line[tail][0];
    line[head][3]=line[tail][3];    //新的尾 
    line[head][4]=line[tail][4];
    
    line[tail][0] = -1;
  }
  else if(flag1) //头连上，更新尾部坐标 
  {
    line[head][0]++;
    line[head][3]=x2;   // 新的头 
    line[head][4]=y2;

   } 
  else if(flag2) //尾连上，更新头部坐标 
  {
    line[tail][0]++;
    line[tail][1]=x1;   // 新的头 
    line[tail][2]=y1;
   }
   else //开始一条新的连续线段 
  {
   line[num][0]=1;
   line[num][1]=x1;
   line[num][2]=y1;
   line[num][3]=x2;
   line[num][4]=y2;
   num++;
  }
 }
 mx=0;
 for(int i=0;i<num;i++)
 {
  if(line[i][0]>line[mx][0])
  {
   mx=i;
  }
 }
 printf("%d %d %d",line[mx][0],line[mx][1],line[mx][2]);
 return 0;
}

/*思路
1 读入一个数据
2 跟先前存在二维数组1里面的数据进行比对（每个二维数组里面：头坐标，尾坐标）：
  如能连接，则替换头or尾，数组2（存线段个数）+1； 
  如不能，则新开一个（线段个数为1） 
  如果能跟两段线段连上，则都替换 
3找到数组2最大值并输出对应的数组1的头 
*/

