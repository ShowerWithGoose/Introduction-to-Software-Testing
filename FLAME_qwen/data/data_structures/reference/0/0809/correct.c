#include<stdio.h>
#include<string.h>
char str[1005];
int main()
{
    gets(str);
    char a;
    int lenth=strlen(str);
    for(int i=0;i<lenth;i++)
    {
        if(('-'==str[i])&&(i!=0))
        {
            if((str[i-1]>='A')&&(str[i-1]<='Z')&&(str[i+1]>='A')&&(str[i+1]<='Z')&&(str[i-1]<str[i+1]))
            {
                for(a=str[i-1]+1;a<str[i+1];a++)
                {
                    printf("%c",a);
                }
            }
            else if((str[i-1]>='a')&&(str[i-1]<='z')&&(str[i+1]>='a')&&(str[i+1]<='z')&&(str[i-1]<str[i+1]))
            {
                for(a=str[i-1]+1;a<str[i+1];a++)
                {
                    printf("%c",a);
                }
            }
            else if((str[i-1]>='0')&&(str[i-1]<='9')&&(str[i+1]>='0')&&(str[i+1]<='9')&&(str[i-1]<str[i+1]))
            {
                for(a=str[i-1]+1;a<str[i+1];a++)
                {
                    printf("%c",a);
                }
            }
            else
            {
                printf("%c",str[i]);
            }
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}

