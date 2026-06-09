#include <stdio.h>
#include <stdlib.h>

char pre, c, nxt;
#define MY_TYPE(cc) ((cc) >= 'a' && (cc) <= 'z' ? 1 : ((cc) >= 'A' && (cc) <= 'Z' ? 2 : ((cc) >= '0' && (cc) <= '9' ? 3 : -1)))

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    while((c = getchar()) != EOF)
    {
        if(!pre)
        {
            pre = c;
            continue;
        }
        if(c != '-')
        {
            putchar(pre);
            pre = c;
            continue;
        }
        nxt = getchar();
        if(nxt == EOF)
        {
            putchar(pre);
            pre = c;
            break;
        }
        if(pre < nxt && MY_TYPE(pre) == MY_TYPE(nxt))
        {
            for(char i = pre; i < nxt; i++)
                putchar(i);
            pre = nxt;
            continue;
        }
        putchar(pre);
        putchar(c);
        pre = nxt;
    }
    if(pre) putchar(pre);
    return 0;
}


