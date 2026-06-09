#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a); // @@ Warning: gets is dangerous and deprecated; implicit declaration leads to undefined reference. Use fgets instead.
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa);
    for(int i=0,n=0;i<w;n++,i+=2) // @@ Error: Assuming each token is exactly one digit and one operator; numbers may be multi-digit, causing incorrect parsing.
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ Error: sscanf always reads from the beginning of aa, never advancing; first number/operator will be read repeatedly. Also, multi-digit numbers not handled correctly.
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ Error: pow returns double; requires -lm link flag. Also logic to find digit count is flawed (infinite loop if b[n]==0) and unnecessary.
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ Error: w-2*n may become negative; the shifting logic is incorrect and will corrupt the string.
        {
            aa[k]=aa[k+1+u]; // @@ Error: Shifts left by u+1 positions, but u might be large; also does not handle the null terminator, leading to undefined behavior.
        }
    }
    w=strlen(c); // @@ Warning: c is filled by sscanf with single characters; its length is likely less than the number of operators, leading to incorrect loop bounds.
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1];
            b[i]=0;
            if(i==0||c[i-1]=='+') // @@ Error: When i==0, c[i-1] accesses out-of-bounds. Also operator indexing mismatched.
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
            b[i]=0;
            if(c[i-1]=='+'||i==0) // @@ Error: Same out-of-bounds issue; also logic incorrectly sets c[i] to '+' when i==0.
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
    }
    int m=b[0]; // @@ Warning: b[0] may not be properly initialized due to earlier parsing failures.
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