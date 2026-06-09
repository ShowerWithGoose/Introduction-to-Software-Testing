#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    gets(s); @@ [Using 'gets' is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
    int count;
    int len=strlen(s);
    int m;
    int i;
    for( i=0;i<len;i++)
    {
        if(s[i]=='.')
            m=i;
    }
    if (m!=1) @@ [Variable 'm' may be used uninitialized if input contains no decimal point, leading to undefined behavior or logical error]
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
        for(int k=3;k<len;k++) @@ [Assumes at least 3 characters exist (e.g., "0.0..."), but input like "0.1" would access s[3] which is out of bounds]
        {
            if(s[k]!='0')
            {
                count=k;
                break;
            }
        }
    /*    printf("%c",s[count]); @@ [This block is commented out, so no output is produced for numbers like 0.00123, causing missing output]
        if(count!=len-1)
            printf(".");
        for(int k=count+1;k<len;k++)
        {
            printf("%c",s[k]);
        }
        printf("e%d",-count+1);*/
    }
}