#include<stdio.h>
#include<string.h>
char ch[1000];
int main()
{
    scanf("%s",ch);
    int len=strlen(ch),i=0,lon,j=0;
    for(;i<len;i++)
    {
        if(ch[i]=='-')
        {
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ [Logical error: The condition incorrectly checks ranges. It must verify that both characters belong to the exact same type range (e.g., both lowercase) and that the character after '-' is strictly greater than the one before it.]
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
        }
        else printf("%c",ch[i]); // @@ [Logical error: This else clause only handles non-'-' characters. When ch[i] is '-' and the expansion condition fails, the '-' is not printed, resulting in missing characters in the output.]
        lon=0;
    }
    return 0;
}