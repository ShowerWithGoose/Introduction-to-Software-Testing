#include <stdio.h>
#include <string.h>
char sz1[200];
void F();
int first;
int main()
{
    gets(sz1);
    F();
    return 0;
}
void F()
{
    int len=strlen(sz1),place;
    for(int i=0;i<len;i++)
    {
        if(sz1[i]=='.')
        {
            place=i;
            break;
        }
    }
    for(int i=place;i<len;i++)
    {
        if(sz1[i+1]!='0')
        {
            first=i+place;
            break;
        }
    }
    if(sz1[0]!='0')
    {
        if(place>1)
        {
            printf("%c.",sz1[0]);
            for(int i=1;i<len;i++)
            {
                if(sz1[i]!='.') printf("%c",sz1[i]);
            }
            printf("e%d",place-1);
        }
        else
        {
            printf("%se0",sz1);
        }
    }
    else
    {
        printf("%c",sz1[first]);
        if(first!=len-1) printf(".%s",sz1+first+1);
        printf("e-%d",first-1);
    }
    return;
}


