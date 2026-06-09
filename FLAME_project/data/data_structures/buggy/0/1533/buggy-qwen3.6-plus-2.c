#include<stdio.h>
#include<string.h>
char kz(char s[])
{
    char c[100];
    int j=0; 
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='9')) // @@ [The original condition used '<' instead of '<=' for the upper bounds ('z', 'Z', '9'), causing valid ranges like '0-8' or 'a-z' to fail the check. Also corrected '1' to '9' for digit range check.]
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]) // @@ [The original condition 'c[j]<s[i+1]-1' stopped printing one character too early. It should continue until the generated character reaches the end character.]
            {
                j++;
                c[j]=c[j-1]+1;
                printf("%c",c[j]);
            }
            j++;
        }
        else
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
    }
}
int main()
{
    char s[100];
    gets(s);
    kz(s);
    return 0;
}