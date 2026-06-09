#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    double d=0;
    char c[1024];
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the problem expects integer arithmetic but uses double]
    double data[1024]={0}; // @@ [Should use integers instead of doubles to match integer division requirement]
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
                  for(i=i+1;;i++) // @@ [This loop modifies the outer loop variable 'i', causing skipped characters and incorrect parsing]
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
             if(c[i]==')') // @@ [The problem states there are no parentheses, so this block is unnecessary and causes logic errors]
            {
                if(n2!=-1)
                {
                    for(n2;n2>-1;n2--) // @@ [Incorrect loop syntax: 'for(n2; ...)' doesn't reinitialize or update properly]
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
                                    d=data[n1]+data[n1-1]; // @@ [Operand order is wrong: should be data[n1-1] + data[n1], but more critically, stack order is reversed]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '-':
                                    d=data[n1-1]-data[n1]; // @@ [Correct order for subtraction, but inconsistent with '+' above]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '*':
                                    d=data[n1]*data[n1-1]; // @@ [Operand order reversed: should be data[n1-1] * data[n1]]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1]; // @@ [Correct order for division, but inconsistent with '*' above]
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
                    for(n2;n2>-1;n2--) // @@ [Same incorrect loop syntax; also, this loop pops all higher/equal precedence operators, but logic is flawed due to operand order and double usage]
                    {
                         if(cal[n2]=='*'||cal[n2]=='/')
                              {
                            d=0;
                            switch(cal[n2])
                            {
                                case '*':
                                    d=data[n1]*data[n1-1]; // @@ [Operand order reversed]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1]; // @@ [Correct order, but inconsistent]
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
                else if(c[i]=='(') // @@ [Unnecessary due to problem constraints (no parentheses)]
                {
                    n2++;
                    cal[n2]=c[i];
                }
                else if(c[i]=='+'||c[i]=='-')
                {
                       for(n2;n2>-1;n2--) // @@ [Incorrect loop syntax again]
                    {
                         if(cal[n2]=='*'||cal[n2]=='/')
                              {
                            d=0;
                            switch(cal[n2])
                            {
                                case '*':
                                    d=data[n1]*data[n1-1]; // @@ [Operand order reversed]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1]; // @@ [Correct order, but inconsistent]
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
                                       d=data[n1]+data[n1-1]; // @@ [Operand order reversed]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '-':
                                    d=data[n1-1]-data[n1]; // @@ [Correct order, but inconsistent]
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
                for(n2;n2>-1;n2--) // @@ [Incorrect loop syntax; also processes remaining operators but with inconsistent operand order]
                {
                    d=0;
                    switch(cal[n2])
                            {
                                case '+':
                                    d=data[n1]+data[n1-1]; // @@ [Operand order reversed]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '-':
                                    d=data[n1-1]-data[n1]; // @@ [Correct order, but inconsistent]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '*':
                                    d=data[n1]*data[n1-1]; // @@ [Operand order reversed]
                                    data[n1]=-1;
                                    data[n1-1]=-1;
                                    n1=n1-1;
                                    data[n1]=d;
                                    break;
                                case '/':
                                    d=data[n1-1]/data[n1]; // @@ [Correct order, but inconsistent and uses double division instead of integer]
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
    printf("%.0f",data[0]); // @@ [Uses floating-point formatting; should output integer directly. Also, due to double precision and integer division not enforced, 500/600 becomes 0.833... which rounds to 1 instead of truncating to 0]
    return 0;
}