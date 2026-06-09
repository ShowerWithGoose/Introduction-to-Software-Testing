#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ gets is deprecated and removed in C11, causing compilation errors in strict environments; use fgets instead.
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa); // @@ aa is not null-terminated after copying characters, strlen may read out of bounds.
    for(int i=0,n=0;i<w;n++,i+=2)
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ sscanf does not consume the parsed string, leading to repeated parsing of the same data; also aa lacks null terminator.
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n])
            break;
        }
        for(int k=0;k<w-2*n;k++)
        {
            aa[k]=aa[k+1+u];
        }
    }
    w=strlen(c); // @@ c array is never null-terminated, causing strlen to read out of bounds and undefined behavior.
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1];
            b[i]=0;
            if(i==0||c[i-1]=='+')
            c[i]='+';
            if(c[i-1]=='-') // @@ When i=0, accessing c[-1] causes out-of-bounds memory access.
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
            b[i]=0;
            if(c[i-1]=='+'||i==0)
            c[i]='+';
            if(c[i-1]=='-') // @@ When i=0, accessing c[-1] causes out-of-bounds memory access.
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