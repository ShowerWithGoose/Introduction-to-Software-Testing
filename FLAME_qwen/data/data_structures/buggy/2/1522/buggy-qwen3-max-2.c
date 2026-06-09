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
gets(Shulie); // @@ [Using `gets()` is unsafe and deprecated; it can cause buffer overflow. However, the immediate error in test execution is likely due to environment (gcc not found), but logically this is a flaw. More critically, the parsing logic below has multiple bugs.]
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
      {if((s[a]>='0'&&s[a]<='9')&&(cou>0)) // @@ [This condition `(cou>0)` is incorrect. `cou` counts non-digit characters, but during number parsing, we shouldn't depend on it to decide if we're reading a number. This breaks number extraction.]
       {if(s[a+1]>='0'&&s[a+1]<='9')
        {num[b]=(num[b]+s[a]-'0')*10; // @@ [This logic for multi-digit numbers is flawed. It doesn't accumulate correctly. For example, "123" becomes ((0+1)*10 + 2)*10 = 120, then next digit handled separately incorrectly. Also, `b` is only incremented when encountering an operator, so all digits of a number must be processed before `b` increments—but the control flow doesn't ensure that.]
        }
     else
        {num[b]=num[b]+s[a]-'0';
        cou--; // @@ [Decrementing `cou` here is illogical. `cou` was meant to count operators, but modifying it during digit parsing corrupts its meaning and affects later logic.]
        }
       }
    else
     {
     fu[b]=s[a];
     b=b+1;
     cou=cou+1; // @@ [Incrementing `cou` again here is inconsistent. `cou` was already counting non-digits in the first loop, but now being reused as a dynamic counter, leading to confusion.]
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++) // @@ [The array `fu` may not have '=' at the expected position because the input ends with '=', but the parsing may not have stored it correctly due to earlier errors. Also, if `fu` isn't null-terminated properly, this loop may run out of bounds.]
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1]; // @@ [This overwrites `num[c+1]`, but then sets `num[c]=0` and changes operator to '+'. However, subsequent addition/subtraction pass uses `num[0]` as base and then tries to find next non-zero `num[c]`, which is fragile and incorrect when multiple operations exist.]
       num[c]=0;
      fu[c]='+';
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1]; // @@ [Same issue as multiplication. Also, integer division is required, which is okay, but order of operations is partially handled, yet the data structure update is inconsistent.]
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
      {while(da==0) // @@ [This `while(da==0)` loop is intended to skip zero entries in `num`, but after setting `num[c]=0` for * and /, it assumes non-zero values are valid numbers. However, original numbers could be zero (e.g., "0+1"), causing infinite loop or wrong skips.]
      { 
      c=c+1;
      da=num[c];
      token=token+1;
      }
      save=save+da;
      da=0;
      b=b+token-1; // @@ [Adjusting loop variable `b` inside the loop leads to skipping operators or reprocessing. This is error-prone and likely causes misalignment between `fu` and `num`.]
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
      b=b+token-1; // @@ [Same issue as above: manually adjusting loop index `b` disrupts the for-loop's natural increment, leading to incorrect traversal of operators.]
      token=0;
      } 
}
   return save;
}