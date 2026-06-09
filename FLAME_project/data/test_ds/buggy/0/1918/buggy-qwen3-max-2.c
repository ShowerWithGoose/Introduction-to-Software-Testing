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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) @@ // Condition is incorrect: it checks only lower bound for first char and upper bound for second char without ensuring both are in the same category (e.g., 'B' >= 'A' is true and 'e' <= 'Z' is false, but this condition may still pass incorrectly due to flawed logic). Also missing validation that both characters are of the same type and that ch[i-1] < ch[i+1].
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
            else printf("%c",ch[i]); @@ // Missing else clause to print '-' when expansion conditions are not met. Without this, the '-' is simply skipped instead of being printed as-is.
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}