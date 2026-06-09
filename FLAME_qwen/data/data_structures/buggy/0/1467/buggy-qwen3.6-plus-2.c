#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ gets is removed in the C11 standard and will cause a compilation error in modern/strict compilers
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1])
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++) // @@ C89/C90 standard does not allow variable declaration inside for-loop initialization, causing a compilation error
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1])
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++) // @@ C89/C90 standard does not allow variable declaration inside for-loop initialization, causing a compilation error
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1])
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++) // @@ C89/C90 standard does not allow variable declaration inside for-loop initialization, causing a compilation error
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
        }

    }
    return 0;
}