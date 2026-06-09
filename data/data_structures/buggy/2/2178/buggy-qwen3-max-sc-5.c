#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa);
    for(int i=0,n=0;i<w;n++,i+=2)
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ [Incorrect parsing logic: `sscanf` always reads from start of `aa`, not from current position; also assumes alternating number-operator format which fails for multi-digit numbers]
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [`pow` returns double; comparing with int may cause precision issues; also inefficient and incorrect for digit counting]
            break;
        }
        for(int k=0;k<w-2*n;k++)
        {
            aa[k]=aa[k+1+u]; // @@ [Shifting array incorrectly; overwrites data needed for subsequent parsing; logic flawed for extracting next token]
        }
    }
    w=strlen(c);
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1]; // @@ [Assumes operands are adjacent in `b`; but previous parsing corrupts operand alignment]
            b[i]=0;
            if(i==0||c[i-1]=='+')
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1]; // @@ [Same issue as multiplication; also integer division is correct per problem, but operand indices are wrong due to parsing errors]
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
        m=m+b[i+1]; // @@ [Operand indexing assumes `b` and `c` are properly aligned, which they are not due to earlier parsing bugs]
        if(c[i]=='-')
        m=m-b[i+1];
    }
    printf("%d",m);
    return 0;
}