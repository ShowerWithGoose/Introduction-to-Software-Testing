#include <stdio.h>
#include <string.h>
int main()
{
 int i,j,k,l;
 char a[10000], b[10000];
 
 gets(a);
 for(i=0,j=0;i<strlen(a);i++)
 {
  b[j]=a[i];
  j++;
  
  if(a[i+1]=='-')
  {
   if((((a[i]>=48&&a[i]<=57)&&(a[i+2]>=48&&a[i+2]<=57))
   ||((a[i]>=65&&a[i]<=90)&&(a[i+2]>=65&&a[i+2]<=90))
   ||((a[i]>=97&&a[i]<=122)&&(a[i]>=97&&a[i+2]<=122)))&&(a[i+2]-a[i]>0))
      {
          for(k=1;k<a[i+2]-a[i];k++)
       {
        b[j]=a[i]+k;
        j=j+1;
    }
    i=i+1;
   }
      else 
      {
       b[j]=a[i+1];
       i=i+1;
       j++;
    } 
  }
  else 
    continue;
  
 }
 puts(b); 
 return 0;
} 



