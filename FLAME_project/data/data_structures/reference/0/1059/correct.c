#include <stdio.h>
#include <stdlib.h>

char pre, cur, nxt;
#define MY_TYPE(cc) ((cc) >= 'a' && (cc) <= 'z' ? 1 : ((cc) >= 'A' && (cc) <= 'Z' ? 2 : ((cc) >= '0' && (cc) <= '9' ? 3 : -1)))

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    while((cur = getchar()) != EOF)
    {
        if(!pre)
        {
            pre = cur;
            continue;
        }
        if(cur != '-')
        {
            putchar(pre);
            pre = cur;
            continue;
        }
        nxt = getchar();
        if(nxt == EOF)
        {
            putchar(pre);
            pre = cur;
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
        putchar(cur);
        pre = nxt;
    }
    if(pre) putchar(pre);
    return 0;
}


