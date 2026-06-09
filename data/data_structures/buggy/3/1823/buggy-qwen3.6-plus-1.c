#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ gets() is deprecated and removed in the C11 standard, which causes compilation errors in modern compilers. It should be replaced with scanf("%s", s) or fgets(s, sizeof(s), stdin).
    int n=strlen(s);
    if(s[0]=='0')
    {
        int x=0,y=2;
        while(s[y]=='0')
        {
            x++;
            y++;
        }
        char *p=s+y+1;
        printf("%c.%se-%d",s[y],p,x+1);
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]);
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x);
    }
    return 0;
}