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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ Incorrect condition: fails to verify both characters are strictly within the same range (missing upper bound check for ch[i-1] and lower bound for ch[i+1]) and does not check if ch[i-1] < ch[i+1].
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
        }
        else printf("%c",ch[i]); // @@ Logical error: when ch[i] is '-' and the expansion condition is false, the '-' character is not printed. The else branch only executes for non-'-' characters.
        lon=0;
    }
    return 0;
}