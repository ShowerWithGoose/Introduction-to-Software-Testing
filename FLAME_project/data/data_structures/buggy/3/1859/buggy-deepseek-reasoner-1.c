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
        for(int k=3;k<len;k++) // @@ Error: Loop should start at k=2 (the first digit after the decimal point) because the decimal point is at index 1. Starting at 3 causes the loop to never execute for inputs like "0.9", leaving 'count' uninitialized and producing no output.
        {
            if(s[k]!='0')
            {
                count=k;
                break;
            }
        }
    /*    printf("%c",s[count]); // @@ Error: This line (and the following output statements) are commented out, so no scientific notation is printed for numbers like "0.9". The output block must be uncommented to produce the correct result.
        if(count!=len-1)
            printf(".");
        for(int k=count+1;k<len;k++)
        {
            printf("%c",s[k]);
        }
        printf("e%d",-count+1);*/
    }
    return 0;
}