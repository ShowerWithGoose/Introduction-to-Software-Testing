#include<stdio.h>
#include<string.h>
void f(char a, char b); // Declaration ok

int main()
{
    char str[1024] = {0};
    int i = 0;
    fgets(str,1024,stdin); // ok, but fgets includes newline; may cause extra newline output
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-')
        {
            if (str[i - 1] <= 'z' && str[i - 1] >= 'a' && str[i + 1] <= 'z' && str[i + 1] >= 'a' && str[i - 1] < str[i + 1]) // @@ potential out-of-bounds when i==0 or i==last index; undefined behavior
            {
                f(str[i - 1], str[i + 1]);
            }
            else if (str[i - 1] <= 'Z' && str[i - 1] >= 'A' && str[i + 1] <= 'Z' && str[i + 1] >= 'A' && str[i - 1] < str[i + 1]) // @@ same out-of-bounds issue
            {
                f(str[i - 1], str[i + 1]);
            }
            else if (str[i - 1] <= 'Z' && str[i - 1] >= 'A' && str[i + 1] <= 'Z' && str[i + 1] >= 'A' && str[i - 1] < str[i + 1]) // @@ logic error: should check digits '0'-'9', not repeated uppercase; also out-of-bounds
            {
                f(str[i - 1], str[i + 1]);
            }
            else
            {
                printf("%c", str[i]);
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
        printf("%c", n);
    }
}