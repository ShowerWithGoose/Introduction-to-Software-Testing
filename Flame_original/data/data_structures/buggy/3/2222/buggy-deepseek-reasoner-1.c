#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char s[120] = {};
    char t[120] = {};
    gets(s); // @@ Use of gets is unsafe and may cause compilation issues in modern C standards.
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
            printf("%1c.",s[i]); // @@ Format specifier %1c is unusual; likely intended as %c. Also will print the first non-zero digit correctly.
            int j;
            j=i+1;
            while(j<=l)
            {
                printf("%1c",s[j]); // @@ Same formatting issue; also printing up to j<=l includes the null terminator, causing potential garbage output.
                j++;
            }
        }
        else
        {
            printf("%1c",s[i]); // @@ Same formatting issue; for numbers like "0.0" this may print a null character.
        }
        printf("e-%d",sum); // @@ Exponent is off by one; should be sum+1 to match scientific notation (e.g., 0.001 => e-3, not e-2).
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
        i=l-1; // @@ Using l (length of original string) as index into t can cause out-of-bounds access because t has length j, which may be smaller.
        while(t[i]=='0') // @@ Out-of-bounds access: i may be >= strlen(t), leading to undefined behavior.
        {
            len++;
            i--;
        }
        if((le-len)==1)
        {
            printf("%1c",t[0]); // @@ Unnecessary %1c, should be %c.
        }
        else
        {
            printf("%1c.",t[0]); // @@ Same formatting issue.
            i=1;
            while(i<le-len)
            {
                printf("%1c",t[i]); // @@ Same formatting issue.
                i++;
            }
        }
        printf("e%d",sum);
    } 
    return 0;
}