#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef long long ll;
#define eps 1e-8

int main()
{
    char s[105],ss[105];
    gets(s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '-')
        {
            if (islower(s[i - 1]) && islower(s[i + 1]) && s[i - 1] < s[i + 1])
            {
                for (int len = s[i - 1] + 1; len < s[i + 1]; len++)
                {
                    printf("%c", len);
                }
            }
            else if (isdigit(s[i - 1]) && isdigit(s[i + 1]) && s[i - 1] < s[i + 1])
            {
                for (int len = s[i - 1] + 1; len < s[i + 1]; len++)
                {
                    printf("%c", len);

                }
            }
            else if (isupper(s[i - 1]) && isupper(s[i + 1]) && s[i - 1] < s[i + 1])
            {
                for (int len = s[i - 1] + 1; len < s[i + 1]; len++)
                {
                    printf("%c", len);
                }
            }
            else {
                printf("%c", s[i]);
            }
        }
        else {
            printf("%c", s[i]);
        }

    }
    return 0;
}




