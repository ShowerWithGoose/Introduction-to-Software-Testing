#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    double d=0;
    char c[1024];
    gets(c); // @@ gets() is removed in C11 standard and causes compilation errors in strict environments; use fgets() instead.
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
                                    d=data[n1-1]/data[n1]; // @@ Performs floating-point division, but problem explicitly requires integer division (truncation towards zero).
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
                                    d=data[n1-1]/data[n1]; // @@ Performs floating-point division, but problem explicitly requires integer division (truncation towards zero).
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
                                    d=data[n1-1]/data[n1]; // @@ Performs floating-point division, but problem explicitly requires integer division (truncation towards zero).
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
                                    d=data[n1-1]/data[n1]; // @@ Performs floating-point division, but problem explicitly requires integer division (truncation towards zero).
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
    printf("%.0f",data[0]); // @@ Uses double type and rounding format, which conflicts with integer division requirement; should use int type and %d format.
    return 0;
}