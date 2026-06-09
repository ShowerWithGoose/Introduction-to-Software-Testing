#include <stdio.h>
#include <stdlib.h>

char s[1000];
int pre, cur, cnt;

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    scanf("%s", s);
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == '.') break;
        pre++;
    }
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == '0') cur++;
        if(s[i] > '0' && s[i] <= '9')
        {
            cur++;
            break;
        }
    }
    for(int i = 0; s[i]; i++)
    {
        if(s[i] >= '0' && s[i] <= '9') cnt++;
        else continue;
        if(cnt == cur + 1)
            putchar('.');
        if(cnt >= cur)
            putchar(s[i]);
    }
    printf("e%d\n", pre - cur);
    return 0;
}
