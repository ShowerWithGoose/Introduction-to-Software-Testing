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
    gets(s);
    int i=0,j=0,k=0,q=1;
    while(s[i] != '=')
    {
        if(s[i]==' ')
        {
            continue; // @@ infinite loop: i is not incremented, so execution gets stuck at spaces
        }
        if(isdigit(s[i])&&!(j%2))
        {
            num[j]=num[j]*10+s[i]-'0'; // @@ uses uninitialized num[0] (and any other first digit of a multi‑digit number) because num array is never zeroed
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
                    num[p]=44-q; // @@ overwrites the operator with a meaningless value, corrupting later processing
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
        num[p+1]=f(num[p-1],(char)num[p],num[p+1]); // @@ assumes all operators are unchanged, but some have been overwritten; also this should only process + and –, not already handled * and /
        i++;
    }
    printf("%d",num[2*k]);
    return 0;
}