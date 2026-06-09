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
    printf("%s\n",c);
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
    for(int i=0;i<n;i++) // @@ Error: The loop should iterate over the length of ne, not n, because ne contains the filtered expression without spaces and '=', and its length may be different from n.
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  
        }
        if(isdigit(ne[i+1])) // @@ Error: This logic for building multi-digit numbers is flawed. It adds the digit and then multiplies by 10 on the next iteration, but it does not correctly handle the case where the next character is also a digit; it should multiply before adding the next digit.
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ Error: This assigns the operator from ne[i+1] but i+1 may be out of bounds when i is the last index. Also, it should assign the operator at the current position, not the next one.
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ Error: The loop condition should be i < strlen(fu), not i <= strlen(fu), to avoid accessing fu[strlen(fu)] which is the null terminator.
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ Error: When i=0, fu[i-1] accesses fu[-1], which is out of bounds and causes undefined behavior.
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ Error: Same out-of-bounds issue when i=0. Also, the logic for handling multiplication and division is incorrect; it does not properly evaluate the expression with operator precedence.
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ Error: a[i+1] may be uninitialized or out of bounds if i+1 exceeds the array size.
            }
            else
            {
                chengshu*=a[i+1]; // @@ Error: Same issue with a[i+1] and also the else is attached to the inner if, not the outer if, causing incorrect logic.
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ Error: When i=0, fu[i-1] accesses fu[-1], out of bounds.
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
        for(int i=0;i<=len;i++) // @@ Error: Loop condition should be i < len, not i <= len, to avoid accessing fu[len] which is the null terminator.
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/') // @@ Error: fu[i+1] may be out of bounds when i is the last index.
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ Error: Should use && instead of & for logical AND. Also, fu[i+1] may be out of bounds.
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}