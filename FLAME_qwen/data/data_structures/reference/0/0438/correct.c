#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
enum Type {digit, upperAlpha, lowerAlpha, none};

enum Type getType(char ch)
{
    if (isdigit(ch))
    {
        return digit;
    }
    else if (isupper(ch))
    {
        return upperAlpha;
    }
    else if (islower(ch))
    {
        return lowerAlpha;
    }
    else
    {
        return none;
    }
    
    
    
    
}

int main()
{
    char str[50];
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-' && getType(str[i-1]) == getType(str[i+1]) && getType(str[i-1]) != none && str[i-1] < str[i+1])
        {
            for (char ch = str[i-1]+1; ch < str[i+1]; ch++)
            {
                putchar(ch);
            }
        }
        else
        {
            putchar(str[i]);
        }
    }
    
    // getchar();

    return 0;
}
