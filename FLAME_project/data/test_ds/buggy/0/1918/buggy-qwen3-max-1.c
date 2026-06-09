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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) @@ // Condition is incorrect: it only checks lower bound of left char and upper bound of right char, not that both are in the same category. Should check both chars belong to same group (e.g., both lowercase).
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
            else printf("%c",ch[i]); @@ // Missing else clause to print '-' when condition fails; without this, '-' is skipped entirely in invalid cases like "B-e".
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}