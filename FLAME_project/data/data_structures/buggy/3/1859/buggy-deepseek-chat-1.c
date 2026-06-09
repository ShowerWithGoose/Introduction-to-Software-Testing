#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    gets(s);
    int count;
    int len=strlen(s);
    int m;
    int i;
    for( i=0;i<len;i++)
    {
        if(s[i]=='.')
            m=i;
    }
    if (m!=1)
    {
        count=m-1;
        printf("%c.",s[0]); // @@ Error: When the input is "0.9", m=1, so this branch is not executed. However, if m!=1 and s[0] is '0' (e.g., "0.12"), this would incorrectly print "0." as the base, but the problem requires the base to have a non-zero digit before the decimal point. The logic for handling numbers like "0.12" is missing here.
        for(int k=1;k<len;k++)
        {
            if(k!=m)
                printf("%c",s[k]);
        }
        printf("e%d",count);
    }
    else if(s[0]!='0')
    {
        for(int k=0;k<len;k++)
        {
            printf("%c",s[k]);
        }
        printf("e0");
    }
    else
    {
        for(int k=3;k<len;k++) // @@ Error: For input "0.9", len=3, so this loop runs from k=3 to k<3, which means it never executes. count remains uninitialized, leading to undefined behavior. The loop should start from k=2 to find the first non-zero digit after the decimal point.
        {
            if(s[k]!='0')
            {
                count=k;
                break;
            }
        }
    /*    printf("%c",s[count]);
        if(count!=len-1)
            printf(".");
        for(int k=count+1;k<len;k++)
        {
            printf("%c",s[k]);
        }
        printf("e%d",-count+1);*/ // @@ Error: This entire block is commented out, so no output is produced for cases like "0.9". The code should output "9e-1" but instead produces nothing.
    }
}