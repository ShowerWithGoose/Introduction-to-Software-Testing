#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    int i,addr=0,e=0,dot=0;
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        dot=i;
    }
    if(s[0]=='0')
    {
        e--;
        for(i=2;i<strlen(s);i++)
        {
            if(s[i]=='0') e--;
            else 
            {
                addr=i;
                break;
            }
        }
        if(addr==strlen(s)-1) printf("%c",s[addr]);
        else 
        {
            printf("%c\.",s[addr]);
            for(i=addr+1;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
        }
        printf("e%d",e);
    }
    else if(dot)
    {
        printf("%c\.",s[0]);
        for(i=1;i<dot;i++)
        {
            printf("%c",s[i]);
        }
        for(i=dot+1;i<strlen(s);i++)
        {
            printf("%c",s[i]);
        }
        printf("e%d",dot-1);
    }
    else
    {
        printf("%c\.",s[0]);
        for(i=1;i<strlen(s);i++)
        {
            printf("%c",s[i]);
        }
        printf("e%d",strlen(s)-1);
    }
    return 0;
}

