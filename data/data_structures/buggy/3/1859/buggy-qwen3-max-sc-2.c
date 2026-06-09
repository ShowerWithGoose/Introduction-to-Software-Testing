#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
    int count;
    int len=strlen(s);
    int m; // @@ [Variable 'm' is used uninitialized if input string contains no '.' character, leading to undefined behavior]
    int i;
    for( i=0;i<len;i++)
    {
        if(s[i]=='.')
            m=i;
    }
    if (m!=1) // @@ [If input has no decimal point, 'm' remains uninitialized, causing unpredictable condition evaluation]
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
        for(int k=3;k<len;k++)
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
        printf("e%d",-count+1);*/
    }
}