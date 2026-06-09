#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ [gets is deprecated and removed in C11, causing compilation error in strict mode]
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
        printf("%c.%se-%d",s[y],p,x+1); // @@ [When p points to an empty string (e.g., input "0.5"), this incorrectly outputs a decimal point after the base. The base should be an integer without a decimal point in that case.]
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