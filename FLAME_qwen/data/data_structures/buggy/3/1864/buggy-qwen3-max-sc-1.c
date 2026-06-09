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
        printf("%c", '.'); // @@ [This prints a '.' even when there are no digits after the first non-zero digit, which may result in trailing decimal point or extra digits. Also, it prints the first non-zero digit twice: once before '.' and again inside the loop starting at j=ct.]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++) // @@ [Loop starts at 'ct', which is the index of the first non-zero digit, so it prints that digit again after already printing it above, causing duplication. Should start at j = ct + 1. Also, input from scanf doesn't contain '\n', so checking for '\n' is unnecessary.]
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
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity // @@ [If the input has no decimal point (though problem says it does), this loop runs past the string end, causing undefined behavior. Also, assumes decimal point exists after at least two digits.]
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++) // @@ [Again, '\n' check is unnecessary since scanf with %s doesn't include newline. Also, this loop prints all digits except skipping the decimal point, but includes digits after decimal without ensuring no trailing zeros (though problem states input has no trailing zeros). However, more critically, if the number has only one digit before '.', this branch won't be taken — but that's handled above. Main issue: logic assumes at least two digits before '.' due to condition in else-if.]
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