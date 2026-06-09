#include<stdio.h>
int main()
{
    int i,n;
    int j=0;
    char ch;
    char c[256]={0};
    while((ch=getchar())!='\n') // @@ This loop may run indefinitely if input does not contain a newline (e.g., EOF). Should also check for EOF.
    {
        c[j]=ch;
        j++;
    }
    c[j]='\0';
    for(i=0;i<=j;i++) // @@ Loop condition i<=j includes the null terminator, causing out‑of‑bounds access when i=j (c[i+1] is undefined) and printing '\0'. Should be i<j.
    {
        if(c[i]!='-')
        {
            printf("%c",c[i]);
        }
        else
        {
            if(c[i-1]>='a'&&c[i-1]<='z'&&c[i+1]>='a'&&c[i+1]<='z'&&c[i+1]>c[i-1])
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else if(c[i-1]>='A'&&c[i-1]<='Z'&&c[i+1]>='A'&&c[i+1]<='Z'&&c[i+1]>c[i-1])
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else if(c[i-1]>='0'&&c[i-1]<='26'&&c[i+1]>='0'&&c[i+1]<='26'&&c[i+1]>c[i-1]) // @@ Invalid digit range: '26' is a multi‑character literal, should be '9'. Also the left bound should be '0' and right bound '9'.
            {
                for(n=1;n<c[i+1]-c[i-1];n++)
                {
                    printf("%c",c[i-1]+n);
                }
            }
            else
            {
                printf("%c",c[i]);
            }
        }
    }
    return 0;
}