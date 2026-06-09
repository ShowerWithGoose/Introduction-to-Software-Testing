#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000000
int main()
{
    int i,j;
    char s[MAXSIZE];
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='-'&&isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1])
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        else if(s[i]=='-'&&islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1])
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        else if(s[i]=='-'&&isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1])
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        else
            printf("%c",s[i]);

    }
    return 0;
}

