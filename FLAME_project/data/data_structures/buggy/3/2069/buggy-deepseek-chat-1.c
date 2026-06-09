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
        printf("%c",c[n-1]); // @@ This prints only the first digit before the decimal point, but the expected output requires the base to have one digit before and after the decimal point. The code then prints the entire original string from index 1, which includes the decimal point and all digits, but does not correctly reposition the decimal point to after the first digit. For input "87899.9999999999000999", it prints "9" then "7899.9999999999000999" resulting in "97899.9999999999000999e4" instead of "8.78999999999999000999e4".
        for(int i=1;c[i]!='\0';i++)
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}