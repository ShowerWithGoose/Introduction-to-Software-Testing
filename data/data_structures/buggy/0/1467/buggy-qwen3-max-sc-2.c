#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check both str[i-1] and str[i+1] are in [a-z], but only checks str[i-1]>='a' and str[i+1]<='z', allowing invalid ranges like 'z'-'a']
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check both str[i-1] and str[i+1] are digits, but only checks str[i-1]>='0' and str[i+1]<='9', allowing invalid like '9'-'0']
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check both str[i-1] and str[i+1] are uppercase letters, but only checks str[i-1]>='A' and str[i+1]<='Z', allowing invalid like 'Z'-'A']
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
        }

    }
    return 0;
}