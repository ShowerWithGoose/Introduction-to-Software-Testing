#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void fun(char *str)
{int i=0;
    char *p;
    for(p=str;*p!='\0';p++)
    {if(*p!=' ')
    str[i++]=*p;
    }
    str[i]='\0';
    }

int con(char s[]);

int main()
{ char Shulie[5000]={};
gets(Shulie); // @@ [Using `gets()` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to a compilation error.]
int ans;

fun(Shulie);
puts(Shulie);
ans=con(Shulie);
printf("%d",ans);

return 0;
}

int con(char s[])
{ int num[5000]={0};
  char fu[5000]={};
  int save=0;
  int da=0;
  int a=0;
  int b=0,c=0;
  int i;
  int cou=0,cousave,token=0;
  for(a=0;s[a]!='\0';a++)
      {if(s[a]>='0'&&s[a]<='9')
       {;
       }
     else{
     cou=cou+1;
     }     
      }
      cousave=cou;
  for(a=0;s[a]!='\0';a++)
      {if((s[a]>='0'&&s[a]<='9')&&(cou>0))
       {if(s[a+1]>='0'&&s[a+1]<='9')
        {num[b]=(num[b]+s[a]-'0')*10; // @@ [This logic incorrectly builds multi-digit numbers. It assumes only two-digit numbers and overwrites `num[b]` instead of accumulating properly. For example, "123" would be processed as (0+1)*10=10, then next digit handled separately but index may not align.]
        }
     else
        {num[b]=num[b]+s[a]-'0';
        cou--;
        }
       }
    else
     {
     fu[b]=s[a];
     b=b+1;
     cou=cou+1; // @@ [This line increases `cou` when encountering an operator, but `cou` was meant to count operators or digits? The logic for `cou` is inconsistent and corrupts parsing.]
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++)
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1];
       num[c]=0;
      fu[c]='+'; // @@ [Changing '*' to '+' alters the expression structure but doesn't correctly handle operator precedence across the entire array because subsequent '+' processing assumes original positions. Also, this approach fails when multiple * or / are adjacent or mixed.]
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1]; // @@ [Division uses current `num[c]` and `num[c+1]`, but if previous operations zeroed `num[c]`, this yields wrong results. Also, integer division is correct per spec, but operand order and indexing are flawed.]
       num[c]=0;
       fu[c]='+';
       cou=cou-1;
      }
   }
   
   puts(fu);
   save=num[0];
   c=0;
   for(b=0;fu[b]!='=';b++)
   {if(fu[b]=='+')
      {while(da==0)
      { 
      c=c+1;
      da=num[c]; // @@ [This loop tries to skip zeros but breaks if `num[c]` is legitimately zero (e.g., expression contains 0). Also, `da` remains 0 if all remaining numbers are zero, causing infinite loop or incorrect skips.]
      token=token+1;
      }
      save=save+da;
      da=0;
      b=b+token-1; // @@ [Manually adjusting loop variable `b` inside the loop leads to skipped or repeated operators due to interaction with the for-loop increment.]
      token=0;
      }
    if(fu[b]=='-')
      {while(da==0)
      {c=c+1;
       da=num[c];
       token=token+1;
      }
      save=save-da;
      da=0;
      b=b+token-1; // @@ [Same issue: modifying loop index `b` inside loop causes unpredictable iteration behavior.]
      token=0;
      } 
}
   return save;
}