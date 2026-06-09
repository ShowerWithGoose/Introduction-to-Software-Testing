#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;)
        {if(s[i]!='-')
        {printf("%c",s[i-1]); // @@ This line causes duplicate output. When an expansion occurs, s[i+1] is printed as part of the range. After i+=2, the next iteration's s[i-1] refers to this same character, causing it to be printed again.
        i+=1;
        }
        else
        {
        int flag=0;
        if(s