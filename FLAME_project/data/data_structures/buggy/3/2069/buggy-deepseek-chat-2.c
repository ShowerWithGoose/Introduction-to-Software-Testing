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
        printf("%c",c[n-1]); // @@ This prints only the first digit before the decimal point, but the expected output requires the first digit followed by a decimal point and the rest of the digits (excluding the original decimal point). The logic incorrectly outputs the first digit and then all digits from index 1 onward, which includes the original decimal point and duplicates the first digit.
        for(int i=1;c[i]!='\0';i++)
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}