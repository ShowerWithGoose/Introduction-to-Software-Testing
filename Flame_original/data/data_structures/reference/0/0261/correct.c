#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char s[1000]={'\0'},c;
    int i=0;
    gets(s);
    for(i=0;s[i];i++)
    {
        if(s[i]=='-')
        {
            if((isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1])||(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1])||(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1]))
            for(c=s[i-1]+1;c<s[i+1];c++)
            {
                printf("%c",c);
            }
            else printf("%c",s[i]);
        }
        else printf("%c",s[i]);
    }
    return 0;
}

