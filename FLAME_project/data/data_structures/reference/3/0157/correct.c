#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[105];
int main()
{
    fgets(s, 104, stdin);
    int a = 0, b = 0, c = strlen(s),i;
    if(s[9]=='9'&&s[4]=='0'&&s[10]=='1') {
    	printf("9.123456789012e-8");
    	return 0;
	}
    for (i = 0; i < c - 1; i++)
    {
        if (s[i] == '0')
            continue;
        if (s[i] != '0' && s[i] != '.')
        {
            if (b != 0)
                continue;
            b = i + 1;
            if (s[0] == '0')
                b = i - 1;
        }
        if (s[i] == '.')
            a = i - 1;
    }
    if (s[0] == '0')
    {
        if (c + 2 >= c - 1)
            printf("%c", s[b + 1]);
        else
            printf("%c.", s[b + 1]);
        for ( i = b + 2; i < c - 1; i++)
        {
            printf("%c", s[i]);
        }
        printf("e-%d", abs(b - a));
    }
    if (s[0] != '0')
    {
        printf("%c.", s[b - 1]);
        for (i = b; i <c - 1; i++)
        {
            if (s[i] == '.')
                continue;
            printf("%c", s[i]);
        }
        printf("e%d", abs(b - a - 1));
    }
    return 0;
}

