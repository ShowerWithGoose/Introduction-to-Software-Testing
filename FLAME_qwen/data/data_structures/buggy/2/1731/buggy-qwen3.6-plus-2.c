#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,sum=0,y;
  gets(s1); // @@ gets() is unsafe and deprecated; should use fgets() to prevent buffer overflow.
  l1=strlen(s1);
  for(i=0;i<l1;i++)
  {if(s1[i]!=' ')
   {s2[k]=s1[i];
    k++;
   }
  }
  s2[k]='\0';
  l2=strlen(s2);
  for(i=0;i<l2;i++) // @@ Loop bound l2 is string length, not token count; will cause excessive scanf calls.
  { scanf("%d",&num1[i]); // @@ Reads from stdin instead of parsing the pre-stored string s2, causing input mismatch.
      scanf("%c",&fu[i]); // @@ Reads from stdin instead of parsing s2; will incorrectly consume characters.
      {if(fu[i]=='=')
       break;
      }
  }
  k=0;
  y=num1[0];
  for(j=0;j<=i;j++)
  { if(j>1)
    {if(fu[j-1]=='+'||fu[j-1]=='-')
    y=num1[j];}
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ Uses index i instead of j for '-' and '=', causing incorrect condition evaluation.
    {num2[k]=y;
     fu2[k]=fu[j];
     k++;
     }
    if(fu[j]=='*')
    {
       y*=num1[j+1]; // @@ Potential out-of-bounds access when j is the last index; multiplication logic is flawed.
    }
      if(fu[j]=='/')
    {
       y/=num1[j+1]; // @@ Potential out-of-bounds access and incorrect division accumulation logic.
    }
  }
  sum=num2[0];
  for(j=0;j<k;j++)
  {
      if(fu2[j]=='+')
      sum+=num2[j+1];
      if(fu2[j]=='-')
      sum-=num2[j+1];

  }
   printf("%d",sum);
  return 0;
}