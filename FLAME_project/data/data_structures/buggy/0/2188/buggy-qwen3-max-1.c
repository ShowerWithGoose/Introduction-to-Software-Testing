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
        else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9')) // @@ [The condition is logically incorrect: it does not ensure both characters are of the same type, nor does it check that s[i+1] > s[i-1]. Also, it accesses s[i+1] without checking bounds (i+1 may be out of range).]
        {
            hc=s[i+1];
            int k=1;
            for(k=1;k<hc-s[i-1];k++) // @@ [This loop runs even when the expansion condition is invalid (e.g., mixed types like '0' and 'A'), and it doesn't verify that s[i+1] > s[i-1], leading to negative or incorrect ranges. Also, hc-s[i-1] could be negative, causing undefined behavior.]
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