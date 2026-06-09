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
  for(i=0;i<l2;i++) // @@ This loop incorrectly attempts to read from stdin again; should parse s2 instead.
  { scanf("%d",&num1[i]); // @@ Reads from stdin, but input has already been stored in s1; causes undefined behavior.
      scanf("%c",&fu[i]); // @@ Same as above; reads from stdin, not from s2.
      {if(fu[i]=='=')
       break;
      }
  }
  k=0;
  y=num1[0];
  for(j=0;j<=i;j++) // @@ i is not guaranteed to be the correct number of operators; loop bounds are unreliable.
  { if(j>1) // @@ Condition should be j>0? Even then logic for handling precedence is incorrect.
    {if(fu[j-1]=='+'||fu[j-1]=='-')
    y=num1[j];}
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ Typo: `fu[i]` should be `fu[j]`; using wrong index leads to incorrect condition.
    {num2[k]=y;
     fu2[k]=fu[j];
     k++;
     }
    if(fu[j]=='*')
    {  
       y*=num1[j+1]; // @@ num1[j+1] may not be properly initialized due to earlier input mistake.
    }
      if(fu[j]=='/')
    {  
       y/=num1[j+1]; // @@ Same issue as above; division may use uninitialized value.
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