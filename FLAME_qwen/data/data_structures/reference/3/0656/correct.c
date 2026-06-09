#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[1000];
    char *p=s,*d,*f;
    int weishu;
    scanf("%s",s);
    while(*p!='\0'&&*p!='.')    p++;
    d=p;
    if(d-s==1&&s[0]=='0')
    {
        f=d+1;
        while(*f=='0')   f++;
        printf("%c",*f);
        if(*(f+1)=='\0')
        {
            printf("e-%d",f-d);
        }
        else
        {
            printf(".%se-%d",f+1,f-d);
        }
    }
    else if(d-s>1)
    {
        *d='\0';
        printf("%c.%s%se%d",*s,s+1,d+1,d-s-1);
    }
    else if(d-s==1&&s[0]!='0')
    {
        printf("%se0",s);
    }
    return 0;
}

