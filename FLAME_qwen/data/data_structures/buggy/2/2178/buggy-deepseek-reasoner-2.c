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
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa); // @@ aa is not null-terminated; strlen may read beyond allocated memory or produce incorrect length.
    for(int i=0,n=0;i<w;n++,i+=2) // @@ i+=2 assumes each number is exactly one digit, which is incorrect for multi‑digit numbers; also w is not updated after shifting aa.
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ sscanf always reads from the beginning of aa, not from the current position; repeated iterations will re‑parse the same data.
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ pow returns double; comparison with integer can be imprecise, and the computed u may be off (e.g., for b[n]==0, loop never ends).
            break;
        }
        for(int k=0;k<w-2*n;k++)
        {
            aa[k]=aa[k+1+u]; // @@ shifts array incorrectly; uses k+1+u which may go out of bounds, and does not update w; also overwrites content needed later.
        }
    }
    w=strlen(c); // @@ c is not null-terminated; strlen may produce an incorrect length or cause a buffer overread.
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