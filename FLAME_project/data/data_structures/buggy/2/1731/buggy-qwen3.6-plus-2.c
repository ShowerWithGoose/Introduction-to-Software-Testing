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
  for(i=0;i<l2;i++) // @@ The logic for parsing numbers and operators from the string s2 is completely missing. The code attempts to use scanf to read from stdin again, which is incorrect as the input has already been read by gets(). Furthermore, even if it were reading from a string, scanf is not suitable here. The variables num1 and fu are not populated correctly from the pre-processed string s2.
  { scanf("%d",&num1[i]); // @@ This line tries to read an integer from standard input, but the input was already consumed by gets(s1). This will likely fail or read garbage/unexpected data, leading to incorrect calculation. It should parse the integer from s2.
      scanf("%c",&fu[i]); // @@ Similarly, this reads a character from standard input instead of parsing the operator from s2. This mismatch causes the subsequent logic to operate on uninitialized or wrong data.
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
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ Logic error: 'fu[i]' is used instead of 'fu[j]'. Also, the condition structure is flawed. It checks for '+' or '-' or '=' to store values, but the accumulation of '*' and '/' results into 'y' and storing them into num2 is handled inconsistently. Specifically, when encountering '+' or '-', the previous accumulated value 'y' (which might have been modified by * or /) needs to be stored. The current logic overwrites y incorrectly or fails to store the result of high-precedence operations properly before moving to low-precedence ones.
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