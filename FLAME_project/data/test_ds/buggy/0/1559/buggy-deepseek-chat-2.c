#include<stdio.h>
#include<string.h>
void f(char a, char b);

int main()
{
    char str[1024] = {0};
    int i = 0;
    fgets(str,1024,stdin);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-')
        {
            if (str[i - 1] <= 'z' && str[i - 1] >= 'a' && str[i + 1] <= 'z' && str[i + 1] >= 'a' && str[i - 1] < str[i + 1])
            {
                f(str[i - 1], str[i + 1]); // @@ The function f only prints the characters between a and b, but does not print a and b themselves, nor does it handle the case where the expansion symbol '-' should be replaced. The program should output the full expanded range including the start and end characters, and the '-' should not be printed.
            }
            else if (str[i - 1] <= 'Z' && str[i - 1] >= 'A' && str[i + 1] <= 'Z' && str[i + 1] >= 'A' && str[i - 1] < str[i + 1])
            {
                f(str[i - 1], str[i + 1]); // @@ Same issue as above: missing output of start and end characters, and the '-' is still printed later.
            }
            else if (str[i - 1] <= 'Z' && str[i - 1] >= 'A' && str[i + 1] <= 'Z' && str[i + 1] >= 'A' && str[i - 1] < str[i + 1]) // @@ This condition is identical to the previous else if, so it is a duplicate and will never be reached. It should check for digits [0-9] instead.
            {
                f(str[i - 1], str[i + 1]); // @@ Same issue as above.
            }
            else
            {
                printf("%c", str[i]); // @@ When the expansion condition is not met, the '-' is printed, but the characters before and after it are also printed separately in the else branch of the outer loop, which is correct. However, when expansion does occur, the '-' should not be printed, but here it is still printed because the code does not skip printing the '-' in the expansion cases.
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}

void f(char a, char b)
{
    char n;
    for (n = a + 1; n < b; n++)
    {
        printf("%c", n); // @@ This function only prints the intermediate characters, missing the start character a and end character b. It should print a, then the intermediate characters, then b.
    }
}