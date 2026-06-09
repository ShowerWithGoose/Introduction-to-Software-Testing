#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
char s[100];
int i,j,k;
int main() 
{ 
 gets(s);
 for(i=0;s[i]!='\0';i++)
{
      k=s[i+1]-s[i-1];
   if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i]=='-')
      for(j=1;j<k;j++)
      printf("%c",s[i-1]+j);
      else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i]=='-')
      for(j=1;j<k;j++)
      printf("%c",s[i-1]+j);
      else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i]=='-')
      for(j=1;j<k;j++)
      printf("%c",s[i-1]+j);
   else
   printf("%c",s[i]);
}
 system("pause");
 return 0; 
}


