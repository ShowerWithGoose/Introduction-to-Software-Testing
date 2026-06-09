#include <stdio.h>
#include <string.h>

int main()
{
    char a[10000] = "";
    int cnt;
    char *b;
    char *flag;
    gets(a);
    b = strchr(a,'-');
    while(b != NULL)
    {
        if(*(b-1)>='0'&&*(b-1)<='9')
        {
            if(*(b+1) >= '0' && *(b+1) <= '9' && *(b+1)>*(b-1))
            {
                cnt = *(b + 1) - *(b - 1) - 1;
                for(flag = &a[strlen(a) - 1]; flag > b;flag --)
                {
                    *(flag + cnt - 1) = *flag;
                }
                flag = b;
                for(int i = 0; i < cnt; i++)
                {
                    *(flag+i) = *(b-1) + i + 1;
                }
            }
            else
            {
                *b = '+';
            }
        }
        else if(*(b-1)>='a'&&*(b-1)<='z')
        {
            if(*(b+1) >= 'a' && *(b+1) <= 'z' && *(b+1)>*(b-1))
            {
                cnt = *(b + 1) - *(b - 1) - 1;
                for(flag = &a[strlen(a) - 1]; flag > b;flag --)
                {
                    *(flag + cnt - 1) = *flag;
                }
                flag = b;
                for(int i = 0; i < cnt; i++)
                {
                    *(flag+i) = *(b-1) + i + 1;
                }
            }
            else
            {
                *b = '+';
            }
        }
        else if(*(b-1)>='A'&&*(b-1)<='Z')
        {
            if(*(b+1) >= 'A' && *(b+1) <= 'Z' && *(b+1)>*(b-1))
            {
                cnt = *(b + 1) - *(b - 1) - 1;
                for(flag = &a[strlen(a) - 1]; flag > b;flag --)
                {
                    *(flag + cnt - 1) = *flag;
                }
                flag = b;
                for(int i = 0; i < cnt; i++)
                {
                    *(flag+i) = *(b-1) + i + 1;
                }
            }
            else
            {
                *b = '+';
            }
        }
        b = strchr(a,'-');
    }
    for(int i = 0; i < strlen(a); i++)
    {
        if(a[i] == '+')
        {
            printf("%c",'-');
        }
        else
        {
            printf("%c",a[i]);
        }
    }
    system("pause");
 
 return 0;

 } 
 


