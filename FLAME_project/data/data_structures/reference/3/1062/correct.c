#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *squeez(char s[], char c)
{
    int i, j;
    for (i = j = 0; i < strlen(s); i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
    return s;
}
void minus(char *ch)
{
    char ans[1000] = "";
    int i;
    for (i = 2; i < strlen(ch); i++)
    {
        if (ch[i] != '0' && i == strlen(ch) - 1)
        {
            sprintf(ans, "%c%se-%d", ch[i], &ch[i + 1], i - 1);
            puts(ans);
            break;
        }
        else if (ch[i] != '0' && i != strlen(ch) - 1)
        {
            sprintf(ans, "%c.%se-%d", ch[i], &ch[i + 1], i - 1);
            puts(ans);
            break;
        }
    }
}
void regular(char *ch)
{
    char ans[1000] = "";
    sprintf(ans, "%se0", &ch[0]);
    puts(ans);
}
void extra(char *ch, int i)
{
    char ans[1000] = "";
    squeez(ch, '.');
    sprintf(ans, "%c.%se%d", ch[0], &ch[1], i - 1);
    puts(ans);
}
int main(void)
{
    char ch_t[1000];
    char *ch = ch_t;
    int i;
    gets(ch);
    i = strchr(ch, '.') - &ch[0];
    if (i == 1 && ch[0] == '0')
    {
        minus(ch);
    }
    else if (i == 1 && ch[0] != '0')
    {
        regular(ch);
    }
    else
    {
        extra(ch, i);
    }
    return 0;
}
