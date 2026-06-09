#include <stdio.h>
char getoperator()
{
    char c;
    while(c = getchar())
        if(c == '+' || c == '-' || c =='*' || c == '/' || c == '=')
            break;
    return c;
}
int main()
{
    int ans = 0, ch = 1;
    char c = '+';
    while(1)
    {
        int x;
        scanf("%d", &x);
        while(1)
        {
            c = getoperator();
            if(c == '+' || c == '-' || c == '=')
                break;
            if(c == '*' || c == '/')
            {
                int y;
                scanf("%d", &y);
                if(c == '*')
                    x = x * y;
                else
                    x = x / y;
            }
        }
        ans += ch * x;
        if(c == '=')
            break;
        if(c == '+')
            ch = 1;
        else
            ch = -1;
    }
    printf("%d\n", ans);
	return 0;
}

