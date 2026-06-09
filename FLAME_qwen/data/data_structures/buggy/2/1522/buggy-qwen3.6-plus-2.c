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
        {num[b]=(num[b]+s[a]-'0')*10; // @@ Incorrect formula for parsing multi-digit numbers. It should be num[b] = num[b] * 10 + (s[a] - '0');
        }
     else
        {num[b]=num[b]+s[a]-'0'; // @@ Fails to multiply the previously accumulated value by 10 before adding the new digit, resulting in incorrect number values.
        cou--;
        }
       }
    else
     {
     fu[b]=s[a]; // @@ Using the same index b for both numbers and operators causes misalignment between the num and fu arrays. They should use independent indices.
     b=b+1;
     cou=cou+1;
     }     
      }
   a=0;
   b=0;
   for(c=0;fu[c]!='=';c++)
   {if(fu[c]=='*')
      {num[c+1]=num[c]*num[c+1];
       num[c]=0;
      fu[c]='+';
      cou=cou-1;
      }
    if(fu[c]=='/')
      {num[c+1]=num[c]/num[c+1];
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
      {while(da==0) // @@ Using da==0 as the loop condition will cause an infinite loop or incorrectly skip valid zero operands. A separate flag or index bound check should be used.
      { 
      c=c+1;
      da=num[c];
      token=token+1;
      }
      save=save+da;
      da=0;
      b=b+token-1;
      token=0;
      }
    if(fu[b]=='-')
      {while(da==0) // @@ Using da==0 as the loop condition will cause an infinite loop or incorrectly skip valid zero operands. A separate flag or index bound check should be used.
      {c=c+1;
       da=num[c];
       token=token+1;
      }
      save=save-da;
      da=0;
      b=b+token-1;
      token=0;
      } 
}
   return save;
}