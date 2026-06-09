#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    gets(s); // @@ gets() is removed in the C11 standard and causes compilation errors in modern environments; use fgets() or scanf() instead.
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
        for(int k=1;k<len;k++) // @@ Declaring loop variable inside 'for' is a C99 feature; causes compilation error if compiled with C89/C90 standard.
        {
            if(k!=m)
                printf("%c",s[k]);
        }
        printf("e%d",count);
    }
    else if(s[0]!='0')
    {
        for(int k=0;k<len;k++) // @@ Same C99 syntax issue as above; may cause compilation error in older C standards.
        {
            printf("%c",s[k]);
        }
        printf("e0");
    }
    else
    {
        for(int k=3;k<len;k++) // @@ Same C99 syntax issue as above.
        {
            if(s[k]!='0')
            {
                count=k;
                break;
            }
        }
    /*    printf("%c",s[count]); // @@ Output logic for numbers less than 1 is commented out, resulting in missing output for this case.
        if(count!=len-1)
            printf(".");
        for(int k=count+1;k<len;k++)
        {
            printf("%c",s[k]);
        }
        printf("e%d",-count+1);*/ // @@ End of commented block; uncommenting is required to fix the logical error.
    }
}