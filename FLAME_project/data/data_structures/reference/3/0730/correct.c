#include <stdio.h>
char c[105];
int i;
int main()
{
    scanf("%s",c);
    if(c[1]=='.')
    {
        if(c[0]=='0')
        {
            for(i=1;c[i+1]=='0';i++)
            ;
            if(c[i+2]=='\0')
            printf("%ce-%d",c[i+1],i);
            else
            printf("%c.%se-%d",c[i+1],&c[i+2],i);
        }
        else
        printf("%se0",c);
    }
    else
    {
        for(i=2;c[i]!='.';i++)
        ;
        c[i]='\0';
        printf("%c.%s%se%d",c[0],&c[1],&c[i+1],i-1);
    }
    return 0;
}



