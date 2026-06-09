#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c);
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) // @@ Does not check i>0, causing out-of-bounds when i=0; also does not ensure both characters belong to the same character type (lowercase, uppercase, digit) as required.
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ Insufficient: only checks lower bound of first and upper bound of second; does not verify both are digits (e.g., c[i-1]='0', c[i+1]=':' would pass incorrectly).
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ Same issue: does not ensure both are lowercase letters; could include non‑letter characters that lie within the ASCII range.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ Same issue: does not ensure both are uppercase letters.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                }
            } // @@ Missing else: when c[i]=='-' but expansion conditions fail (e.g., characters of different types or c[i-1] >= c[i+1]), the '-' character is NOT added to the output, which violates the requirement to output it unchanged.
        }
        else
        {
            a[j]=c[i];
            j++;
        }
    }
    a[j]='\0';
    printf("%s",a);
    return 0;
}