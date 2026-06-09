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
    int num[250]; // @@ The array 'num' is not initialized. Local arrays contain indeterminate garbage values, which will cause incorrect results when accumulating multi-digit numbers with 'num[j] = num[j] * 10 + ...'. It should be initialized to zero, e.g., 'int num[250] = {0};'.
    gets(s); // @@ 'gets' has been removed from the C11 standard and causes compilation errors in modern environments due to implicit declaration or missing library symbol. Use 'fgets(s, sizeof(s), stdin);' instead.
    int i=0,j=0,k=0,q=1;
    while(s[i] != '=')
    {
        if(s[i]==' ')
        {
            continue;
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
        num[p+1]=f(num[p-1],(char)num[p],num[p+1]);
        i++;
    }
    printf("%d",num[2*k]);
    return 0;
}