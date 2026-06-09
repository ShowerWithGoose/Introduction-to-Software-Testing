#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [gets is deprecated and dangerous; should use fgets instead]
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa);
    for(int i=0,n=0;i<w;n++,i+=2) // @@ [Logic error: i+=2 assumes each number is single digit, but numbers can be multi-digit; also sscanf usage is incorrect]
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ [sscanf always reads from start of aa, not from current position; also pow(10,u) may cause linker error due to missing -lm flag]
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [pow returns double, comparison with int may cause issues; also linker error for pow]
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ [Logic error: incorrect shifting of aa array, does not properly remove parsed number and operator]
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
            if(c[i-1]=='+'||i==0) // @@ [Potential logic error: when i==0, c[i-1] is out of bounds]
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