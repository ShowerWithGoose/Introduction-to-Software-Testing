#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000005];
long ans, cur, reading;

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    scanf("%[^\n]", s);
    int len = strlen(s);
    cur = 1;
    int flag = 1;
    for(int i = 0; i < len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            reading = (reading << 1) + (reading << 3) + (s[i] - '0');
        }
        else if(s[i] == '+' || s[i] == '=')
        {
            if(flag) cur *= reading;
            else cur /= reading;
            ans += cur;
            cur = 1; flag = 1; reading = 0;
        }
        else if(s[i] == '-')
        {
            if(flag) cur *= reading;
            else cur /= reading;
            ans += cur;
            cur = -1; flag = 1; reading = 0;
        }
        else if(s[i] == '*')
        {
            if(flag) cur *= reading;
            else cur /= reading;
            flag = 1; reading = 0;
        }
        else if(s[i] == '/')
        {
            if(flag) cur *= reading;
            else cur /= reading;
            flag = 0; reading = 0;
        }
    }
    printf("%ld\n", ans);
    return 0;
}


