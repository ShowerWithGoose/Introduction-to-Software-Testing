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
gets(Shulie); // @@ [Using `gets()` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets()` is not available, leading to a compilation error.]
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
        {num[b]=(num[b]+s[a]-'0')*10; // @@ [This logic incorrectly builds multi-digit numbers. It assumes prior value in `num[b]` is meaningful, but `num[b]` starts at 0 and is only updated once per digit group. For example, "123" would be processed as: '1' → num[b]=0*10+1? No—it actually does (0+1)*10=10 on first digit if next is digit, then adds next digit without multiplying again properly. This leads to wrong number parsing.]
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
     cou=cou+1; // @@ [This `cou` manipulation is logically inconsistent. `cou` was initially counting operators, but here it's being incremented when encountering an operator during tokenization, breaking the intended use. This causes incorrect control flow in number parsing.]
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++)
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1];
       num[c]=0;
      fu[c]='+'; // @@ [Changing '*' to '+' alters the expression structure but doesn't correctly handle operator precedence in subsequent passes because the algorithm assumes all * and / are resolved, but the index management is flawed. Also, setting `num[c]=0` breaks left-to-right evaluation if there are consecutive operations.]
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1]; // @@ [Division uses `num[c]/num[c+1]`, which is correct mathematically, but if `num[c+1]` is zero, this causes undefined behavior (division by zero). However, problem states expression is valid, so maybe not the issue. Bigger issue: after this, `num[c]` is set to 0, and operator changed to '+', but the shifting of operands is not done—so later addition/subtraction will use wrong indices.]
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
      da=num[c];
      token=token+1;
      }
      save=save+da;
      da=0;
      b=b+token-1; // @@ [Modifying loop variable `b` inside the loop leads to skipping or reprocessing operators. This is error-prone and likely causes incorrect accumulation. The logic with `token` and `da` is convoluted and doesn't correctly map operators to operands after * and / have been "collapsed".]
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
      b=b+token-1; // @@ [Same issue as above: manually adjusting loop index `b` disrupts the for-loop's natural progression, leading to missed or duplicated operations.]
      token=0;
      } 
}
   return save;
}