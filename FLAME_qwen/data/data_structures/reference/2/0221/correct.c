#include<stdio.h>
int main()
{
 int a,b,c;
 char f1,f2,f3;
 a=0;
 f1='+';
 while(f1!='=')
 {
  scanf("%d %c",&b,&f2);
  while(f2 == '*'||f2 == '/')
  {
   scanf("%d %c",&c,&f3);
   if(f2 == '*')
   {
    b=b*c;
   }
   if(f2 == '/')
   {
    b=b/c;
   }
   f2=f3;
  }
  if(f1=='-')
  {
   a=a-b;
  }
  if(f1=='+')
  {
   a=a+b;
  }
  f1=f2;
 }
 printf("%d",a);
 
 
}



