#include<stdio.h>
int operat(int n1,int n2,char op)
{
    if(op=='+')
        return n1+n2;
    else if(op=='-')
        return n1-n2;
    else if(op=='*')
        return n1*n2;
    else if(op=='/')
        return n1/n2;
    else return -1;
}
int main()
{
    char s0[100];
    char s[100];
    int i,j;
    int a1,a2,a3;
    char c,op1,op2,op3;
    gets(s0);

    for(i=0,j=0;s0[i]!='=';i++)
    {
        if(s0[i]!=' ')
            s[j++]=s0[i];
    }
    s[j]='=';                   //利用gets读入表达式并删除空格

    int len=j;j=0;

    a1=0;a2=0;a3=0;
    op1='+';
    while(op1!='=')
    {
        a2=0,a3=0;
      while(s[j]>='0'&&s[j]<='9')
        {a2=a2*10+s[j]-'0';
            j++;
        }
      op2=s[j++];
      while(op2=='*'||op2=='/')
      {
           a3=0;
           while(s[j]>='0'&&s[j]<='9')
        {a3=a3*10+s[j]-'0';
            j++;
        }
      op3=s[j++];

         a2=operat(a2,a3,op2);
         op2=op3;
      }
      if(op1=='+'||op1=='-')
      a1=operat(a1,a2,op1);
         op1=op2;
    }
printf("%d",a1);
return 0;
}

