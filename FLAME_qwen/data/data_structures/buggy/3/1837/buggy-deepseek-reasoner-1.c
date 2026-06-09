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
        while (*(in++) == '0')
            cnt += 1;
        in -= 1;
        printf("%c", *(in));
        in += 1; // @@ This line moves the pointer without checking if there are more digits; a decimal point should be printed before any remaining digits if they exist.
        while (*(in) != '\0') // @@ This loop prints all remaining digits without inserting a decimal point after the first non-zero digit, which is required when there are additional digits.
            printf("%c", *(in++)); // @@ This prints digits consecutively without a dot; the output base incorrectly omits the decimal point.
        printf("e-%d", cnt);
    }
    else
    {
        ptr = strchr(in, '.'); // @@ If the input is an integer (no '.'), strchr returns NULL, leading to undefined behavior in the next line.
        whe = ptr - in + 1; // @@ Pointer subtraction with NULL is undefined; integer inputs are not handled.
        printf("%c.", *(in++));
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