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
    gets(s); // @@ [Using gets is unsafe and may cause compilation error in strict C11 environments.]
    int i=0,j=0,k=0,q=1;
    while(s[i] != '=')
    {
        if(s[i]==' ')
        {
            continue; // @@ [Infinite loop when space encountered: 'continue' skips increment of i, causing loop to never advance.]
        }
        if(isdigit(s[i])&&!(j%2))
        {
            num[j]=num[j]*10+s[i]-'0'; // @@ [num[j] uninitialized for j=0, leads to undefined behavior.]
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
                    num[p-1]=0; // @@ [Zeroing left operand destroys value needed for later addition/subtraction.]
                    num[p]=44-q; // @@ [Replaces operator with arbitrary character, causing incorrect processing in subsequent loop.]
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
        num[p+1]=f(num[p-1],(char)num[p],num[p+1]); // @@ [Processes all operators including modified placeholders, leading to wrong results.]
        i++;
    }
    printf("%d",num[2*k]); // @@ [Index 2*k may be out of bounds if operator count does not match final result position.]
    return 0;
}