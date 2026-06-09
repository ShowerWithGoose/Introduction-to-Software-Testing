#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
char a[10000];
void remove_a() //去掉空格和等于
{
    int lenth=strlen(a);
    int i = 0, j = 0;
    while (a[i] != '=')
    {
        if (a[i] != 32) // 32 is space
        {
            a[j] = a[i];
            j++;
        }
        i++;
    }
    while (j<lenth+2)
    {
        a[j] = '\0';
        j++;
    }
    strcat(a, "=");
    return;
}
int find_next(char **p)
{
    while (*(*p) != '+' && *(*p) != '-' && *(*p) != '*' && *(*p) != '/')
    {
        if (*(*p) == '=')
        {
            return -1;
        }
        *p += 1;
    }
    return 1;
}
int main()
{
    gets(a);
    remove_a();
    int ans = 0;
    int temp, current;
    bool if_pos = true;
    char *p = a;
    sscanf(a, "%d", &current);
    temp = current;
    while (find_next(&p) == 1)
    {
        if (*p == '*')
        {
            p += 1;
            sscanf(p, "%d", &current);
            temp *= current;
        }
        else if (*p == '/')
        {
            p += 1;
            sscanf(p, "%d", &current);
            temp /= current;
        }
        else if (*p == '+' || *p == '-')
        {
            if (if_pos)
                ans += temp;
            else
                ans -= temp;
            if (*p == '+')
                if_pos = true;
            else
            {
                if_pos = false;
            }
            p += 1;
            sscanf(p, "%d", &temp);
        }
    }
    if (if_pos)
        ans += temp;
    else
        ans -= temp;
    printf("%d", ans);
    return 0;
}
