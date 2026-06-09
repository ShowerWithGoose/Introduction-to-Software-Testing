#include <stdio.h>
#include <string.h>
int main()
{
    char a;
    char str[10001];
    int i=1;
    gets(str); // @@ Compilation error: gets is unsafe and removed from C11 standard, causing implicit declaration error or linking failure in strict compilation modes.
    if(str[0]!='0')
    {
        while(str[i]!='.')
        {
            i++;
        }
        a=str[0];
        printf("%c.",a);
        for(int j=1; j<=strlen(str)-1; j++)
        {
            if(str[j]!='.')
                printf("%c",str[j]);
        }
        printf("e%d",i-1);
    }
    else if(str[0]=='0')
    {
        i=2;
        while(str[i]=='0')
        {
            i++;
        }
        printf("%c",str[i]);
        if(i<(strlen(str)-1))
            printf(".");
        for(int q=i+1; q<=strlen(str)-1; q++)
        {
            printf("%c",str[q]);
        }
        printf("e%d",i-1);
    }
    return 0;
}