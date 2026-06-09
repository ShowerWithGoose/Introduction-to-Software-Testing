#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char s[1000];
    gets(s);
    int mark,z,x;
    int len=strlen(s);
    for(int i=1;i<len;i++)
    {
        if(s[i]=='.')
        {
            mark=i;
            break;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(s[i]!='0'&&s[i]!='.')
        {
            z=i;
            break;
        }
    }
    if(z<mark)
    {
        printf("%c.",s[z]);
        for(int i=z+1;i<len;i++)
        {
            if(i!=mark)
            {
                printf("%c",s[i]);
            }
        }
        printf("e%d",mark-z-1);
    }
    if(z>mark)
    {
        printf("%c",s[z]);
        if(z+1!=len)
        {
            printf(".");
        }
        for(int i=z+1;i<len;i++)
        {
            if(i!=mark)
            {
                printf("%c",s[i]);
            }
        }
        printf("e%d",mark-z);
    }
    system("pause");
    return 0;
}


