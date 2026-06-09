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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) @@ [The condition is incorrect: it checks only one side of the range (e.g., ch[i-1] >= 'a' but doesn't ensure ch[i-1] <= 'z', and similarly for others). Also, it does not verify that both characters are of the same type or that ch[i+1] > ch[i-1].]
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}