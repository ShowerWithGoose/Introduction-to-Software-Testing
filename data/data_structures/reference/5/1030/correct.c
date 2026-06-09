#include<stdio.h>
typedef struct k{
 int xishu;
 int zhishu;
 int flag;//在合并多项式的时候判断是否用过了 
}xiang;
xiang a[200];//第一个多项式 
xiang b[200];//第二个多项式 
xiang c[200];//得到的多项式 
void quchong(xiang *a,int n);//合并同类项 
void paixu(xiang *a,int n);//按照指数排序（从大到小） 
int main()
{
 int l_a=0,l_b=0;//两个多项式的长度 
 char o='a';
 int m=0;//得到的多项式的长度 
 while(o!='\n'){
  scanf("%d%d%c",&a[l_a].xishu,&a[l_a].zhishu,&o);//这个O就是每次输进去的空格 
  l_a++;
 }
 o='a';
 while(o!='\n'){
  scanf("%d%d%c",&b[l_b].xishu,&b[l_b].zhishu,&o);
  l_b++;
 }
 for(int i=0;i<l_a;i++){//两个多项式相乘 
  for(int j=0;j<l_b;j++){
   c[m].xishu=a[i].xishu*b[j].xishu;
   c[m].zhishu=a[i].zhishu+b[j].zhishu;
   c[m].flag=0;//令所有的flag都为0 
   m++;
  }
 }
 paixu(c,m);//先将得到多项式排序，再合并 
 quchong(c,m);//合并，并且输出 
}
void quchong(xiang *a,int n){
 for(int i=0;i<n;i++){
  if(a[i].flag==0){
   a[i].flag=1;//标记他被用过了 ，1代表他是初始项，其他的项都加到他上面 
   for(int j=i+1;j<n;j++){
    if(a[j].zhishu==a[i].zhishu){//如果指数相等 
     a[j].flag=2;//将后面的项标记为2，代表他是加上去的数，不是初始项 
     a[i].xishu=a[i].xishu+a[j].xishu;     
    }    
   }
  }
  else{
   continue;
  }
 }
 for(int i=0;i<n;i++){
  if(a[i].flag==1){
   printf("%d %d ",a[i].xishu,a[i].zhishu);//只输出初始项 
  }
  }
}
void paixu(xiang *a,int n){//冒泡排序 
 int i,j;
 xiang temp;
 for(i=0;i<n-1;i++){
  for(j=0;j<n-1-i;j++){
   if(a[j].zhishu<a[j+1].zhishu){
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
}

