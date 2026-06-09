#include <stdio.h>
#include <string.h>
int main() {
    char str[105];
    gets(str);
    int i=0,numbp=0;
    for(i=0;i< strlen(str);i++)
    {
        if(str[i]=='.') numbp=i+1;
    }
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);int num=i;
        printf("%c",str[i]);
        if(str[i+1]!='\0')
        {
            printf(".");
            for (i = num+1; i < strlen(str); i++) printf("%c",str[i]);
        }
        printf("e-%d",num-1);
    }
    else if(numbp==0)
    {
        printf("%c.",str[0]);
        for(i=1;i< strlen(str);i++) printf("%c",str[i]);
        printf("e%d", strlen(str)-1);
    }
    else
    {
        printf("%c.",str[0]);
        for(i=1;i< strlen(str);i++)
            if(str[i]!='.') printf("%c",str[i]);
        printf("e%d",numbp-2);
    }
}

