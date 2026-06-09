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
        printf("%c",c[n-1]); // @@ [Should print the first digit c[0] instead of the last digit before decimal, and should also print a decimal point '.' after it.]
        for(int i=1;c[i]!='\0';i++) // @@ [This loop includes the original decimal point; it should skip it and also the first digit (already printed). Additionally, a decimal point must be printed before this loop.]
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}