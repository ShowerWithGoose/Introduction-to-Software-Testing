#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c);
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++)
        {
            n=i;
        }
        n=n+1;
        if(c[n+1]=='\0')
            printf("%ce-%d",c[n],n-1);
        else
        {
            printf("%c.",c[n]);
            for(int i=n+1;c[i]!='\0';i++)
                printf("%c",c[i]);
            printf("e-%d",n-1);
        }
    }
    else
    {
        for(int i=0;c[i]!='.';i++)
        {
            n=i;
        }
        n=n+1;
        printf("%c",c[n-1]); // @@ This line incorrectly prints only the first digit before the decimal point, but the expected output should include the decimal point and the rest of the number after it. The logic for the else branch is flawed: it should print the base as "first digit . remaining digits" and then the exponent, but here it prints the first digit and then the entire original string from index 1, which includes the decimal point and trailing digits, resulting in an incorrect format.
        for(int i=1;c[i]!='\0';i++)
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}