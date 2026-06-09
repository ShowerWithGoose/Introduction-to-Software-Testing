#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100];
    int i,m;
    gets(ch);
    if(ch[1]=='.'&&ch[0]-'0'>=1)
    {
        printf("%se0",ch);
    }
    else if(ch[1]=='.'&&ch[0]=='0')
    {
        for(i=2; i<strlen(ch); i++)
        {
            if(ch[i]-'0'>=1)
            {
                m=ch[i]-'0';
                if(i==strlen(ch)-1)
                {
                    printf("%d",m);
                }
                else
                {
                    printf("%d.",m);
                }

                break;
            }
        }
        //printf("%d",i);
        for(int j=i+1; j<strlen(ch); j++)
        {
            printf("%d",ch[j]-'0');
        }
        printf("e-%d",i-1);
    }
    else
    {
        for(i=0; i<strlen(ch); i++)
        {
            if(ch[i]=='.')
                break;
        }
        printf("%c.",ch[0]);
        for(int j=1; j<strlen(ch); j++)
        {
            if(ch[j]=='.')
            {
                continue;
            }
            printf("%c",ch[j]);

        }
        printf("e%d",i-1);

    }
    return 0;


}

