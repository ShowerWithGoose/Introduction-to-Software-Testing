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
        printf("e-%d", cnt); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", cnt becomes 8, but the expected exponent is -8. However, the output shows "e-8" which is correct in this case, but the base is printed as "9123456789012" instead of "9.123456789012". The error is that the decimal point is not inserted after the first digit. The code prints the first digit and then all remaining digits without inserting a '.' between the first and second digits.
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