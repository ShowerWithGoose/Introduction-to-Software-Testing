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
        printf("%c", *(in)); // @@ [缺少小数点：应输出一位整数后加小数点，例如改为 printf("%c.", *(in));]
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