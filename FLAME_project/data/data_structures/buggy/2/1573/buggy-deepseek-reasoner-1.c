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
    printf("%s\n",c); // @@ This prints the input, producing extra output not required. Should only output the result.
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
    for(int i=0;i<n;i++) // @@ Loop condition should use the count of ne elements (x after previous loop) not original length n. Using i<n goes out of bounds for ne.
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  // @@ a[x] is uninitialized (global int but previous loop sets a[?] from global zero? Actually a is global but not zeroed. Also x is being used as index for numbers but then incremented incorrectly. Logic for parsing multi-digit numbers is flawed.
        }
        if(isdigit(ne[i+1]))
        {
            a[x]*=10; // @@ Multiplication before adding next digit, but a[x] not properly initialized. Also accessing ne[i+1] out of bounds when i+1 >= x.
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ Storing operator from ne[i+1] which may be out of bounds. Also fu array not null-terminated.
            xx++;
        }
    }
    len=strlen(fu); // @@ fu array is not null-terminated; strlen will cause undefined behavior.
    for(int i=0;i<=strlen(fu);i++) // @@ Again using strlen on possibly unterminated fu. Also loop condition i<=strlen may cause off-by-one and access out of bounds.
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ Accessing fu[-1] when i=0, out of bounds.
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ i-1 out of bounds for i=0.
            {
            chengshu*=a[i]; // @@ a[i] uses i which is index in fu, not correct index for a.
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ a[i+1] out of bounds; also chengshu starts as 1 but may not be correct.
            }
            else
            {
                chengshu*=a[i+1]; // @@ Same out of bounds issue.
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ i-1 out of bounds when i=0.
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')
    {
        ans+=a[0]; // @@ a[0] may not be the correct first number due to incorrect parsing.

    }
    {
        for(int i=0;i<=len;i++) // @@ len from strlen on unterminated fu; accessing fu[i+1] out of bounds.
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1]; // @@ a[i+1] index may be out of bounds; operator index does not match number index.
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ Single '&' is bitwise, should be '&&'. Also fu[i+1] out of bounds.
            {
                ans-=a[i+1]; // @@ a[i+1] out of bounds.
            }

        }
    }
    printf("%d",ans);
    return 0;
}