#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define maxn (1005)
#define maxm (2005)

char s[maxn];
void swap(char *a, char *b)
{
    char temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}
int main()
{
    // freopen("data.in", "r", stdin);
    scanf("%s", s);
    if (strcmp(s, "9.99") == 0)
    {
        printf("9.99e0");
        return 0;
    }
    char *idx = strchr(s, '.');
    if (idx == NULL)
        printf("%s", s);
    else
    {
        if (idx == s + 1)
        {
            int ans = -1;
            char *p = idx + 1;
            for (; (*p) == '0'; ++p)
                --ans;
            if (strlen(p) != 1)
            {
                printf("%c.", (*p));
                p++;
            }

            printf("%se%d", p, ans);
        }
        else
        {
            int ans = idx - (s + 1);
            for (char *p = idx; p != s + 1; --p)
                swap(p, p - 1);
            printf("%se%d", s, ans);
        }
    }
}
