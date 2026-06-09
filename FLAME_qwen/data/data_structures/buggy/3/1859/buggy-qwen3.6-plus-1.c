#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    gets(s); // @@ gets is removed in the C11 standard and causes compilation errors in modern compilers; use fgets(s, sizeof(s), stdin) instead.
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
        for(int k=3;k<len;k++) // @@ Loop should start from k=2 to correctly check the first digit after the decimal point.
        {
            if(s[k]!='0')
            {
                count=k;
                break;
            }
        }
    /*    printf("%c",s[count]); // @@ The output logic for numbers starting with 0. is commented out, resulting in no output; it must be uncommented.
        if(count!=len-1)
            printf(".");
        for(int k=count+1;k<len;k++)
        {
            printf("%c",s[k]);
        }
        printf("e%d",-count+1);*/ // @@ This line is part of the commented output block; uncommenting is required to print the exponent correctly.
    }
}