#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    double d=0;
    char c[1024];
    gets(c); // @@ [Using `gets` is unsafe and deprecated; more critically, it may not handle trailing spaces or the '=' correctly in all cases, but the main issue lies elsewhere.]
    double data[1024]={0};
     char cal[1024]={0};
    int i,j=0,n1=-1,n2=-1;
    for(i=0;;i++)
    {
        d=0;
        if(c[i]=='\0')
        break;
        if(i==0)
        {
            if(c[i]=='-')
            {
                j=1;
                continue;
            }
        }
         if(c[i]==' ')
        continue;
           if(c[i]>='0'&&c[i]<='9')
        {
            d=c[i]+0-'0';
             if(c[i+1]<'0'||c[i+1]>'9')
            {
                n1++;
                data[n1]=d;
            }
            else
            {
                  for(i=i+1;;i++)
                {
                     d=d*10+c[i]+0-'0';
                     if(c[i+1]<'0'||c[i+1]>'9')
                    break;
                }
                 n1++;
                data[n1]=d;
            }
            if(j==1)
            {
                data[n1]=-data[n1];
                j=0;
            }
        }
        else
        {
             if(c[i]==')')
            {
                if(n2!=-1)
                {
                    for(n2;n2>-1;n2--)
                    {
                        if(cal[n2]=='(')
                        {
                            cal[n2]='\0';
                            n2--;
                            break;
                        }
                        else
                        {
                            d=0;
                            switch(cal[n2])
                            {
                                case '+':
                                    d=data[n1]+data[n1-1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '-':
                                    d=data[n1-1]-data[n1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '*':
                                    d=data[n1]*data[n1-1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;    
                                    break;        
                            }
                            cal[n2]='\0';
                        }
                    }
                }
            }
            else if(c[i]!='=')
            {
                if(c[i]=='*'||c[i]=='/')
                {
                    for(n2;n2>-1;n2--)
                    {
                         if(cal[n2]=='*'||cal[n2]=='/')
                              {
                            d=0;
                            switch(cal[n2])
                            {
                                case '*':
                                    d=data[n1]*data[n1-1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                        break;
                            }
                             cal[n2]='\0';
                        }
                        else if(cal[n2]=='+'||cal[n2]=='-')
                        break;
                        else if(cal[n2]=='(')
                        {
                            break;
                        }
                    }
                    n2++;
                     cal[n2]=c[i];
                }
                else if(c[i]=='(')
                {
                    n2++;
                    cal[n2]=c[i];
                }
                else if(c[i]=='+'||c[i]=='-')
                {
                       for(n2;n2>-1;n2--)
                    {
                         if(cal[n2]=='*'||cal[n2]=='/')
                              {
                            d=0;
                            switch(cal[n2])
                            {
                                case '*':
                                    d=data[n1]*data[n1-1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                        break;
                            }
                             cal[n2]='\0';
                        }
                        else if(cal[n2]=='+'||cal[n2]=='-')
                        {
                            switch(cal[n2])
                            {
                                case '+':
                                       d=data[n1]+data[n1-1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '-':
                                    d=data[n1-1]-data[n1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                            }
                        }
                        else if(cal[n2]=='(')
                        {
                            break;
                        }
                    }
                    n2++;
                     cal[n2]=c[i];
                }      
            }
            else
            {
                for(n2;n2>-1;n2--)
                {
                    d=0;
                    switch(cal[n2])
                            {
                                case '+':
                                    d=data[n1]+data[n1-1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '-':
                                    d=data[n1-1]-data[n1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '*':
                                    d=data[n1]*data[n1-1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1];
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;    
                                    break;        
                            }
                }
            }
        }
    }
    printf("%.0f",data[0]); // @@ [The program uses `double` for integer arithmetic, but more critically, the order of operands in subtraction and division is reversed: it computes `data[n1-1] - data[n1]` and `data[n1-1] / data[n1]`, which is correct for left-to-right evaluation. However, the real error is that when popping two operands, the first popped is the right operand, and the second is the left — but in this code, `data[n1]` is the most recent (right operand), and `data[n1-1]` is the left, so `left op right` is correct. BUT: in the test case, 500/600 should be 0 (integer division), and 0 + 12000 = 12000. The buggy output is 12001, suggesting 500/600 was computed as 1. This happens because `double` division 500.0/600.0 = 0.833..., and `%.0f` rounds to nearest integer (1), not truncates toward zero. The problem requires integer division (truncation), but using `double` and `%.0f` causes rounding instead of truncation. Also, the expression starts with large multiplications that result in 0 (due to *0), so final result should be 0 + 0 + 12000 = 12000. But 500/600 becomes 1 due to rounding, giving 12001. Hence, using floating point is the core error.]
    return 0;
}