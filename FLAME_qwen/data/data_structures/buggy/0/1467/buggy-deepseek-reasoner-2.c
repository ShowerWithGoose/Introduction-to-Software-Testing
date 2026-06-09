#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ gets is unsafe and deprecated, but not the main logic error
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ condition does not ensure both characters are in [a-z]; should be (str[i-1]>='a' && str[i-1]<='z') && (str[i+1]>='a' && str[i+1]<='z')
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ condition does not ensure both characters are in [0-9]; should be (str[i-1]>='0' && str[i-1]<='9') && (str[i+1]>='0' && str[i+1]<='9')
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ condition does not ensure both characters are in [A-Z]; should be (str[i-1]>='A' && str[i-1]<='Z') && (str[i+1]>='A' && str[i+1]<='Z')
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
            // @@ Missing else clause: when none of the above conditions are true, the dash '-' should be printed unchanged; currently it is omitted.
        }

    }
    return 0;
}