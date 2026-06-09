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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) @@ [The condition is incorrect: it does not ensure both characters are of the same type and within valid range. For example, it allows 'a' and 'Z' to pass if 'a'>='a' and 'Z'<='z' is false but other parts may misleadingly pass. Also missing check that ch[i-1] <= ch[i+1] and same category. Additionally, accessing ch[i-1] when i=0 causes undefined behavior.]
            {
                lon=ch[i+1]-ch[i-1]; @@ [If the condition above is wrong, this calculation may be invalid. Also, if ch[i+1] <= ch[i-1], lon could be <=0 leading to unexpected loop behavior.]
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