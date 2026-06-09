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
        printf("e-%d", cnt); @@ [When the input is "0.0...", after skipping zeros, if there are no more digits (i.e., all remaining are zeros), this code will print nothing after the first non-zero digit and may access beyond the string or produce incorrect output. Also, it fails to handle the case where only one significant digit remains (should not print decimal point). Moreover, cnt starts at 1 but should start at 2 for "0.0...x" since exponent is -(position after decimal).]
    }
    else
    {
        ptr = strchr(in, '.');
        whe = ptr - in + 1; @@ [If there's no decimal point, strchr returns NULL, leading to undefined behavior when computing whe. The problem states input always has digits before and after decimal point, but code doesn't validate this assumption robustly. However, per problem description, input always contains a decimal point, so this might not be the main issue. But more critically: whe = ptr - in gives index of '.', so whe - 2 as exponent is wrong. For example, "123.45": '.' is at index 3, whe = 4, exponent = 2 → correct. But logic is convoluted and error-prone. However, the real bug is in the '0' branch.]
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