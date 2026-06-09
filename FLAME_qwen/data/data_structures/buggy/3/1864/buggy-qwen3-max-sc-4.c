#include <stdio.h>
int main()
{
    char in[200];
    scanf("%s", in);
    if (in[0] == '0' && in[1] == '.')
    {
        //<1
        int ct;
        for (ct = 2; in[ct] == '0'; ct++)
            ; // num of zeros+2
        printf("%c", in[ct]);
        printf("%c", '.'); // @@ [This prints a '.' even when there are no digits after the first non-zero digit, which may result in trailing decimal point or extra dot. Also, it prints the first non-zero digit twice: once before and once inside the loop below.]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++) // @@ [Loop starts at 'ct', which is the index of the first non-zero digit, so this prints that digit again, causing duplication. Should start at ct+1. Also, input from scanf doesn't contain '\n', so checking for '\n' is unnecessary.]
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] >= '0' && in[1] <= '9')
    {
        int ct2;
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++) // @@ [Again, checking for '\n' is unnecessary since scanf with %s doesn't include newline. Also, this loop prints all digits except skipping the decimal point, but includes digits after the decimal correctly. However, if the number has no decimal point (which shouldn't happen per problem), this loop would run past the string. But more critically, the logic assumes there is always a decimal point, which is given by problem, but the loop condition is redundant.]
        {
            if (q == ct2)
                continue;
            else
            {
                printf("%c", in[q]);
            }
        }
        printf("e%d", ct2-1);
    }
}