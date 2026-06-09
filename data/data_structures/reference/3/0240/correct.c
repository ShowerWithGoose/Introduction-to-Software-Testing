
#include <stdio.h>
#include <string.h>

int main()
{
 char a[10000];
 int i,k,m=0;
 
 gets(a);
 for(i=0;i<strlen(a);i++)
 {
  if(a[i]=='.')
  break;
 }
 k=i-1;
 
 if(a[0]=='0')
 {
  for(i=2;i<strlen(a);i++)
  {
   if(a[i]!='0')
   {
   m=i;
   break;}
  }
  
  printf("%c",a[m]);
  if(m!=strlen(a)-1)printf(".");
  for(i=m+1;i<strlen(a);i++)
  {
   printf("%c",a[i]);
  }
  printf("e-%d",m-1);
    }
 
 
 else if((k+1>1)||((k+1==1)&&a[0]!=0))
 {
  printf("%c.",a[0]);
  for(i=1;i<strlen(a);i++)
  {
   if(a[i]=='.') 
     continue;
   else
     printf("%c",a[i]);
  }
  printf("e%d",k);
 }
 
 
    return 0; 
}

