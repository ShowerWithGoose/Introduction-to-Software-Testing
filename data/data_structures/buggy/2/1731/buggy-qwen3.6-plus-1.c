#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,sum=0,y;
  gets(s1); // @@ [gets is removed in C11 standard, causing compilation error in modern environments; use fgets instead]
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
  { scanf("%d",&num1[i]); // @@ [Reads from stdin again instead of parsing the already processed string s2, causing logical error and incorrect input handling]
      scanf("%c",&fu[i]); // @@ [Same as above, should parse characters from s2 rather than calling scanf on stdin]
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
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ [Typo: fu[i] should be fu[j], incorrectly uses index i from previous loop instead of current loop variable j]
    {num2[k]=y;
     fu2[k]=fu[j];
     k++;
     }
    if(fu[j]=='*')
    {
       y*=num1[j+1]; // @@ [Potential array out-of-bounds access when j is the last index, as j+1 exceeds allocated size]
    }
      if(fu[j]=='/')
    {
       y/=num1[j+1]; // @@ [Potential array out-of-bounds access when j is the last index, as j+1 exceeds allocated size]
    }
  }
  sum=num2[0];
  for(j=0;j<k;j++)
  {
      if(fu2[j]=='+')
      sum+=num2[j+1]; // @@ [Array out-of-bounds access when j equals k-1, num2 only contains k valid elements]
      if(fu2[j]=='-')
      sum-=num2[j+1]; // @@ [Array out-of-bounds access when j equals k-1, num2 only contains k valid elements]

  }
   printf("%d",sum);
  return 0;
}