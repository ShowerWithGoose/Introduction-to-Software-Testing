#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
    int count;
    int len=strlen(s);
    int m; // @@ [Variable 'm' is used uninitialized if input string contains no '.' character, leading to undefined behavior or incorrect logic]
    int i;
    for( i=0;i<len;i++)
    {
        if(s[i]=='.')
            m=i;
    }
    if (m!=1) // @@ [This condition assumes there is always a decimal point; if input has no '.', 'm' remains uninitialized, causing unpredictable behavior]
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
        for(int k=3;k<len;k++) // @@ [Assumes at least 4 characters exist (indices 0,1,2,3), but input like "0.1" would make len=3, causing out-of-bounds access]
        {
            if(s[k]!='0')
            {
                count=k;
                break;
            }
        }
    /*    printf("%c",s[count]); // @@ [This block is commented out, so the program produces no output for numbers like "0.00123", violating problem requirements]
        if(count!=len-1)
            printf(".");
        for(int k=count+1;k<len;k++)
        {
            printf("%c",s[k]);
        }
        printf("e%d",-count+1);*/
    }
}