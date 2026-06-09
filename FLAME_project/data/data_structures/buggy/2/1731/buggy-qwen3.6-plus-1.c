#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,sum=0,y;
  gets(s1);
  l1=strlen(s1);
  for(i=0;i<l1;i++)
  {if(s1[i]!=' ')
   {s2[k]=s1[i];
    k++;
   }
  }
  s2[k]='\0';
  l2=strlen(s2);
  for(i=0;i<l2;i++) // @@ The logic for parsing numbers and operators from the string s2 is completely incorrect. It uses scanf which reads from stdin, not from the string s2. This will cause the program to wait for more input or read garbage, leading to Wrong Answer.
  { scanf("%d",&num1[i]); // @@ Incorrectly attempts to read integer from stdin instead of parsing s2.
      scanf("%c",&fu[i]); // @@ Incorrectly attempts to read char from stdin instead of parsing s2.
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
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ Logic error: uses index 'i' instead of 'j' for checking '-' and '='. Also, the condition structure is flawed for handling operator precedence and accumulation.
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
      sum-=num2[j+1];
      
  }
   printf("%d",sum);
  return 0;
}