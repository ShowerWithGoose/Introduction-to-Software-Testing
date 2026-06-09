#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[1000];
int judge(int x)
{
    if(isupper(s[x-1])&&isupper(s[x+1])&&s[x-1]<s[x+1]) return 1;
    if(islower(s[x-1])&&islower(s[x+1])&&s[x-1]<s[x+1]) return 1;
    if(isdigit(s[x-1])&&isdigit(s[x+1])&&s[x-1]<s[x+1]) return 1;
    return 0;
}
int main()
{
    int len;
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i+1]=='-'&&judge(i+1)){
            for(int j=s[i];j<s[i+2];j++)
                putchar(j);
            i++;
        }
        else
            putchar(s[i]);
    }
    return 0;
}

