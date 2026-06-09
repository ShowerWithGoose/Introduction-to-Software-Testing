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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ Condition incorrectly checks same type and does not ensure left < right. It also allows mixing lowercase left with uppercase right.
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            } // @@ Missing else branch: when the expansion condition fails, the '-' character is not printed, causing it to be omitted from output.
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}