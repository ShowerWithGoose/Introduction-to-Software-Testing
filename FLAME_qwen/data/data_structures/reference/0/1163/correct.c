#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isSame(char, char); 
int main()
{
    char a = 0, b = 0, c = 0; 
    while (a != EOF)
    {
        a = getchar();
        if (b == '-')
        {
            if (isSame(a, c) && a - c > 0)
            {
                int i;
                for (i = 1; i < a - c; i ++)
                {
                    printf("%c", c + i);
                }
            }
            else
            {
                putchar('-');
            }
            
        }
        if (a != '-' && a != EOF)
        {
            printf("%c", a);
        }
        
        c = b;
        b = a;
    }
    
    return 0;
}

int isSame(char a, char b)
{
    if (a - 'a' >= 0 && a - 'a' <= 25)
    {
        if (b - 'a' >= 0 && b - 'a' <= 25 )
        {
            return 1;
        }
    }
    else if (a - '0' >= 0 && a - '0' <= 9)
    {
        if (b - '0' >= 0 && b - '0' <= 9)
        {
            return 1;
        }
    }
    else if (a - 'A' >= 0 && a - 'A' <= 25)
    {
        if (b - 'A' >= 0 && b - 'A' <= 25)
        {
            return 1;
        }
    }
    return 0;
}
