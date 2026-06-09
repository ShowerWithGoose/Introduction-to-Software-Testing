#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char ch[1000];
    int i,j;
    int a;
    scanf("%s",ch);
    for(i=0,j=0;ch[i]!='\0';i++)
    {
        if(ch[i]!='-')
        {
            printf("%c",ch[i]);
        }
        else if(i==0||ch[i+1]=='\0')
        {
            printf("%c",ch[i]);
        }
        else if((ch[i-1]<='z'&&ch[i-1]>='a')&&(ch[i+1]<='z'&&ch[i+1]>='a')&&ch[i-1]<ch[i+1])
        {
            for(a=1;a<=ch[i+1]-ch[i-1]-1;a++)
            {
                printf("%c",ch[i-1]+a);
            }
        }
        else if((ch[i-1]<='Z'&&ch[i-1]>='A')&&(ch[i+1]<='Z'&&ch[i+1]>='A')&&ch[i-1]<ch[i+1])
        {
            for(a=1;a<=ch[i+1]-ch[i-1]-1;a++)
            {
                printf("%c",ch[i-1]+a);
            }
        }
        else if((ch[i-1]<='9'&&ch[i-1]>='0')&&(ch[i+1]<='9'&&ch[i+1]>='0')&&ch[i-1]<ch[i+1])
        {
            for(a=1;a<=ch[i+1]-ch[i-1]-1;a++)
            {
                printf("%c",ch[i-1]+a);
            }
        }
        else
        printf("%c",ch[i]);
    }
    return 0;
}

