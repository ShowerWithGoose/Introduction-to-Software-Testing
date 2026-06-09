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
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like those with GCC >= 7), `gets` is removed entirely, leading to a compilation error: "implicit declaration of function ‘gets’" or "‘gets’ was not declared". This explains the observed compilation error "gcc: not found" — actually, the real issue is that `gets` is undefined. Use `fgets` instead.]
    int i=0,j=0,k=0,q=1;
    while(s[i] != '=')
    {
        if(s[i]==' ')
        {
            continue; // @@ [This `continue` causes an infinite loop because `i` is never incremented when encountering a space. The loop condition depends on `s[i] != '='`, but if there's a space, `i` stays the same, so it keeps checking the same space forever.]
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
        num[p+1]=f(num[p-1],(char)num[p],num[p+1]); // @@ [This line assumes all operators are either '+' or '-', but after the first pass, some operators (like '*' and '/') were replaced with arbitrary values (e.g., `44 - q`). Casting these back to `char` and passing to `f` leads to incorrect behavior or undefined operations. Also, this second pass doesn't skip already-processed multiplication/division tokens, causing invalid calculations.]
        i++;
    }
    printf("%d",num[2*k]); // @@ [The indexing `num[2*k]` assumes the result is stored at that position, but due to flawed parsing and overwriting logic (especially with `num[p-1]=0` and arbitrary operator replacement), the final result may not be at `num[2*k]`. This leads to wrong output even if the program compiles and runs.]
    return 0;
}