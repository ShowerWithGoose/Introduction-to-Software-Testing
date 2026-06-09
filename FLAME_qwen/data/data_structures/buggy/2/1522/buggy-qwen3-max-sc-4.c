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
        {num[b]=(num[b]+s[a]-'0')*10; // @@ [This logic incorrectly builds multi-digit numbers. It assumes only two digits and overwrites `num[b]` instead of accumulating properly (e.g., "123" becomes (0+1)*10=10, then next digit handled separately but index not advanced correctly). Also, `b` is not incremented when reading digits, causing all digits to be stored in `num[0]`.]
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
     cou=cou+1;
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++)
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1]; // @@ [Incorrect operand order and indexing: after parsing, `num` array doesn't align with `fu` because digit parsing didn't increment `b` per number, so `num[c]` and `num[c+1]` are not the correct operands for operator `fu[c]`.]
       num[c]=0;
      fu[c]='+';
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1]; // @@ [Same indexing issue as above; also, integer division is required, but logic fails due to misaligned arrays.]
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
      b=b+token-1; // @@ [Modifying loop variable `b` inside the loop leads to skipping operators or incorrect traversal, especially since `token` logic is flawed.]
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
      b=b+token-1; // @@ [Same issue: manually adjusting loop index `b` causes unpredictable behavior and likely skips parts of the expression.]
      token=0;
      } 
}
   return save;
}