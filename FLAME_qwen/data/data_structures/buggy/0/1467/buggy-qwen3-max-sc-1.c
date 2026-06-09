#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors. Use 'fgets' instead.]
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check that BOTH characters are in [a-z], but this checks only str[i-1] >= 'a' and str[i+1] <= 'z', allowing invalid pairs like '{'-'z'.]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ [Incorrect condition: should check that BOTH characters are digits, but this allows cases like '0'-'{' which satisfies str[i-1] >= '0' and str[i+1] <= '9' only if str[i+1] is actually <= '9', but missing lower bound on str[i+1] and upper bound on str[i-1]. Actually, it's missing str[i+1] >= '0' and str[i-1] <= '9'.]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ [Incorrect condition: similar to lowercase case; must ensure both are uppercase letters, but only checks str[i-1] >= 'A' and str[i+1] <= 'Z', allowing invalid like '['-'Z'.]
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