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
        printf("e-%d", cnt); @@ [When the input is "0.x" where all digits after decimal are zero (which shouldn't happen per problem constraints, but code doesn't handle end-of-string properly), or when there's only one non-zero digit after leading zeros, it fails to output decimal point as required by scientific notation format. Also, it doesn't print a decimal point even when there are more digits after the first non-zero digit, violating the output specification that requires either one digit (integer) or one digit before and at least one after decimal point.]
    }
    else
    {
        ptr = strchr(in, '.');
        whe = ptr - in + 1; @@ [If input has no decimal point (e.g., "123"), strchr returns NULL, leading to undefined behavior when calculating whe and later dereferencing ptr. The program assumes a decimal point always exists for non-zero-leading numbers, which contradicts the problem statement allowing integers as input.]
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