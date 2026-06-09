#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char** argv)
{
    char c[5000];
    char ne[5000];
    char fu[5000];
    int a[5000];
    char m;
    int len,n,x,xx,wei,ans=0,chengshu=1;
    x=0;
    xx=0;
    gets(c);
    n=strlen(c);
    printf("%s\n",c); // @@ [Error: This line prints the input expression, which is not required by the problem and may cause output mismatch. The problem expects only the final result to be printed.]
    for(int i=0;i<n;i++)
    {
        if(c[i]==' '||c[i]=='=')
        {
            continue;
        }
        else
        {
            ne[x++]=c[i];
        }
    }
    x=0;
    for(int i=0;i<n;i++) // @@ [Error: The loop should iterate over the length of ne (which is x), not n, because ne contains only the filtered characters. Using n may cause out-of-bounds access or incorrect processing.]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  
        }
        if(isdigit(ne[i+1])) // @@ [Error: This logic for building multi-digit numbers is flawed. It multiplies by 10 for every next digit, but does not handle the case where the current digit is part of a multi-digit number correctly. Also, it uses ne[i+1] which may be out of bounds.]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [Error: This assigns the operator from ne[i+1], but i+1 may be out of bounds or not an operator. Also, it does not correctly separate numbers and operators.]
            xx++;
        }
    }
    len=strlen(fu); // @@ [Error: fu is not null-terminated properly, so strlen may give incorrect length.]
    for(int i=0;i<=strlen(fu);i++) // @@ [Error: Loop condition uses <= strlen(fu), which may cause out-of-bounds access. Also, the logic for handling multiplication/division and addition/subtraction is fundamentally flawed and does not correctly evaluate the expression with operator precedence.]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [Error: Accessing fu[i-1] when i=0 leads to out-of-bounds access.]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-'))
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [Error: a[i+1] may be out of bounds or incorrect index.]
            }
            else
            {
                chengshu*=a[i+1]; // @@ [Error: a[i+1] may be out of bounds or incorrect index.]
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Error: Accessing fu[i-1] when i=0 leads to out-of-bounds access.]
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')
    {
        ans+=a[0];

    }
    {
        for(int i=0;i<=len;i++) // @@ [Error: Loop condition uses <= len, which may cause out-of-bounds access. Also, the logic for handling '+' and '-' is incomplete and does not account for operator precedence correctly.]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Error: Should use '&&' instead of '&' for logical AND. Also, fu[i+1] may be out of bounds.]
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}