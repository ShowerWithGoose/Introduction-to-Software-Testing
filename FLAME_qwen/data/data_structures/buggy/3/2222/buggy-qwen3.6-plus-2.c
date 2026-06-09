#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char s[120] = {}; // @@ [Error: Empty initializer list {} is not valid in standard C (C89/C90) and may cause compilation errors; use {0} instead.]
    char t[120] = {}; // @@ [Error: Same as above, use {0} instead.]
    gets(s); // @@ [Error: gets() is removed in the C11 standard and will cause a compilation error in strict environments; use fgets(s, sizeof(s), stdin) instead.]
    int i,sum;
    sum=0;
    int l=strlen(s);
    if(s[0]=='0')
    {
        sum+=1;
        i=2;
        while(s[i]=='0')
        {
            i++;
            sum++;
        }
        if(sum<l-2)
        {
            printf("%1c.",s[i]);
            int j;
            j=i+1;
            while(j<=l) // @@ [Error: Loop condition should be j < l to avoid accessing and printing the null terminator '\0' at index l, which causes output corruption.]
            {
                printf("%1c",s[j]);
                j++;
            }
        }
        else
        {
            printf("%1c",s[i]);
        }
        printf("e-%d",sum);
    }
    else
    {
        while(s[sum]!='.'&&sum<l)
        {
            sum++;
        }
        sum--;
        int j=0;
        i=0;
        while(i<l)
        {
            if(s[i]!='.')
            {
                t[j]=s[i];
                j++;
            }
            i++;
        }
        int le=strlen(t);
        int len=0;
        i=l-1; // @@ [Error: Should be i = le - 1; t's length is le, so l-1 points to the null terminator of t, causing the trailing zero removal loop to fail immediately.]
        while(t[i]=='0')
        {
            len++;
            i--;
        }
        if((le-len)==1)
        {
            printf("%1c",t[0]);
        }
        else
        {
            printf("%1c.",t[0]);
            i=1;
            while(i<le-len)
            {
                printf("%1c",t[i]);
                i++;
            }
        }
        printf("e%d",sum);
    } 
    return 0;
}