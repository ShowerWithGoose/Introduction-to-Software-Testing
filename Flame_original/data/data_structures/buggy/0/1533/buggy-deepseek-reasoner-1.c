#include<stdio.h>
#include<string.h>
char kz(char s[]) // @@ function should return void, not char, and function has no return statement
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
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'1')) // @@ logic errors: incorrect range checks (e.g., s[i+1]<'1' for digits, missing upper bounds) and no bounds check for i-1 and i+1 (potential out-of-bounds access)
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]-1)
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