#include <stdio.h>

char str[100];

int main()
{
    gets(str);
    int dot = 0;
    int fullLength = strlen(str);
    if(fullLength==1)
    {
        printf("%ce0",str[0]);
        return 0;
    }
    int leftLength;
    int rightLength;
    if(strchr(str,'.')!=NULL)
    {
        dot = strchr(str,'.')-str;
        leftLength = dot;
        rightLength = fullLength - dot - 1;
    }
    else
    {
        leftLength = fullLength;
        rightLength = 0;
    }
    if(leftLength>1||str[0]!='0')
    {
        printf("%c.",str[0]);
        for(int i=1;i<fullLength;i++)
        {
            if(i==dot)continue;
            printf("%c",str[i]);
        }
        printf("e%d",leftLength-1);
    }
    else
    {
        int zero = 1;
        int i;
        for(i=dot+1;i<fullLength;i++)
        {
            if(str[i]!='0')break;
            zero++;
        }
        if(i==fullLength-1)
        {
            printf("%ce-%d",str[i],zero);
            return 0;
        }
        printf("%c.",str[i++]);
        for(;i<fullLength;i++)
        {
            printf("%c",str[i]);
        }
        printf("e-%d",zero);
    }
}

