#include <stdio.h>
#include <string.h>

int is(char a)
{
    if (a >= 'A' && a <= 'Z')
        return 1;
    if (a >= 'a' && a <= 'z')
        return 2;
    if (a >= '0' && a <= '9')
        return 3;
    return 0;
}

char str[10000000];
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        
        printf("%c", str[i]);
        if (str[i + 1] == '-')
        {
            if (is(str[i]) == is(str[i + 2]) && str[i] < str[i + 2])
            {
                for (int j = 1; str[i] + j < str[i + 2]; j++)
                {
                    printf("%c", str[i] + j);
                }
                i++;
            }
            
        }
    }
    return 0;
}
