#include<stdio.h>
#include<ctype.h>
int main()
{
    char front,now=0;
    while(scanf("%c",&now)!=EOF)
    {
        if(now!='-')
        {
            if(isprint(front))
            printf("%c",front);
            front=now;
        }
        else
        {
            scanf("%c",&now);
            if(((isdigit(now)&&isdigit(front))||(islower(now)&&islower(front))||(isupper(now)&&isupper(front)))&&front<=now)
            {
                while(front<now)
                {
                    printf("%c",front);
                    front++;
                }
            }
            else
            {
                printf("%c-",front);
                front=now;
            }
        }
    }
    printf("%c",now);
    return 0;
}

