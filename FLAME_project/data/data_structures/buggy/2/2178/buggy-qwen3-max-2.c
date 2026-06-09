#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [The `gets` function is unsafe and deprecated; it's not available in modern C standards, causing a compilation error. Use `fgets` instead.]
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
            if(pow(10,u)>b[n]) // @@ [The `pow` function returns a double, which may cause precision issues when used with integers. More critically, the logic here assumes base-10 digit counting but doesn't correctly parse multi-digit numbers from the string `aa`. Also, the loop modifies `aa` while parsing, leading to incorrect parsing in subsequent iterations.]
            break;
        }
        for(int k=0;k<w-2*n;k++)
        {
            aa[k]=aa[k+1+u]; // @@ [This shifting of `aa` is logically flawed—it corrupts the input string during parsing, causing subsequent `sscanf` calls to read garbage or incorrect data. The entire parsing approach using `sscanf` in a loop with manual string shifting is error-prone and incorrect for expressions with mixed operators.]
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