#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
struct line{
 int x1;
 int y1;
 int x2;
 int y2;
};
struct line LINE[100];
void sort(int n);
int main()
{
 int n,i,j,m=0;
 int tmp=1;
 int count[100]={0},P[100];
 int arr[100]={0};
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d%d%d%d",&LINE[i].x1,&LINE[i].y1,&LINE[i].x2,&LINE[i].y2); 
 }
 sort(n);
 
 for(m=0;m<n;m++)//找出拥有最多相同点的线段 
 {
  i = m;
  for(j=i;j<n;j++)
  {
   if(LINE[i].x2==LINE[j].x1&&LINE[i].y2==LINE[j].y1)
 {
             i=j;
             
             count[m]++;
    }
  }
  
 }

 for(i=0;i<n;i++)
 {
     if(count[i]>tmp)
     {
      tmp=count[i];
     }
    }//得到最多相同点数（即最多连续线段数）
    
 for(i=0;i<n;i++)
 {
  if(count[i]==tmp)
  break;
 }//找到含有最多连续线段中的一条
 
 printf("%d %d %d ",tmp+1,LINE[i].x1,LINE[i].y1);
 return 0; 
}


void sort(int n)
{
 int i,j,flag;
 struct line tmp;
 for(i=0;i<n-1;i++)
 {
  flag=0;
  for(j=0;j<n-1-i;j++)
  {
      if(LINE[j].x1>LINE[j+1].x1)
      {
       tmp=LINE[j];
       LINE[j]=LINE[j+1];
       LINE[j+1]=tmp;
       flag=1;
      }
     }
     if(flag==0)
     break;
    }
}

