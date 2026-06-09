#include <stdio.h>
int main()
{
    int a1,a2,a3;
    char b1,b2,b3;
    int num[3];
    char symbol[3];
    num[0] = 0;
    symbol[0] = '+';
    while(1)
    {
        scanf("%d %c", &num[1], &symbol[1]);
        while (symbol[1] == '*' || symbol[1] == '/')
        {
            scanf("%d %c", &num[2], &symbol[2]);
            if (symbol[1] == '*') {num[1] = num[1] * num[2];}
            else {num[1] = num[1] / num[2];}
            symbol[1] = symbol[2];
        }
        if (symbol[0] == '+') {num[0] = num[0] + num[1];}
        else if(symbol[0] == '-') {num[0] = num[0] - num[1];}
        symbol[0] = symbol[1];
        if (symbol[0] == '=')
        {
            printf("%d\n", num[0]);
            break;
        }
        
    }
    return 0;
}


