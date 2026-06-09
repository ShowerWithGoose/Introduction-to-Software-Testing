#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check both ends are lowercase, but only checks left >= 'a' and right <= 'z', allowing mixed cases like 'Z-d']
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check both ends are digits, but only checks left >= '0' and right <= '9', allowing invalid like ': - 5']
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check both ends are uppercase, but only checks left >= 'A' and right <= 'Z', allowing mixed like 'a-Z']
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