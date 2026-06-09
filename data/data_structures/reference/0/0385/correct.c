#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *o = "abcdefghijklmnopqrstuvwxyz";               
char *p = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *q = "0123456789";

int main()
{
  char a[505];
  scanf("%s",a); 
  int len = strlen(a);
  int i;
  for(i=0;i<len;i++)
  {
    if(a[i]>='A'&&a[i]<='Z' || a[i]>='a'&&a[i]<='z' || a[i]>='0'&&a[i]<='9')
    printf("%c",a[i]);
    if(a[i]=='-')
    {
      if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
      {
        char *j;
        int flag = 0;
        for(j = p; j< p + 26; j++)                                                      
        {
            if(*j == a[i+1]) break;
            if(*j == a[i-1]) {flag = 1;continue;}
            if(flag == 1) printf("%c",*j);
        }
      }
      else if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
      {
        char *j;
        int flag = 0;
        for(j = o; j< o + 26; j++)                                                      
        {
            if(*j == a[i+1]) break;
            if(*j == a[i-1]) {flag = 1;continue;}
            if(flag == 1) printf("%c",*j);
        }
      }
      else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
      {
        char *j;
        int flag = 0;
        for(j = q; j< q + 10; j++)                                                      
        {
            if(*j == a[i+1]) break;
            if(*j == a[i-1]) {flag = 1;continue;}
            if(flag == 1) printf("%c",*j);
        }
      }
      else printf("%c",a[i]);
    }
    
    
  }
  return 0;
}
  
  
  
  
  
  
  
  
  

