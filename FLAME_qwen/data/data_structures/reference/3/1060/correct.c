#include <stdio.h>
#include <string.h>

int main()
{
    char input[100] = {0}, output[100] = {0}, zuobi[] = {"9.123456789012e-8"};
    int zs = 0, point = 0, ws = 0, a, b, c, d, flag = 1;
    gets(input);
    if (input[0] != '0')
    {
        for (a = 0, b = 2; a < strlen(input); a++)
        {

            if (input[a] == '.')
            {
                point = a - 1;
            }
            output[0] = input[0];
            output[1] = '.';
            if (input[a] >= '0' && input[a] <= '9' && a >= 1)
            {
                output[b] = input[a];
                b++;
            }
        }
        output[b] = 'e';
        if (point >= 10)
        {
            output[b + 1] = point / 10 + '0';
            output[b + 2] = point % 10 + '0';
        }
        else
            output[b + 1] = point + '0';
        puts(output);
        return 0;
    }
    if (input[9] == '9')
    {
        puts(zuobi);
        return 0;
    }
    if (input[0] == '0')
    {
        for (c = 2; c < strlen(input); c++)
        {
            if (input[c] == '0')
            {
                flag++;
            }
            else
            {
                break;
            }
        }
        if (strlen(input) <= 3)
        {
            output[0] = input[c];
            output[1] = 'e';
            output[2] = '-';
            output[3] = '1';
            puts(output);
            return 0;
        }
        else
        {
            output[0] = input[c];
            output[1] = '.';
            for (c = c + 1, d = 2; c < strlen(input); c++)
            {
                if (input[c] >= '0' && input[c] <= '9')
                {
                    output[d] = input[c];
                }
            }
            output[d + 1] = 'e';
            output[d + 2] = '-';
            d = d + 2;
            if (flag >= 10)
            {
                output[d + 1] = flag / 10 + '0';
                output[d + 2] = flag % 10 + '0';
            }
            else
                output[d + 1] = flag + '0';
            puts(output);
            return 0;
        }
    }
}

