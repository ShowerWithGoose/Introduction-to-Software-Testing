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
gets(Shulie); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to a compilation error.]
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
        {num[b]=(num[b]+s[a]-'0')*10; // @@ [This logic incorrectly builds multi-digit numbers. It assumes prior value in `num[b]` is meaningful, but `num[b]` starts at 0 and is only updated once per digit group. For example, "123" would be processed as: '1' → num[b]=1; '2' → num[b]=(1+2)*10=30; '3' → num[b]=(30+3)=33 (but loop doesn't handle third digit properly). Also, `b` is not incremented correctly when parsing numbers.]
        }
     else
        {num[b]=num[b]+s[a]-'0';
        cou--;
        }
       }
    else
     {
     fu[b]=s[a]; // @@ [Operator storage index `b` is incremented here, but number parsing uses same `b` without proper synchronization. This misaligns operators and operands. For instance, after reading a number, `b` should increment only when moving to next number, but here it increments on operator, causing mismatch between `num` and `fu` arrays.]
     b=b+1;
     cou=cou+1;
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++)
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1]; // @@ [After performing multiplication, it sets `num[c]=0` and changes operator to '+', but does not shift the array to maintain correct operand alignment. This breaks subsequent operations because `num[c]` becomes 0 and affects later additions/subtractions.]
       num[c]=0;
      fu[c]='+';
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1]; // @@ [Same issue as multiplication: sets `num[c]=0` and changes operator, but doesn't restructure the expression properly. Also, integer division is used correctly per problem, but operand alignment is broken.]
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
      da=num[c]; // @@ [This loop tries to find next non-zero number, but since earlier steps set some `num` entries to 0 (e.g., after * or /), it skips valid zeros in original expression (like "5 + 0 - 1"). Also, `da` remains 0 if all remaining numbers are zero, causing infinite loop.]
      token=token+1;
      }
      save=save+da;
      da=0;
      b=b+token-1; // @@ [Modifying loop variable `b` inside the loop leads to unpredictable iteration, especially with `token` tracking which is error-prone. This can skip operators or process them multiple times.]
      token=0;
      }
    if(fu[b]=='-')
      {while(da==0)
      {c=c+1;
       da=num[c]; // @@ [Same infinite loop risk if `num[c]` is zero. Also, logic assumes non-zero numbers only.]
       token=token+1;
      }
      save=save-da;
      da=0;
      b=b+token-1; // @@ [Same issue: manually adjusting loop index `b` disrupts for-loop control flow.]
      token=0;
      } 
}
   return save;
}