#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to security concerns]
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
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ [Incorrect parsing logic: `sscanf` always reads from start of `aa`, not current position; also modifies `aa` in loop causing undefined behavior]
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [Using `pow` for integer digit counting is inefficient and may introduce floating-point inaccuracies]
            break;
        }
        for(int k=0;k<w-2*n;k++)
        {
            aa[k]=aa[k+1+u]; // @@ [This shifts `aa` incorrectly and leads to corrupted parsing; also modifies string while parsing]
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
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1]; // @@ [Division order is wrong: should be `b[i] / b[i+1]` but stored into `b[i+1]`; also modifies operands before later use]
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