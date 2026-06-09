#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
char s[150];
int i,j,k,m,sum,xsd,xsdq;
int main() 
{ 
 gets(s);
 if(s[0]=='0'&&s[1]=='.')
 {
    sum=1;
    for(i=2;s[i]!='\0';i++)
    {
      if (s[i]=='0')
      {
         sum++;
      }
      else
      {
         break;
      }
    }
    printf("%c",s[i]);
    if(s[i+1]>='1'&&s[i+1]<='9')
    printf(".");
    for(m=i+1;s[m]!='\0';m++)
    printf("%c",s[m]);
    printf("e-");
    printf("%d",sum);
 }
 else
 {
    for(j=0;s[j]!='\0';j++)
    {
       if(s[j]!='.')
       {
          xsdq++;
          xsd++;
       }
       else
       {
          xsd++;
          break;
       }
    }
    if(xsdq==1)
    {
       for(i=0;s[i]!='\0';i++)
       printf("%c",s[i]);
       printf("e0");
    }
    else
    {
       printf("%c",s[0]);
       printf(".");
       for(i=1;s[i]!='\0';i++)
       {
          if(s[i]!='.')
          printf("%c",s[i]);
          else
          continue;
       }
       printf("e%d",xsdq-1);
    }
    
 }
 system("pause");
 return 0; 
}


