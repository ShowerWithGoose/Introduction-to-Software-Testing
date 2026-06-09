#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int f(int a,char c,int b)
{
    switch(c)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default : break;                
    }
    return 0;
}
int main()
{
    char s[250];
    int num[250]; 
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and may cause compilation errors with modern compilers. Use `fgets` instead.]
    int i=0,j=0,k=0,q=1;
    while(s[i] != '=')
    {
        if(s[i]==' ')
        {
            continue; // @@ [This `continue` causes an infinite loop because `i` is not incremented when encountering a space.]
        }
        if(isdigit(s[i])&&!(j%2))
        {
            num[j]=num[j]*10+s[i]-'0';
        }
        else if(isdigit(s[i])&&(j%2))
        {
            num[++j]=s[i]-'0';
        }
        else
        {
            num[++j]=s[i];
            k++;
        }
        i++;
    }
    i=0;
    while(i<k)
    {
        int p=2*i+1;
        switch(num[p])
        {
            case '*':
            case '/':
                    num[p+1]=f(num[p-1],(char)num[p],num[p+1]);
                    num[p-1]=0;
                    num[p]=44-q;
                    break;
            case'+':
                   q=1;
                   break;
            case'-':
                   q=-1;
                   break;
            default:
                   break;                      
        }
        i++;
    }
    i=0;
    while(i<k)
    {
        int p=2*i+1;
        num[p+1]=f(num[p-1],(char)num[p],num[p+1]); // @@ [This line assumes all operators are '+' or '-', but after the first pass, some operators may have been replaced by arbitrary values like `44 - q`, leading to undefined behavior in `f`.]
        i++;
    }
    printf("%d",num[2*k]); // @@ [The index `2*k` may be out of bounds or incorrect due to flawed parsing and operator handling logic. The final result may not be stored at this location.]
    return 0;
}