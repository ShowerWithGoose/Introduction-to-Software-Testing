#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa);
    for(int i=0,n=0;i<w;n++,i+=2) // @@ [Loop logic is flawed: assumes fixed 2-character steps, but numbers can have variable digits; also modifies `aa` while parsing, leading to incorrect parsing]
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ [`sscanf` reads from start of `aa` every time, not from current position; also `%c` reads any character including digits or '=', causing misparse]
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [Using `pow` (floating-point) for integer digit counting is inefficient and error-prone due to precision issues]
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ [Shifting `aa` by `1+u` is incorrect; `u` is number of digits, but shifting logic doesn't align with actual parsed length]
        {
            aa[k]=aa[k+1+u];
        }
    }
    w=strlen(c);
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1];
            b[i]=0;
            if(i==0||c[i-1]=='+')
            c[i]='+'; // @@ [Modifying operator to '+' after multiplication breaks expression structure; subsequent addition uses wrong operand]
            if(c[i-1]=='-')
            c[i]='-'; // @@ [Same issue: overwriting operator affects later evaluation incorrectly]
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
            b[i]=0;
            if(c[i-1]=='+'||i==0)
            c[i]='+'; // @@ [Same structural flaw as multiplication: operator substitution corrupts expression semantics]
            if(c[i-1]=='-')
            c[i]='-'; // @@ [Same issue]
        }
    }
    int m=b[0];
    for(int i=0;i<w;i++)
    {
        if(c[i]=='+')
        m=m+b[i+1];
        if(c[i]=='-')
        m=m-b[i+1];
    }
    printf("%d",m);
    return 0;
}