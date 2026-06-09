#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,sum=0,y;
  gets(s1); // @@ [gets() is unsafe and deprecated; may cause compilation error with modern compilers due to security concerns]
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
  { scanf("%d",&num1[i]); // @@ [This loop uses scanf on a string that has already been read via gets(); it should parse s2 instead of reading new input]
      scanf("%c",&fu[i]); // @@ [Same issue: trying to read from stdin again instead of parsing the already-read expression in s2]
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
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ [Incorrect indexing: uses fu[i] instead of fu[j] in two places, leading to wrong operator checks]
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
      sum-=num2[j+1]; // @@ [Missing else-if causes both '+' and '-' branches to potentially execute if conditions overlap (though unlikely here), but more critically, num2[k] may be uninitialized or out-of-bounds]
      
  }
   printf("%d",sum);
  return 0;
}