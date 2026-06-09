#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char buf[100000];

int main()
{
    scanf("%s", buf);
    for(int i = 0; buf[i] != '\0'; ++i)
    {
        if(buf[i] != '-')
            printf("%c", buf[i]);
        if(buf[i] == '-')
            if(i > 0 && ((isdigit(buf[i-1]) && isdigit(buf[i+1]))||(islower(buf[i-1])&&islower(buf[i+1]))||(isupper(buf[i-1])&&isupper(buf[i+1]))))
                for(char j = buf[i-1] + 1; j <= buf[i+1] - 1; ++j)
                    printf("%c", j);
            else
                printf("-");
    }
    return 0;
}
