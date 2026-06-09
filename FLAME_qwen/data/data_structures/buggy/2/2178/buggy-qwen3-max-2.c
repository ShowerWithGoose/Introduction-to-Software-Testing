#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [Using `gets()` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use `fgets()` instead.]
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa);
    for(int i=0,n=0;i<w;n++,i+=2) // @@ [The loop increment `i+=2` assumes tokens alternate strictly between number and operator, but parsing logic inside doesn't align with this assumption, leading to incorrect parsing and potential out-of-bounds access.]
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ [`sscanf(aa, "%d%c", ...)` always reads from the start of `aa`, not from the current position `i`. This causes repeated parsing of the same prefix and incorrect tokenization.]
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [Using `pow(10, u)` (a floating-point function) to compute digit count is error-prone due to precision issues and inefficient. Also, `u` may overflow or behave unexpectedly.]
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ [This shifting logic `aa[k]=aa[k+1+u]` is flawed: it modifies the input buffer during parsing in a way that doesn't correctly advance the parse position, leading to corrupted or skipped tokens.]
        {
            aa[k]=aa[k+1+u];
        }
    }
    w=strlen(c);
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1]; // @@ [This overwrites `b[i+1]` but leaves `b[i]` as 0, which breaks subsequent operations if there are consecutive * or / operators (e.g., 2*3*4).]
            b[i]=0;
            if(i==0||c[i-1]=='+')
            c[i]='+'; // @@ [Modifying operator `c[i]` to '+' after multiplication is logically incorrect; it conflates operator precedence handling with token mutation, leading to wrong evaluation order.]
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1]; // @@ [Same issue as multiplication: overwrites `b[i+1]` and sets `b[i]=0`, breaking chains like 12/2/2. Also, integer division is correct per spec, but parsing errors may cause wrong operands.]
            b[i]=0;
            if(c[i-1]=='+'||i==0)
            c[i]='+'; // @@ [Same flawed logic as for '*': changing operator symbol doesn't correctly implement precedence and corrupts expression structure.]
            if(c[i-1]=='-')
            c[i]='-';
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