#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ [gets is deprecated and unsafe; should use fgets. Also may cause undefined behavior on buffer overflow. In some compilers, gets is not declared, causing implicit declaration error.]
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++; // @@ [No null terminator added after the loop; aa is not a proper string, causing strlen later to read beyond array.]
        }
        
    }

     w=strlen(aa); // @@ [aa is not null-terminated; strlen result is undefined.]
    for(int i=0,n=0;i<w;n++,i+=2) // @@ [i increments by 2 assuming each token occupies 2 characters, but numbers can be multi-digit, leading to incorrect parsing and out-of-bounds access.]
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ [sscanf reads only the first number and operator; the remaining string is not updated correctly because aa is shifted, but the length w is not updated, causing incorrect parsing.]
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ [pow requires linking with -lm; also using floating point for integer digit count is inappropriate and may cause precision issues. Should calculate digit count using integer arithmetic.]
            break;
        }
        for(int k=0;k<w-2*n;k++)
        {
            aa[k]=aa[k+1+u]; // @@ [Shifting the remaining array incorrectly; after shifting, the array is corrupted and subsequent sscanf calls will read from wrong positions.]
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