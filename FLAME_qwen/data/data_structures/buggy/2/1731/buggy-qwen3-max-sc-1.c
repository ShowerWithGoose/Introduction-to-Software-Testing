#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,sum=0,y;
  gets(s1); @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, the program reads input via gets() but then tries to read again with scanf(), leading to inconsistent input handling.]
  l1=strlen(s1);
  for(i=0;i<l1;i++)
  {if(s1[i]!=' ')
   {s2[k]=s1[i];
    k++;
   }
  }
  s2[k]='\0';
  l2=strlen(s2);
  for(i=0;i<l2;i++)
  { scanf("%d",&num1[i]); @@ [This scanf reads from stdin again, but the input was already consumed by gets(). This causes undefined behavior or waiting for new input, which doesn't exist. The logic should parse numbers and operators from s2, not use scanf after gets().]
      scanf("%c",&fu[i]); @@ [Same issue: trying to read from stdin after using gets(), leading to incorrect parsing. Also, %c reads any character including non-operators, and doesn't skip whitespace properly.]
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
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') @@ [Typo: should be fu[j]=='-' not fu[i]=='-'; using wrong index 'i' instead of 'j' leads to incorrect condition evaluation.]
    {num2[k]=y;
     fu2[k]=fu[j];
     k++;
     }
    if(fu[j]=='*')
    {  
       y*=num1[j+1];    
    }
      if(fu[j]=='/')
    {  
       y/=num1[j+1];    
    }
  }
  sum=num2[0];
  for(j=0;j<k;j++)
  {
      if(fu2[j]=='+')
      sum+=num2[j+1];
      if(fu2[j]=='-')
      sum-=num2[j+1]; @@ [Missing else-if; both '+' and '-' blocks could execute if fu2[j] is '+', but more critically, num2[j+1] may be out of bounds when j == k-1 because num2 has only k elements (indices 0 to k-1), so j+1 accesses invalid memory.]
      
  }
   printf("%d",sum);
  return 0;
}