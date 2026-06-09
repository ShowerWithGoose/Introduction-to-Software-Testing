//3. 小数形式与科学计数法转换（简）
//case 2: 123.456 -> 1.23456e2
//01.10 error
#include <stdio.h>
#include <string.h>

#define SIZE 105

int main()
{
    char s[SIZE];
    int len;      //length of number (from 0 to length - 1)
    int dot_pos;  //dot position
    int non_zero; //first non zero number position
    int i;
    gets(s);
    len = strlen(s) - 1;
    if (s[0] == '0')
    {
        if (s[2] == '0')
        {
            for (i = 3; i <= len; i++)
            {
                if (s[i] != '0')
                {
                    non_zero = i;
                    break;
                }
            }
            //0.002 -> 2e-3
            if (non_zero == len - 1)
            {
                putchar(s[len]);
                printf("e-%d", non_zero - dot_pos - 1);
            }
            //0.00123 -> 1.23e-3
            else
            {
                printf("%c.", s[non_zero]);
                for (i = non_zero + 1; i <= len; i++)
                {
                    putchar(s[i]);
                }
                printf("e-%d", non_zero - dot_pos - 1);
            }
        }
        //0.9 -> 9e1
        else if (len == 2)
        {
            printf("%ce-1", s[2]);
        }
        //0.123 - > 0.123e0
        else
        {
            for (i = 0; i <= len; i++)
            {
                putchar(s[i]);
            }
            printf("e0");
        }
    }
    else
    {
        for (i = 0; i <= len; i++)
        {
            if (s[i] == '.')
            {
                dot_pos = i;
                break;
            }
        }
        //1.23456 -> 1.23456e0
        if (dot_pos == 1)
        {
            for (i = 0; i <= len; i++)
            {
                putchar(s[i]);
            }
            printf("e0");
        }
        //123.456 -> 1.23456e2
        else
        {
            printf("%c.", s[0]);
            for (i = 1; i <= dot_pos - 1; i++)
            {
                putchar(s[i]);
            }
            for (i = dot_pos + 1; i <= len; i++)
            {
                putchar(s[i]);
            }
            printf("e%d", dot_pos - 1);
        }
    }
    return 0;
}
