#include <stdio.h>
#include <string.h>
int vst[1000] = {0};
void chuli(char a, char b, int k)
{
    for (int i = a; i <= b; ++i)
        if (vst[k] && i == a)
            continue;
        else
            printf("%c", i);
}
int main()
{
    char s[1000];
    // int vst[1000]={0};
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        if (s[i + 1] == '-' && i != len - 1)
        {
            if (s[i] >= 'a' && s[i] <= 'z' && s[i + 2] >= 'a' && s[i + 2] <= 'z')
                chuli(s[i], s[i + 2], i);
            else if (s[i] >= 'A' && s[i] <= 'Z' && s[i + 2] >= 'A' && s[i + 2] <= 'Z')
                chuli(s[i], s[i + 2], i);
            else if (s[i] >= '0' && s[i] <= '9' && s[i + 2] >= '0' && s[i + 2] <= '9')
                chuli(s[i], s[i + 2], i);
            else
                printf("%c%c%c", s[i], s[i + 1], s[i + 2]);
            vst[i] = 1, vst[i + 1] = 1, vst[i + 2] = 1;
        }
        else if (!vst[i])
            printf("%c", s[i]), vst[i] = 1;
    }
    return 0;
}


