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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ Condition does not ensure both characters are of the same type and within valid ranges; also missing check that ch[i+1] > ch[i-1]; also missing else clause to print '-' when expansion condition is not met.
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            } // @@ Missing else clause to output the '-' character when the expansion condition is not satisfied, causing dashes to be omitted.
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}