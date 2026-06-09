#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,sum=0,y;
  gets(s1); @@ [gets() is unsafe and deprecated; may cause compilation error with modern compilers due to security concerns]
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
  { scanf("%d",&num1[i]); @@ [Attempting to read integers from input after already reading the entire line with gets(); this will not parse the expression correctly and leads to undefined behavior]
      scanf("%c",&fu[i]); @@ [Same issue: mixing gets() with scanf() causes input stream mismatch; also, fu array indexing assumes one operator per number, but loop logic is flawed]
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
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') @@ [Logical error: uses fu[i] instead of fu[j] in condition, causing incorrect operator checks]
    {num2[k]=y;
     fu2[k]=fu[j];
     k++;
     }
    if(fu[j]=='*')
    {  
       y*=num1[j+1]; @@ [Accesses num1[j+1] without ensuring j+1 is within bounds; also, num1 was never properly filled due to earlier scanf misuse]
    }
      if(fu[j]=='/')
    {  
       y/=num1[j+1]; @@ [Same out-of-bounds and uninitialized data issue as above]
    }
  }
  sum=num2[0];
  for(j=0;j<k;j++)
  {
      if(fu2[j]=='+')
      sum+=num2[j+1]; @@ [Accesses num2[j+1] which may be uninitialized or out of valid range]
      if(fu2[j]=='-')
      sum-=num2[j+1]; @@ [Same issue: potential access beyond initialized elements of num2]
      
  }
   printf("%d",sum);
  return 0;
}