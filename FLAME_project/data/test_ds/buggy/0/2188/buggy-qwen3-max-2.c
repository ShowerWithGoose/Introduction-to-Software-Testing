#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char hc;
    char s[100];
    int j=0,i=0;
    scanf("%s",s);
    int p=strlen(s);
    for(i=0;i<p;i++)
    {
        if(s[i]!='-')
        {
            printf("%c",s[i]);
        }
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ [The condition is logically incorrect: it does not ensure both characters are of the same type, nor does it check that s[i+1] > s[i-1]. Also, it accesses s[i+1] without checking if i+1 is within bounds, and mixes ranges (e.g., 'A' to 'z' includes non-alphabetic characters).]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ [This loop runs even when the range is invalid (e.g., when s[i+1] <= s[i-1]), and it doesn't verify that both endpoints are of the same category (digit, lowercase, uppercase). Also, if s[i+1] < s[i-1], this causes negative or large positive values due to unsigned char behavior, leading to garbage output like "0123456789:;<=>?@A".]
            {
                printf("%c",s[i-1]+k);
            }
            
        }
        else
        {
            printf("%c",s[i]);
        }
    }
}