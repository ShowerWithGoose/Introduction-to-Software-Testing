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
    while(s[i] != '=') // @@ The loop condition checks for '=' but does not increment 'i' when encountering spaces or digits in certain logic paths, potentially causing an infinite loop if the input format isn't perfectly aligned with the parsing logic. More critically, if the input string does not contain '=', this loop will run out of bounds. However, the primary issue for TLE is likely the logic inside.
    {
        if(s[i]==' ')
        {
            continue; // @@ This 'continue' skips the 'i++' at the end of the loop, causing an infinite loop when a space is encountered.
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