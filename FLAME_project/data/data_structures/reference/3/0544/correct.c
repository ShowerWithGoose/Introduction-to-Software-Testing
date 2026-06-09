#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[110]="";
    int i=0,e=0;
    int count=0,strlens;
    gets(s);
    strlens=strlen(s);
    if(s[0]=='0')                                              //0.几
    {
        for(i=0;s[i]=='0'||s[i]=='.';i++,count++)
        ;
        e=1-count;
        printf("%c",s[i]);
        if(count!=strlens-1)printf(".");
        for(i++;s[i]!='\0';i++)
            printf("%c",s[i]);
        printf("e");
        printf("%d",e);
    }
    else if(s[1]=='.')                                        //几点几
    {
        for(i=0;s[i]!='\0';i++)
            printf("%c",s[i]);
        printf("e0");
    }
    else                                                      //... . ...
    {
        for(i=0;s[i]!='.';i++,count++)
            ;
        e=count-1;
        printf("%c",s[0]);
        printf(".");
        for(i=1;s[i]!='\0';i++)
            if(s[i]!='.')printf("%c",s[i]);
        printf("e");
        printf("%d",e);
    }
    return 0;
}



