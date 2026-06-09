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
  for(i=0;i<l2;i++) // @@ [Error: This loop uses scanf to read from stdin instead of parsing the already read string s2. The program should extract numbers and operators from s2, not re-read input.]
  { scanf("%d",&num1[i]); // @@ [Error: Reading integer from stdin again. Input has already been read via gets; this will wait for new input or cause mismatch.]
      scanf("%c",&fu[i]); // @@ [Error: Reading operator from stdin again. Should parse from s2.]
      {if(fu[i]=='=') // @@ [Error: The condition compares the just-read operator with '=', but the operator is read from stdin, not from the original expression string s2. The loop may never break as intended.]
       break;
      }
  }
  k=0;
  y=num1[0]; // @@ [Error: num1[0] may be uninitialized if the previous loop read no numbers (e.g., empty input or format error).]
  for(j=0;j<=i;j++) // @@ [Error: Loop bound uses i which is the index after the flawed input loop; i may not correspond to actual number of elements.]
  { if(j>1) // @@ [Error: The condition j>1 is arbitrary and does not correctly reset accumulator y for new terms after + or -.]
    {if(fu[j-1]=='+'||fu[j-1]=='-') // @@ [Error: Accesses fu[j-1] which may be out of bounds or not meaningful due to earlier misreading.]
    y=num1[j];} // @@ [Error: Resets y to num1[j], but num1 array may not have been properly filled.]
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ [Error: Typo: should be fu[j] for the second and third conditions (fu[i] is incorrect). Also logical condition is flawed.]
    {num2[k]=y;
     fu2[k]=fu[j];
     k++;
     }
    if(fu[j]=='*')
    {  
       y*=num1[j+1]; // @@ [Error: Accesses num1[j+1] without bounds check; also the multiplication accumulation does not correctly handle chained * or precedence with +/‑.]
    }
      if(fu[j]=='/')
    {  
       y/=num1[j+1]; // @@ [Error: Same out‑of‑bounds risk and flawed logic as for '*'.]
    }
  }
  sum=num2[0]; // @@ [Error: num2[0] may be uninitialized if no operators were stored; leads to undefined behavior.]
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