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
        in += 2; // @@ [If the input is "0.0", this skips to position 2, but if the string length is <=2 (e.g., "0." or "0.0" with no further digits), then in may point beyond valid data, leading to undefined behavior when dereferencing]
        while (*(in++) == '0') // @@ [This loop increments in before checking, so it may read past the null terminator if all remaining characters are zeros or if the string ends early]
            cnt += 1;
        in -= 1; // @@ [Adjustment may not correctly point to the first non-zero digit if the loop exited due to reaching '\0']
        printf("%c", *(in)); // @@ [Dereferencing in here may access invalid memory if the input has no non-zero digits after the decimal point (e.g., "0.000")]
        in += 1;
        while (*(in) != '\0')
            printf("%c", *(in++));
        printf("e-%d", cnt);
    }
    else
    {
        ptr = strchr(in, '.'); // @@ [If there's no '.' in the input (e.g., an integer like "123"), strchr returns NULL, and the following subtraction leads to undefined behavior]
        whe = ptr - in + 1; // @@ [If ptr is NULL (no '.' found), this causes undefined behavior due to invalid pointer arithmetic]
        printf("%c.", *(in++));
        while (*(in) != '\0')
        {
            if (*(in) == '.')
                in += 1;
            else
                printf("%c", *(in++));
        }
        printf("e%d", whe - 2); // @@ [If ptr was NULL, whe is garbage, leading to incorrect exponent output]
    }
}
int main(int argc, char const *argv[])
{
    scanf("%s", in);
    fa(in);
    return 0;
}