#include <stdio.h>
#include <string.h>
#include <math.h>

int num[50000];
char op[50000];
char str[10000000];

int isnum(char a)
{
    if (a >= '0' && a <= '9')
        return 1;
    return 0;
}
int numI, opI;

void read()
{
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!isnum(str[i]) && str[i] != ' ')
        {

            op[++opI] = str[i];
        }
        if (isnum(str[i]))
        {

            num[++numI] = abs(atoi(str + i));
            while (isnum(str[i]))
                i++;
            i--;
            continue;
        }
    }
    opI--;
}

int main()
{
    read();
    for (int i = 1; i <= opI; i++)
    {
        if (op[i] == '*' || op[i] == '/')
        {
            int j = i;
            while (op[i] == '*' || op[i] == '/')
            {

                if (op[i] == '*')
                {
                    num[j] *= num[i + 1];
                }
                if (op[i] == '/')
                {
                    num[j] /= num[i + 1];
                }
                i++;
            }
        }
    }
    for (int i = 1; i <= opI; i++)
    {

        if (op[i] == '+')
        {
            num[1] += num[i + 1];
        }
        if (op[i] == '-')
        {
            num[1] -= num[i + 1];
        }
    }
    printf("%d ", num[1]);

    return 0;
}
