// 1.遍历，找到- i++和i--的对应比较
// 2.存放在新的数组中

#include<stdio.h>
#include<string.h>

int is_indentify(char* s)
{
    if(*(s-1) >='a' && *(s+1) <= 'z')
    {
        return 1;
    }

    if(*(s-1) >='A' && *(s+1) <= 'Z')
    {
        return 1;
    }

    if(*(s-1) >='0' && *(s+1) <= '9')
    {
        return 1;
    }

    return 0;
}

int main()
{
    char s[500];
    char c[500];
    scanf("%s",s);

    int j = 0;
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        if(i == len - 1)
        {
            c[j++]=s[i];
            break;
        }

        if(s[i] != '-')
        {
        c[j++] = s[i];
        }

        else
        {
        if(is_indentify(&s[i]))
        {
            char tmp = s[i-1];
            while(tmp >= s[i-1] && tmp < s[i+1])
            {   
                tmp++;
                c[j++] = tmp;
            }
            i++;
        }

        else
        {
            c[j++] = s[i];
        }
        }
    }

    c[j] = '\0';
    printf("%s\n",c);
    return 0;
}


