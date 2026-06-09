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
  for(i=0;i<l2;i++)
  { scanf("%d",&num1[i]); // @@ [Error: This scanf reads from stdin again, but the input has already been read by gets(s1). This will cause incorrect data or wait for new input, and the loop condition i<l2 is based on the string length, not the number of numbers.]
      scanf("%c",&fu[i]); // @@ [Error: Same issue as above; scanf reads from stdin instead of parsing s2. Also, the loop may read beyond the actual number of operators.]
      {if(fu[i]=='=')
       break;
      }
  }
  k=0;
  y=num1[0];
  for(j=0;j<=i;j++)
  { if(j>1)
    {if(fu[j-1]=='+'||fu[j-1]=='-')
    y=num1[j];} // @@ [Error: This logic incorrectly resets y when encountering + or - after the first two elements, but the multiplication/division chain handling is flawed. For example, in "1+2*3", when j=2, fu[1] is '+', so y becomes num1[2]=3, losing the previous product.]
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ [Error: Should be fu[j]=='-' and fu[j]=='=', not fu[i]. This condition is incorrect and will cause wrong operator checks.]
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