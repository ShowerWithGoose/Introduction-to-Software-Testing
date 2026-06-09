#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa);
    for(int i=0,n=0;i<w;n++,i+=2) // @@ [Loop increment logic is flawed: `i+=2` assumes fixed token length, but numbers can have variable digits; also `sscanf` always reads from start of `aa`, not current position]
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ [`sscanf` reads from beginning of `aa` every time, not from current parsing position; this causes repeated parsing of the same prefix]
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [Using `pow` (floating-point) for integer digit counting is unreliable and inefficient; also `pow` may not be linked properly causing linker errors]
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ [Shifting logic `aa[k]=aa[k+1+u]` is incorrect and corrupts the string; also modifies `aa` while using it in loop condition]
        {
            aa[k]=aa[k+1+u];
        }
    }
    w=strlen(c);
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1]; // @@ [Assumes `b[i]` is valid operand, but previous shifting/parsing may have left uninitialized or zeroed values]
            b[i]=0;
            if(i==0||c[i-1]=='+')
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1]; // @@ [Same issue as multiplication; also division by zero possible if parsing failed]
            b[i]=0;
            if(c[i-1]=='+'||i==0)
            c[i]='+';
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