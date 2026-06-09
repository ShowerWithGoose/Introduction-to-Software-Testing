#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    double d=0;
    char c[1024];
    gets(c);
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
                for(n2;n2>-1;n2--) // @@ The loop condition and decrement logic are flawed. When n2 is decremented in the loop header, it skips operators or accesses invalid indices if not handled correctly with the stack pointer logic used elsewhere. More critically, the loop doesn't update n2 correctly to reflect the popped elements from the 'cal' stack in a way that matches the push/pop logic. The variable n2 acts as a stack pointer. In previous blocks, when an operator is processed, `cal[n2]='\0'` is set but n2 is not explicitly decremented immediately inside the switch, relying on the for-loop decrement. However, here, if the stack has multiple operators, the logic `for(n2;n2>-1;n2--)` will process them. But wait, look at the test case: `... + 500/600 + ...`. `500/600` is integer division. In C, `500/600` with integers is 0. With doubles, it is 0.833. The problem requires integer division. The variables are `double`. `d=data[n1-1]/data[n1]` performs floating point division. `printf("%.0f", data[0])` rounds the result. `12000 + 0.833` is `12000.833`, which rounds to `12001`. The expected output is `12000`. This confirms the error is using `double` instead of `int` for calculation, leading to incorrect rounding instead of truncation (integer division).
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
                                    d=data[n1-1]/data[n1]; // @@ Using double division instead of integer division. The problem requires integer division (truncation). Since data is double, this performs floating point division. Later printf rounds it, causing wrong answer for cases like 500/600 (0.833 -> rounds to 1 instead of truncating to 0).
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
    printf("%.0f",data[0]); // @@ Printing with rounding (%.0f) instead of truncating to integer. Combined with the double division error, this produces the wrong result. Should cast to int or use %d with integer arithmetic.
    return 0;
}