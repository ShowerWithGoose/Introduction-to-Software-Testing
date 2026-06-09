#include<stdio.h> 
#include<string.h>
char ch[1000005],k;
int len,i;
int judge(char a)
{
    if(a>='0'&&a<='9')
    return 0;
    else if(a>='a'&&a<='z')
    return 1;
    else
    return 2;
}
int main()
{
    gets(ch);
    len=strlen(ch);
    for(i=0;i<len;i++)
    {
        if(ch[i]!='-')
        printf("%c",ch[i]);
        else
        {
            if(judge(ch[i-1])==judge(ch[i+1]))
            {
                for(k=ch[i-1]+1;k<ch[i+1];k++)
                printf("%c",k);
            }
            else printf("%c",ch[i]);
        }
    }
}
