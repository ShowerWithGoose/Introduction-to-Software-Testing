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
        printf("%c", *(in)); // @@ The first significant digit is printed, but the decimal point required by scientific notation format (e.g., 9.123...) is missing here. It should print a dot after this digit if there are subsequent digits.
        in += 1;
        while (*(in) != '\0')
            printf("%c", *(in++));
        printf("e-%d", cnt);
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