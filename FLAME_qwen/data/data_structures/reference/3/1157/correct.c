#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 200000

int Max;

char buf[maxn];
int unable_print[maxn];

int pos_0, pos_X, pos_point;

int find(char l, char r, char *data)
{
    for(int i = 0; data[i] != '\0'; ++i)
        if(data[i] >= l && data[i] <= r)
            return i;
    return Max;
}

void plan1()
{
    printf("%c", buf[pos_X]);
    for(int i = pos_X + 1; i < Max; ++i)
    {
        if(i == pos_X + 1)  printf(".");
        printf("%c", buf[i]);
    }
    printf("e-%d", pos_X - pos_point);
    return ;
}

void plan2()
{
    printf("%c", buf[pos_X]);
    int next_pos_X = find('1', '9', buf + pos_X + 1);
    if(next_pos_X != Max)
    {
        printf(".");
        int once_X = 0;
        for(int i = Max -1 ; i > pos_X; --i)
        {
            if(buf[i] > '0') once_X = 1;
            unable_print[i] = once_X ^ 1;
        }
        for(int i = pos_X + 1; buf[i] != '\0'; ++i)
        {
            if(buf[i] != '.' && !unable_print[i])
                printf("%c", buf[i]);
        }
    }
    printf("e%d", pos_point-pos_X -1);
    return;
}

int main()
{
    scanf("%s", buf);
    Max = strlen(buf);
    pos_0 = find('0', '0', buf);
    pos_X = find('1', '9', buf);
    pos_point = find('.', '.', buf);
    if(pos_0 < pos_point && pos_point < pos_X)
        plan1();
    else if(pos_X < pos_point)
        plan2();
#ifdef DBG
    printf("\n");
#endif
    return 0;
}
