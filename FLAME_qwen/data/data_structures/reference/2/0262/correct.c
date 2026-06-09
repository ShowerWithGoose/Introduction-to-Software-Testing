#include<stdio.h>
#include <string.h> 
#include <math.h> 
int main()
{
 char a[1000]={},c;
 int i=0,j=0,q;
 int s=0,b[1000],x[1005]={0},l=0,o,e;
 for(i=0;i<1005;i++)
 {
  x[i]=0;
 }
 gets(a);
 q=strlen(a);
 for(i=0;i<q;i++)
 {
  if(a[i]==' ')
  {
   for(j=i;j<q;j++)
   a[j]=a[j+1];
   i--;
  }
 }//除去空格 
 for(i=0;a[i]>='0'&&a[i]<='9'&&i<q;i++)
 {
  b[i]=a[i]-'0';l++;
 }
 for(o=0;o<l;o++)
 {
  for(e=0;e<abs(o-l+1);e++)
  b[o]=b[o]*10;
 }
 for(e=0;e<l;e++)
 {
  s=s+b[e];
 }
 a[0]='0';x[0]=s;
 for(j=1;j<q;j++)
 {
  a[j]=a[j+l-1];
  x[j]=x[j+l-1];
 }//将第一个数字转换格式 
 s=0;
 for(i=0;i<q;i++)
 {
  if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
  {
   l=0;
   x[i]=0;
   for(j=i+1;a[j]>='0'&&a[j]<='9'&&j<q;j++)
   {
    b[l]=a[j]-'0';
    l++;
   }
   for(o=0;o<l;o++)
   {
    for(e=0;e<abs(o-l+1);e++)
    b[o]=b[o]*10;
   }
   s=0;
   for(e=0;e<l;e++)
   {
    s=s+b[e];
   }
   a[i+1]='0';x[i+1]=s;
   for(j=i+2;j<q;j++)
   {
    a[j]=a[j+l-1];
   }
   i++;
  }
 }//将之后每一位转换格式 
 for(j=0;j<q;j++)
 {
  
   if(a[j]=='/')
   {
    s=x[j-1]/x[j+1];
    x[j+1]=s;
    x[j]=0;
    x[j-1]=0;
    a[j]='0';
    j++;
   }
   else if(a[j]=='*')
   {
    s=x[j-1]*x[j+1];
    x[j+1]=s;
    x[j]=0;
    x[j-1]=0;
    a[j]='0';
    j++;
   }
 }//依次进行乘除运算 

 int w=0;
 int t;
 for(j=0;j<q;j++)
 {
  if(a[j]=='+')
  {
   for(t=j+1;t<i;t++)
   {
    if(a[t]!='+'&&a[t]!='-')
    {
     w=w+x[t];x[t]=0;
    }
    else t=i;
   }
   x[j+1]=w;w=0;a[j]='0';
  }
  else if(a[j]=='-')
  {
   for(t=j+1;t<i;t++)
   {
    if(a[t]!='+'&&a[t]!='-')
    {
     w=w+x[t];x[t]=0;
    }
    else t=i;
   }
   x[j+1]=0-w;w=0;a[j]='0';
  }
 }//进行加减运算 
 s=0;
 for(i=0;i<q;i++)
 {
  s=s+x[i];
 }//把最后结果依次相加 
 scanf("=");
 printf("%d",s);
 return 0;
 } 



