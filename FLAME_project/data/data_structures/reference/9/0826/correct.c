#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
struct bot{
 int x;
 int y;
}start[200]={},end[200]={};

int main(){
 int n,i,j,k,max=0,flag=0;
 int FLAG[200]={};
 scanf("%d",&n);
 for(i=0;i<n;i++){
  scanf("%d %d %d %d",&start[i].x,&start[i].y,&end[i].x,&end[i].y);
 }
 for(i=0;i<n;i++){
  k=i;
  for(j=0;j<n;j++){
   if(end[i].x==start[j].x&&end[i].y==start[j].y){
    i=j;
    j=-1;
    flag++;
   }
  }
  i=k;
  FLAG[i]=flag;
  flag=0;
 }
 for(i=0;i<n;i++){
  if(FLAG[i]>max){
  max=FLAG[i];
  k=i;
  }
 }
 printf("%d %d %d",FLAG[k]+1,start[k].x,start[k].y);
 return 0; 
}

