#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    char start, next1, next2;
    int num1, num2, num3;
    start= '+';num1 = 0;
    while (start != '=')
    {
        scanf("%d %c", &num2, &next1);
        while (next1 == '*' || next1 == '/')
        {
            scanf("%d %c", &num3, &next2);
            if (next1 == '*') num2 *= num3;
            else num2 /= num3;
            next1 = next2;
        }
        if (start== '+') num1 += num2;
        else if (start == '-')num1 -= num2;
        start = next1;
    }
    printf("%d", num1);
    return 0;
}


