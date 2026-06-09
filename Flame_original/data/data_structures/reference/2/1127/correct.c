#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
int suan(int,int,char);
char fu1,fu2;
int shu1,shu2,shu3,sum;
int main() 
{ 
 scanf("%d",&shu1);
 scanf(" %c",&fu1);
 if(fu1=='=')
   {
     printf("%d",shu1);
   }
 else
 { 
   scanf("%d",&shu2);
   scanf(" %c",&fu2);
   while(fu2!='=')
   {
     if(fu1=='*'||fu1=='/')
     {
      shu1=suan(shu1,shu2,fu1);
      fu1=fu2;
      scanf("%d",&shu2);
      scanf(" %c",&fu2);
     }
     else
     {
      scanf("%d",&shu3);
      if(fu2=='+'||fu2=='-')
      {
        shu1=suan(shu1,shu2,fu1);
        shu2=shu3;
        fu1=fu2;
        scanf(" %c",&fu2);
      }
      else
      {
        shu2=suan(shu2,shu3,fu2);
        scanf(" %c",&fu2);
      }
     }  
   }
   sum=suan(shu1,shu2,fu1);
     printf("%d",sum);    
 }
 system("pause");
 return 0; 
}

int suan(int p,int q,char c)
{
  int re;
  if(c=='+')
  re=p+q;
  else if(c=='-')
  re=p-q;
  else if(c=='*')
  re=p*q;
  else if(c=='/')
  re=p/q;
  return re;
}



