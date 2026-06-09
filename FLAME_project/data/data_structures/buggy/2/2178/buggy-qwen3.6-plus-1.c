#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [The function 'gets' is deprecated and removed in C11; use 'fgets' instead. Also, the variable 'a' is used here but the error log mentions 'gets(a)' while the provided source code has 'gets(a)', however the compilation error log provided in the prompt seems to mismatch the source code slightly (referencing 'gets(a)' vs 'gets(s)' in reference). In this specific source code, 'gets' causes a warning/error depending on compiler standards.]
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
        sscanf(aa,"%d%c",&b[n],&c[n]);int u;
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [Undefined reference to 'pow'. The math library is not linked correctly or 'pow' is unnecessary for integer operations. Using floating point pow for integer digit counting is inefficient and causes linking errors if -lm is not used, though typically gcc links it if <math.h> is included, the error log explicitly states undefined reference to pow.]
            break;
        }
        for(int k=0;k<w-2*n;k++)
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
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
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