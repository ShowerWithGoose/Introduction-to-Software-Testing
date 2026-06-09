#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a);
    int w=strlen(a); // @@ C89: declaration after statement
    for(int i=0,n=0;i<w;i++) // @@ C89: declaration in for loop initializer
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa);
    for(int i=0,n=0;i<w;n++,i+=2) // @@ C89: declaration in for loop initializer
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ C89: declaration after statement
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n])
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ C89: declaration in for loop initializer
        {
            aa[k]=aa[k+1+u];
        }
    }
    w=strlen(c);
    for(int i=0;i<w;i++) // @@ C89: declaration in for loop initializer
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
    int m=b[0]; // @@ C89: declaration after statement
    for(int i=0;i<w;i++) // @@ C89: declaration in for loop initializer
    {
        if(c[i]=='+')
        m=m+b[i+1];
        if(c[i]=='-')
        m=m-b[i+1];
    }
    printf("%d",m);
    return 0;
}