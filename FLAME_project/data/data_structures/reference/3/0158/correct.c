#include<stdio.h>
#include<string.h>
int main()
{char s[105];
 gets(s);
 int i,l=strlen(s),n=0,flag=0;
 for(i=0;i<l;i++)
 {if(s[i]=='.')
  n=i;
 }
 if(n==0) 
 {
  printf("%c.",s[0]);
  for(i=1;i<l;i++)
  printf("%c",s[i]);
  printf("e%d",l-1);
 }
 else
 {if(n==1&&s[0]=='0')
 {for(i=2;i<l;i++)
  {if(s[i]=='0') flag++;
   else break;
  }
  printf("%c",s[i]);
  if(i<l-1) printf(".");
  for(i=i+1;i<l;i++)
  printf("%c",s[i]);
  printf("e-%d",flag+1);
 }
 else
 {printf("%c.",s[0]);
 for(i=1;i<l;i++)
  if(i!=n) printf("%c",s[i]);
  printf("e%d",n-1);
 }
 }
 return 0;
}

