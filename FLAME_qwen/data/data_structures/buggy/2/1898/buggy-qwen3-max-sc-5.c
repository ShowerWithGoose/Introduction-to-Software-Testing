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
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to compilation errors.]
    int i=0,j=0,k=0,q=1;
    while(s[i] != '=')
    {
        if(s[i]==' ')
        {
            continue; // @@ [This `continue` causes an infinite loop because `i` is not incremented when encountering a space. The loop condition depends on `i`, but `i++` is skipped.]
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
                    num[p]=44-q; // @@ [Arbitrary assignment to `num[p]` (e.g., 44 - q) corrupts operator data. This breaks later parsing since the operator is no longer '+', '-', etc., causing incorrect behavior in the second pass.]
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
        num[p+1]=f(num[p-1],(char)num[p],num[p+1]); // @@ [This assumes all operators are still valid, but earlier step replaced '*' and '/' with arbitrary values (like 43 or 45), so casting to char may yield unexpected operators, leading to wrong calculations or undefined behavior.]
        i++;
    }
    printf("%d",num[2*k]); // @@ [The indexing `2*k` may be out of bounds or incorrect due to flawed parsing logic and array usage. The structure of `num` does not reliably store numbers and operators in alternating positions as assumed.]
    return 0;
}