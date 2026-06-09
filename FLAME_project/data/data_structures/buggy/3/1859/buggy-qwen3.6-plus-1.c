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
        printf("%c.",s[0]);
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
        for(int k=3;k<len;k++) // @@ The loop starts at index 3, but for input "0.9", the first non-zero digit after '0.' is at index 2. It should start at k=2. Also, if there are no non-zero digits found (e.g., 0.0), count remains uninitialized.
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
        printf("e%d",-count+1);*/ // @@ The code responsible for printing the result for numbers like 0.9 is commented out. This block needs to be uncommented and corrected to handle the output format (mantissa and exponent).
    }
}