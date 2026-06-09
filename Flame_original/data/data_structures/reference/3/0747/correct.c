#include<stdio.h>
int main()
{
    char s[1000];
    int i=2,m=1;
    gets(s);
    if(s[0]=='0')
    {
        for(i=2;s[i]=='0';i++){}
        if(s[i+1]=='\0')
        {
            printf("%c",s[i]);
            printf("e-%d",i-1);
        }
        else if(s[i+1]!='\0')
        {
            printf("%c.",s[i]);
            while(s[i+m]!='\0')
            {
                printf("%c",s[i+m]);
                m++;
            }
            printf("e-%d",i-1);
        }
    }
    else if(s[0]!='0')
    {
        for(i=1;s[i]!='.';i++){}
        m=i;
        while(i>1)
        {
            s[i]=s[i-1];
            i--;
        }
        s[1]='.';
        printf("%s",s);
        printf("e%d",m-1);
    }
    return 0;
}



