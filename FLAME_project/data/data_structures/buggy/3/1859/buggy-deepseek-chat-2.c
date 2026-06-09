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
        for(int k=3;k<len;k++) // @@ Error: The loop starts from index 3, but for input "0.9", the first non-zero digit is at index 2 (the digit '9'), so it is skipped. Should start from k=2.
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
        printf("e%d",-count+1);*/ // @@ Error: The entire output logic for the case where s[0]=='0' is commented out, so no output is produced for inputs like "0.9".
    }
}