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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ Error: Condition does not fully check same character type (e.g., missing upper bound for first char and lower bound for second char) and does not require ch[i+1] > ch[i-1].
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
        } // @@ Error: Missing else branch to output the '-' character when expansion condition is not met. The program currently does nothing, so the '-' is omitted.
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}