#include <stdio.h>
#include <math.h>
#include <string.h>

char s[105];
int pos_dot = -1, pos_num = -1;

int main()
{
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i ++ )
    {
        if (s[i] == '.')
            pos_dot = i;
        else if (s[i] != '0' && pos_num == -1)
            pos_num = i;
    }
    if (pos_dot == -1)
    {
        for (int i = 0; i < strlen(s); i ++ )
            printf("%c", s[i]);
        return 0;
    }
    for (int i = pos_num; i < strlen(s); i ++ )
    {
        if (s[i] != '.')
            printf("%c", s[i]);
        if(i == pos_num && i != (strlen(s) - 1)) printf(".");
    }
    printf("e%d", (pos_num - pos_dot > 0) ? pos_dot - pos_num : pos_dot - pos_num - 1);
    return 0;
}


