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
        in += 1;
        while (*(in) != '\0')
            printf("%c", *(in++));
        printf("e-%d", cnt); // @@ [The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at position 8 after the decimal, so exponent should be -8, but the code counts leading zeros starting from position 2 (after "0."), and increments cnt for each zero including the one before '9', resulting in cnt=8, but it should represent -8 correctly. However, more critically, the output format is wrong: it prints "9123456789012e-8" instead of "9.123456789012e-8" because it fails to insert a decimal point after the first significant digit.]
    }
    else
    {
        ptr = strchr(in, '.');
        whe = ptr - in + 1;
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