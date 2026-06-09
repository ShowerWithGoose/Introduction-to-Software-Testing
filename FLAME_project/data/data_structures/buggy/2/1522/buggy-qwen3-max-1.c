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
gets(Shulie);
int ans;

fun(Shulie);
puts(Shulie); // @@ [This debug output should not be present as per problem requirements and may interfere with judging]
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
        {num[b]=(num[b]+s[a]-'0')*10; // @@ [Incorrect number parsing: multiplies existing value by 10 even when starting a new number, leading to wrong values like '20' becoming 2*10 + 0 = 20 only if previous was zero, but logic is flawed]
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
     cou=cou+1; // @@ [Incorrectly increments cou here; cou is used inconsistently and breaks parsing logic]
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++)
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1]; // @@ [Performs multiplication but does not handle operator precedence correctly across the whole expression; modifies num[c+1] but leaves num[c] as 0, which later causes issues in addition/subtraction phase]
       num[c]=0;
      fu[c]='+'; // @@ [Changing '*' to '+' alters the operator array but doesn't account for the fact that the next operator might also be * or /, breaking sequential processing]
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1]; // @@ [Same issue as multiplication: integer division is done, but assignment and operator replacement logic is flawed]
       num[c]=0;
       fu[c]='+';
       cou=cou-1;
      }
   }
   
   puts(fu); // @@ [Debug output not required by problem and may cause wrong answer in automated judging]
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
      b=b+token-1; // @@ [Modifying loop variable b inside the loop leads to skipping operators or incorrect indexing]
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
      b=b+token-1; // @@ [Same issue: modifying loop index b causes incorrect traversal of operator array]
      token=0;
      } 
}
   return save;
}