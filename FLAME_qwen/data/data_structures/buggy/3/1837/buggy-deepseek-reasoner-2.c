#include <stdio.h>
#include <string.h>
char in[101];
char *ptr;
int whe;
void fa(char in[])
{
    if (*(in) == '0')
    {
        int cnt = 1;
        in += 2;
        while (*(in++) == '0') @@ // The pointer is incremented even when the digit is non‑zero, causing it to overshoot the first significant digit; this is later compensated but leads to a fragile and unclear implementation.
            cnt += 1;
        in -= 1;
        printf("%c", *(in));
        in += 1;
        while (*(in) != '\0') @@ // Missing decimal point before the remaining digits when there is more than one non‑zero digit after the decimal. The output should be, e.g., "1.23e-3", not "123e-3".
            printf("%c", *(in++));
        printf("e-%d", cnt);
    }
    else
    {
        ptr = strchr(in, '.'); @@ // No check for NULL; if the input is an integer (no decimal point), dereferencing ptr later leads to undefined behavior.
        whe = ptr - in + 1; @@ // Uses ptr which may be NULL, causing a crash or garbage value.
        printf("%c.", *(in++)); @@ // Prints a decimal point even when the input might be an integer (i.e., no decimal point in the string). This branch is only reached for non‑zero first digits but still must handle the integer case.
        while (*(in) != '\0')
        {
            if (*(in) == '.')
                in += 1;
            else
                printf("%c", *(in++));
        }
        printf("e%d", whe - 2);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%s", in);
    fa(in);
    return 0;
}