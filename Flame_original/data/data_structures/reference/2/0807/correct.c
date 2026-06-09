#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define ll long long
int doing(int n,char a,int m) { //做计算
 if(a=='+')
  return n+m;
 else if(a=='-')
  return n-m;
 if(a=='*')
  return n*m;
 if(a=='/')
  return n/m;
}
char b[500];
int j=0;
void arr(char a[]) { /*去掉空格*/
 int i=0;
 while(a[i]!='\0') {
  if(a[i]!=' ')
   b[j++]=a[i++];
  else
   i = i+1;
 }

}
int main() {
 char a[500];
 int sum=0,e=0,z=1,y,i=1,k=0,d=0,n[500]= {0},op[500]= {0},op1[500]= {0};
 int l=0,c[500];//有效的加减数  
 gets(a);
 arr(a);
 for(i=1; i<=j-3; i++) { /*b数组从0到j-1,第j-1是=号*/
  if(b[i]=='*'||b[i]=='/'||b[i]=='+'||b[i]=='-') {
   op[k++]=i;//保存所有符号在b数组中的位置，op从0到k-1，共k个符号
   if(b[i]=='+'||b[i]=='-')
    op1[e++]=k-1;
  }
 }
 if(k==0) { //只有数字和等于号
  for(i=0; i<j-1; i++) {
   n[0]=10*n[0]+b[i]-'0';
  }
  printf("%d",n[0]);
 } else if(k==1) { //只有一个符号（不算等于号）
  for(i=0; i<op[0]; i++) {
   n[0]=10*n[0]+b[i]-'0';
  }
  for(i=op[0]+1; i<j-1; i++) {
   n[1]=10*n[1]+b[i]-'0';
  }
  printf("%d",doing(n[0],b[op[0]],n[1]));
 }
 if(k>1) { //加减乘除都有
  for(i=0; i<op[0]; i++) {
   n[0]=10*n[0]+b[i]-'0';
  }
  while(z<k) {
   for(i=op[z-1]+1; i<op[z]; i++) {
    n[z]= 10*n[z]+b[i]-'0';

   }
   z++;
  }
  for(i=op[k-1]+1; i<j-1; i++)
   n[k]= 10*n[k]+b[i]-'0';//一共k+1个数字，保存在n下标0到k中
  for(i=0; i<=k; i++) { //从此处开始计算 
   int sum=n[i];
   while(b[op[i]]=='*'||b[op[i]]=='/') {
    sum=doing(sum,b[op[i]],n[i+1]);
    i++;
   }//这里修改了
   c[l]=sum;
   l++;
  }
  int sum=c[0];//加的 
  for(i=0; i<e; i++) {
   sum=doing(sum,b[op[op1[i]]],c[i+1]);//虽然不知道为什么这么写，但我这里尽量按你的思路
  }
//  n[k]=doing(n[op1[i]],b[op1[i]],n[k]);
  printf("%d",sum);
 }
}

