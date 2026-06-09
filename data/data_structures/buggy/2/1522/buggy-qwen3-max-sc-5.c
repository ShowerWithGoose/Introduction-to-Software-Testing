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
gets(Shulie); // @@ [Using `gets()` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets()` is not available, leading to compilation errors.]
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
        {num[b]=(num[b]+s[a]-'0')*10; // @@ [This logic incorrectly builds multi-digit numbers. It assumes prior value in `num[b]` is meaningful, but `num[b]` starts at 0 and only gets updated once per digit group. For example, "123" becomes ((0+1)*10 + 2)*10 = 120, then next digit is not handled properly because loop skips ahead incorrectly.]
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
     cou=cou+1; // @@ [This increment of `cou` here is logically inconsistent with its earlier use as a count of operators/symbols. It corrupts the intended purpose of `cou` as a counter for remaining numbers to parse.]
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++)
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1];
       num[c]=0;
      fu[c]='+'; // @@ [Changing '*' to '+' after processing breaks expression structure if later passes rely on original operators. Also, this approach doesn't correctly handle operator precedence across the whole expression due to in-place modification without proper re-indexing.]
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1]; // @@ [Division uses current `num[c]` and `num[c+1]`, but if previous operations zeroed `num[c]`, this yields wrong results. Also, integer division is correct per spec, but operands may be invalid due to earlier parsing errors.]
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
      da=num[c]; // @@ [This loop tries to find next non-zero number, but `num` array may have zeros from earlier operations (e.g., `num[c]=0` after multiplication), causing it to skip valid zeros or get stuck. Also, `da=0` initialization outside loop causes incorrect state reuse across iterations.]
      token=token+1;
      }
      save=save+da;
      da=0;
      b=b+token-1; // @@ [Manually adjusting loop index `b` leads to skipping operators or reprocessing, especially since `token` counts how many zeros were skipped, which doesn't correspond to operator positions.]
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
      b=b+token-1; // @@ [Same issue as above: incorrect index manipulation causes misalignment between operators and operands.]
      token=0;
      } 
}
   return save;
}